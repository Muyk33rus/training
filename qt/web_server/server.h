#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
class server : public QTcpServer
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    void incomingConnection(int handle);
signals:

public slots:
private:
    QThreadPool* threadPool;
};

#endif // SERVER_H
