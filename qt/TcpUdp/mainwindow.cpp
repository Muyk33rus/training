#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/highgui.hpp>
#include <opencv/cv.h>
#include <QImage>
#include <QImageWriter>
#include <QImageReader>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMainWindow::setFixedSize(370,640);
    UdpSocket  =  new QUdpSocket();
    TCPserver  =  new QTcpServer();
    TcpSocket   =  new QTcpSocket(this);
    ui->setupUi(this);

    ui->logList->setReadOnly(true);
    pTimer = new QTimer(this);
    ui->TCP->setChecked(true);
    ui->send->setCheckable(true);
    ui->send->setChecked(false);
    ui->receive->setCheckable(true);
    ui->receive->setChecked(false);
    ui->UDP->setDisabled(true);
    connect(ui->receive,SIGNAL(clicked()),this,SLOT(receivingMessage()));
    connect(ui->send,   SIGNAL(clicked()),this,SLOT(timeSend())     );
    connect(ui->UDP,    SIGNAL(clicked()),this,SLOT(clickedUDP())   );
    connect(ui->TCP,    SIGNAL(clicked()),this,SLOT(clickedTCP())   );
    connect(pTimer,     SIGNAL(timeout()),this,SLOT(sendMessage())  );

}

MainWindow::~MainWindow()
{
    UdpSocket->abort();
    delete ui;
    delete pTimer;
    delete UdpSocket;
}

void MainWindow::sendToTcpClient(QTcpSocket *pSocket, QByteArray &arrBlock)
{
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out<<ui->message->text();
    pSocket->write(arrBlock);
}

void MainWindow::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(TcpSocket->errorString())
                    );
    ui->logList->append(strError);
}



void MainWindow::sendMessage()
{
    QBuffer buffer;
    QByteArray baDatagram;
    QDataStream out(&baDatagram, QIODevice::WriteOnly);

    IplImage* img = cvQueryFrame( capture );
    if (!img)
       return;
    QImage imgDst((uchar*)img->imageDataOrigin , img->width , img->height , QImage::Format_RGB888);
    QImageWriter writer(&buffer,"jpg");
    writer.write(imgDst);
    ui->lol->setPixmap(QPixmap::fromImage(imgDst.scaled(ui->lol->width(), ui->lol->height())));
    out<<(quint32)buffer.size()<<ui->message->text();
    baDatagram.append(buffer.data());
    if(ui->UDP->isChecked())
        UdpSocket->writeDatagram(baDatagram,QHostAddress(ui->address->currentText()) , ui->port->currentText().toInt());
    if(ui->TCP->isChecked()){
        TcpSocket->write(baDatagram);
    }

}

void MainWindow::receivingMessage()
{
    if(ui->receive->isChecked()){

        if(ui->port->currentText().toInt()<=0){
            QMessageBox::critical (0,"Ошибка!","Порт не выбран!",QMessageBox::Ok);
            ui->receive->setChecked(false);
        }
        else{
            if(ui->UDP->isChecked()){
                if(!UdpSocket->bind(ui->port->currentText().toInt())){
                    QMessageBox::critical (0,"Ошибка!","Данный порт занят!",QMessageBox::Ok);
                    ui->receive->setChecked(false);
                }
                else{
                    connect(UdpSocket,SIGNAL(readyRead()),SLOT(messageRead()));
                    ui->send->setDisabled(true);
                    ui->port->setEnabled(false);
                    ui->rate->setReadOnly(true);
                    ui->address->setEnabled(false);
                    ui->UDP->setEnabled(false);
                    ui->TCP->setEnabled(false);
                }
            }
            if(ui->TCP->isChecked()){
                QHostAddress hostAddress;
                QString str=ui->address->currentText().trimmed();
                if (str=="ANY"||str=="any")
                    hostAddress=QHostAddress::Any;
                else if  (str=="local"||str=="localhost")
                    hostAddress=QHostAddress::LocalHost;
                else
                    hostAddress= QHostAddress(str);
                if(TCPserver->listen(hostAddress,ui->port->currentText().toInt())){
                    countTcpSok=0;
                    MapTcpSok= new QMap<int,QTcpSocket*>;
                    connect(TCPserver,SIGNAL(newConnection()),this, SLOT(slotNewTcpConnection()));
                    ui->send->setDisabled(true);
                    ui->port->setEnabled(false);
                    ui->rate->setReadOnly(true);
                    ui->address->setEnabled(false);
                    ui->UDP->setEnabled(false);
                    ui->TCP->setEnabled(false);
                }
                else{
                    QMessageBox::critical (0,"Ошибка!","Данный порт занят!",QMessageBox::Ok);
                    ui->receive->setChecked(false);
                }

            }
        }
    }
    else{
        ui->send->setDisabled(false);
        ui->rate->setReadOnly(false);
        ui->port->setEnabled(true);
        ui->address->setEnabled(true);
        ui->UDP->setEnabled(true);
        ui->TCP->setEnabled(true);
        QMap<int,QTcpSocket*>::iterator it=MapTcpSok->begin();
        for (;it != MapTcpSok->end(); ++it) {
            QTcpSocket* socket= it.value();
            socket->deleteLater();
        }
        UdpSocket->close();
        TCPserver->close();
        delete MapTcpSok;
        countTcpSok=0;
    }
}

