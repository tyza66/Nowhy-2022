#ifndef SERVER_H
#define SERVER_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <gogal.h>
#include <QString>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
class Server : public QObject
{
    Q_OBJECT
public:
    bool listen(int Port);
    bool isConnect();
    void sendData(int type,int content);
    int getType();
    int getContent();
    void disConnect();
    QTcpServer * s1;
    QTcpSocket * c1;
    void serverNewConnection();
    void serverReadData();
    void serverDisconnected();
signals:
    void getData(int &type,int &content);
private:
    int Port;
    int Type;
    int Content;
    bool isConnection=false;
};

#endif // SERVER_H
