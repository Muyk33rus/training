#ifndef QSOCKETRUN_H
#define QSOCKETRUN_H
#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

class QSocketRun : public QRunnable
{
public:
    QSocketRun(int handle);
    void run();
private:
    int discriptor;
};

#endif // QSOCKETRUN_H
