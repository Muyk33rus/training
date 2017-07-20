#include "qsocketrun.h"

QSocketRun::QSocketRun(int handle):discriptor(handle)
{

}

void QSocketRun::run()
{
    QTcpSocket *socket =new QTcpSocket;
    socket->setSocketDescriptor(discriptor);
    socket->waitForReadyRead();
    qDebug()<<socket->readAll();
    QString res("HTTP/1.1 200 OK\r\n\r\n <h1>Hi %1</h1>");
    socket->write(res.arg("max").toLatin1());
    socket->waitForBytesWritten();
    socket->disconnectFromHost();
    socket->close();
    socket->deleteLater();
}