void MainWindow::timeSend()
{
    if(ui->send->isChecked()){
        nameCap=QFileDialog::getOpenFileName();
        if(nameCap.isEmpty())
            return;
        capture= cvCreateFileCapture( nameCap.toLatin1() );
        qDebug()<<nameCap;
        if(""==ui->port->currentText()||""==ui->address->currentText()){
            QMessageBox::critical (0,"Ошибка!","Адресс или порт не выбраны!",QMessageBox::Yes);
            ui->send->setChecked(false);
        }


            ui->receive->setDisabled(true);
            ui->port->setEnabled(false);
            ui->rate->setReadOnly(true);
            ui->address->setEnabled(false);
            ui->UDP->setEnabled(false);
            ui->TCP->setEnabled(false);

            int time=ui->rate->text().toInt();
            if(time==0)
                time=1000;

        if(ui->TCP->isChecked()){
            TcpSocket->connectToHost(ui->address->currentText(),ui->port->currentText().toInt());
        }
            pTimer->setInterval(time);
            pTimer->start();
    }
    else{
        ui->receive->setDisabled(false);
        ui->rate->setReadOnly(false);
        ui->port->setEnabled(true);
        ui->address->setEnabled(true);
        ui->UDP->setEnabled(true);
        ui->TCP->setEnabled(true);
        pTimer->stop();

        UdpSocket->close();
        TcpSocket->disconnect();
        TcpSocket->close();
    }

}

void MainWindow::clickedUDP()
{
    ui->UDP->setChecked(true);
    ui->TCP->setChecked(false);
}

void MainWindow::clickedTCP()
{
    ui->TCP->setChecked(true);
    ui->UDP->setChecked(false);
}

void MainWindow::messageRead()
{
    int m_nNextBlockSize=0;
    QString str;
    if (!m_nNextBlockSize) {
        QDataStream in(UdpSocket);
        if (UdpSocket->bytesAvailable() < sizeof(quint32)) {
                return;
        }
        in>>m_nNextBlockSize>>str;;
        qDebug()<<m_nNextBlockSize;
    }
    if(UdpSocket->bytesAvailable())
        return;
    ui->logList->append("Client has sent- :"+str);
    QByteArray bar=UdpSocket->read(m_nNextBlockSize);
    QBuffer buffer(&bar);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"jpg");
    QImage imgDst=reader.read();

    if(!imgDst.isNull())
      ui->lol->setPixmap(QPixmap::fromImage(imgDst.scaled(ui->lol->width(), ui->lol->height())));
}

void MainWindow::slotNewTcpConnection()
{
    QTcpSocket* pClientSocket;
    pClientSocket = TCPserver->nextPendingConnection();
        connect(pClientSocket, SIGNAL(disconnected()),
                pClientSocket, SLOT(deleteLater())
               );
        connect(pClientSocket, SIGNAL(readyRead()),
                this,          SLOT(slotReadTcpClient())
                );
    countTcpSok++;
    MapTcpSok->insert(countTcpSok,pClientSocket);
}

void MainWindow::slotReadTcpClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();

    QString str;
    int m_nNextBlockSize=0;
    if (!m_nNextBlockSize) {
        QDataStream in(pClientSocket);
        if (pClientSocket->bytesAvailable() < sizeof(quint32)) {
                return;
        }
        in>>m_nNextBlockSize>> str;
        qDebug()<<m_nNextBlockSize;
    }
    if(m_nNextBlockSize>pClientSocket->bytesAvailable())
        return;
    QByteArray bar=pClientSocket->read(m_nNextBlockSize);
    QBuffer buffer(&bar);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"jpg");
    QImage imgDst=reader.read();
      QString strMessage ="Client has sent TCP- " + str;
      ui->logList->append(strMessage);
    if(!imgDst.isNull())
      ui->lol->setPixmap(QPixmap::fromImage(imgDst.scaled(ui->lol->width(), ui->lol->height())));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    UdpSocket->close();
    UdpSocket->abort();
    TCPserver->close();
    TcpSocket->close();
    TcpSocket->abort();
    qDebug()<<"close NMEA"<<endl;
    event->accept();
}
