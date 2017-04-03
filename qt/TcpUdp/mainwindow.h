#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtNetwork>
#include <QCloseEvent>
#include <QErrorMessage>
#include <QMessageBox>
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
    Ui::MainWindow *ui;
    QTimer* pTimer;
    QTcpServer* TCPserver;
    QUdpSocket* UDPserver;
    QTcpSocket* TcpSocket;
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
