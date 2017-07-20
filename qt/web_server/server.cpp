#include "server.h"
#include"qsocketrun.h"
#include <QDebug>
server::server(QObject *parent) : QTcpServer(parent)
{
    if(listen(QHostAddress::Any,80)){
        qDebug()<<"Listening...";
    }
    else{
        qDebug()<<errorString();
    }
    threadPool =new QThreadPool(this);
}

void server::incomingConnection(int handle)
{
    QSocketRun* runSock= new QSocketRun(handle);
    threadPool->start(runSock);
}
