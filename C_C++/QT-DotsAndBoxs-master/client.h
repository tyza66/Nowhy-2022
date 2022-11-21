#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <gogal.h>
class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket * c1;
    int Type;
    int Content;
    bool isConnection=false;
private slots:
    void disconnection();
    void readData();
signals:
    void getData(int &type,int &content);
public:
    bool sendData(int type,int content);
    int  getContent();
    int  getType();
    bool connectToHost(QString Ip,int Port);
    void disConnect();
    bool getConnection();
};

#endif // CLIENT_H
