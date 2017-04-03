#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMainWindow::setFixedSize(370,420);
    UDPserver  =  new QUdpSocket();
    TCPserver  =  new QTcpServer();
    TcpSocket   =  new QTcpSocket(this);
    ui->setupUi(this);

    ui->logList->setReadOnly(true);
    pTimer = new QTimer(this);
    ui->UDP->setChecked(true);
    ui->send->setCheckable(true);
    ui->send->setChecked(false);
    ui->receive->setCheckable(true);
    ui->receive->setChecked(false);

    connect(ui->receive,SIGNAL(clicked()),this,SLOT(receivingMessage()));
    connect(ui->send,   SIGNAL(clicked()),this,SLOT(timeSend())     );
    connect(ui->UDP,    SIGNAL(clicked()),this,SLOT(clickedUDP())   );
    connect(ui->TCP,    SIGNAL(clicked()),this,SLOT(clickedTCP())   );
    connect(pTimer,     SIGNAL(timeout()),this,SLOT(sendMessage())  );

}

MainWindow::~MainWindow()
{
    UDPserver->abort();
    delete ui;
    delete pTimer;
    delete UDPserver;
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
    QByteArray baDatagram;
    QDataStream out(&baDatagram, QIODevice::WriteOnly);
    out<<ui->message->text();
//    ui->logList->append(ui->message->text());
//    ui->logList->append(ui->address->currentText());
//    ui->logList->append(ui->port->text());
    if(ui->UDP->isChecked())
        UDPserver->writeDatagram(baDatagram,QHostAddress(ui->address->currentText()) , ui->port->currentText().toInt());
    if(ui->TCP->isChecked()){
        TcpSocket->write(baDatagram);
    }

}

void MainWindow::receivingMessage()
{
    if(ui->receive->isChecked()){

        if(ui->port->currentText().toInt()<=0){
            QMessageBox::critical (0,"Ошибка!","Порт не выбран!",QMessageBox::Yes);
            ui->receive->setChecked(false);
        }
        else{
            if(ui->UDP->isChecked()){
                if(!UDPserver->bind(ui->port->currentText().toInt())){
                    QMessageBox::critical (0,"Ошибка!","Данный порт занят!",QMessageBox::Yes);
                    ui->receive->setChecked(false);
                }
                else{
                    connect(UDPserver,SIGNAL(readyRead()),SLOT(messageRead()));
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
                    connect(TCPserver,SIGNAL(newConnection()),this, SLOT(slotNewTcpConnection()));
                    ui->send->setDisabled(true);
                    ui->port->setEnabled(false);
                    ui->rate->setReadOnly(true);
                    ui->address->setEnabled(false);
                    ui->UDP->setEnabled(false);
                    ui->TCP->setEnabled(false);
                }
                else{
                    QMessageBox::critical (0,"Ошибка!",TCPserver->errorString(),QMessageBox::Yes);
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
        disconnect(UDPserver,0,0,0);
        UDPserver->close();
        TCPserver->close();
    }
}

void MainWindow::timeSend()
{
    if(ui->send->isChecked()){
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
//                connect(TcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
//                connect(TcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
//                connect(TcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
//                            this,         SLOT(slotError(QAbstractSocket::SocketError))
//                           );
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
        UDPserver->close();
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

    QDateTime dateTime;
    QByteArray baDatagram;
    do{
        baDatagram.resize(UDPserver->pendingDatagramSize());
        UDPserver->readDatagram(baDatagram.data(),baDatagram.size());
    }while (UDPserver->hasPendingDatagrams());
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    QString str;
    in>>str;
    ui->logList->append(dateTime.currentDateTime().toString()+" :"+str);
}

void MainWindow::slotNewTcpConnection()
{
    QTcpSocket* pClientSocket = TCPserver->nextPendingConnection();
        connect(pClientSocket, SIGNAL(disconnected()),
                pClientSocket, SLOT(deleteLater())
               );
        connect(pClientSocket, SIGNAL(readyRead()),
                this,          SLOT(slotReadTcpClient())
                );
}

void MainWindow::slotReadTcpClient()
{
    int m_nNextBlockSize=0;
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    for (;;) {
            if (!m_nNextBlockSize) {
                if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
                    break;
                }
                in >> m_nNextBlockSize;
            }

            if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
                break;
            }

            QString str;
            in >> str;

            //QString strMessage = "Client has sent - " + str;
            ui->logList->append(str);

            m_nNextBlockSize = 0;


    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    UDPserver->close();
    UDPserver->abort();
    TCPserver->close();
    TcpSocket->close();
    TcpSocket->abort();
    qDebug()<<"close NMEA"<<endl;
    event->accept();
}
