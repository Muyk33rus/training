#include <QCoreApplication>
#include <server.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server newSer;
    return a.exec();
}
