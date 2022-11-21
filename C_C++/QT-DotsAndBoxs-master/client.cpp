#include "client.h"


bool Client::sendData(int type,int content)
{
    QJsonObject ob;
    ob.insert("type",type);
    ob.insert("content",content);
    QJsonDocument doc;
    doc.setObject(ob);
    QByteArray byt=doc.toJson(QJsonDocument::Compact);
    c1->write(byt);
}
int Client::getContent()
{
    return Content;
}
int Client::getType()
{
    return Type;
}
bool Client::connectToHost(QString Ip,int Port)
{
    c1=new QTcpSocket();
    QObject::connect(c1,&QTcpSocket::readyRead,this,&Client::readData);
    QObject::connect(c1,&QTcpSocket::disconnected,this,&Client::disconnection);
    c1->connectToHost(Ip,Port);
    if(!c1->waitForConnected(3000))
    {return false;}
    isConnection=true;
    return true;
}
void Client::disConnect()
{
    c1->disconnectFromHost();
}
void Client::disconnection()
{
    isConnection=false;
}
void Client::readData()
{
    QByteArray b1=c1->readAll();
    QJsonDocument jd=QJsonDocument::fromJson(b1);
    QJsonObject data=jd.object();
    Type=data.value("type").toInt();
    Content=data.value("content").toInt();
    emit getData(Type,Content);
}
bool Client::getConnection()
{
    return isConnection;
}
