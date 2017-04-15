#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv2/highgui.hpp>
#include <opencv/cv.h>
#include <QMainWindow>
#include <QTimer>
#include <QtNetwork>
#include <QCloseEvent>
#include <QErrorMessage>
#include <QMessageBox>
#include <QMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sendToTcpClient(QTcpSocket* pSocket, QByteArray &arrBlock);
    void slotError(QAbstractSocket::SocketError err);
private:
    CvCapture* capture;
    Ui::MainWindow *ui;
    QTimer* pTimer;
    QTcpServer* TCPserver;
    QUdpSocket* UdpSocket;
    QTcpSocket* TcpSocket;
    QString nameCap;
    QMap<int,QTcpSocket*> *MapTcpSok;
    int countTcpSok;
private slots:
    void sendMessage();
    void receivingMessage();
    void timeSend();
    void clickedUDP();
    void clickedTCP();
    void messageRead();
    void slotNewTcpConnection();
    void slotReadTcpClient();
 protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
