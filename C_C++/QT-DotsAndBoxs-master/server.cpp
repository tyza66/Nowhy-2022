#include "server.h"


bool Server::listen(int Port)
{
        s1=new QTcpServer();
        c1=new QTcpSocket();
        this->Port=Port;
        connect(s1,&QTcpServer::newConnection,this,&Server::serverNewConnection);
        return s1->listen(QHostAddress::Any,Port);

}
void Server::serverNewConnection()
{
    c1=s1->nextPendingConnection();
    QObject::connect(c1,&QTcpSocket::readyRead,this,&Server::serverReadData);
    QObject::connect(c1,&QTcpSocket::disconnected,this,&Server::serverDisconnected);
    isConnection=true;

}
void Server::serverReadData()
{
    QByteArray bty=c1->readAll();
    if(!bty.isEmpty())
    {
        QJsonDocument temp=QJsonDocument::fromJson(bty);
        QJsonObject data=temp.object();
        int type=data.value("type").toInt();
        int content=data.value("content").toInt();
        Type=type;
        Content=content;
        qDebug()<<Type;
        emit getData(Type,Content);
    }
}
void Server::serverDisconnected()
{
    isConnection=false;
}
bool Server::isConnect()
{
    return isConnection;
}
void Server::sendData(int type,int content)
{
    QJsonObject ob;
    ob.insert("type",type);
    ob.insert("content",content);
    QJsonDocument doc;
    doc.setObject(ob);
    QByteArray byt=doc.toJson(QJsonDocument::Compact);
    c1->write(byt);
}
int Server::getContent()
{
    return Content;
}
int Server::getType()
{
    return Type;
}
void Server::disConnect()
{
    isConnection=false;
    if(c1->state()==QAbstractSocket::ConnectedState)
    {
        c1->disconnectFromHost();
    }
    s1->close();
}
