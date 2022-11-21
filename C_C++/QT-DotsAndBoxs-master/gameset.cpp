#include "gameset.h"
#include "ui_gameset.h"

GameSet::GameSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameSet)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    this->setWindowFlags(Qt::FramelessWindowHint);
    if(NETWORKMODE==SERVER)
    {
        setNetWorkEnble(SERVER,true);
        setNetWorkEnble(CLIENT,false);
        ui->serverRadio->setChecked(true);
        ui->serverListen->setText(tr("取消侦听"));
        ui->clientRadio->setEnabled(false);
        ui->serverPort->setEnabled(false);
    }
    else if(NETWORKMODE==CLIENT)
    {
        ui->clientRadio->setChecked(true);
        ui->clientConnect->setText(tr("取消连接"));
        ui->serverRadio->setEnabled(false);
        ui->clientPort->setEnabled(false);
        ui->clientIP->setEnabled(false);
        setNetWorkEnble(CLIENT,true);
        setNetWorkEnble(SERVER,false);
    }
    else if(NETWORKMODE==0)
    {
        setNetWorkEnble(CLIENT,false);
        setNetWorkEnble(SERVER,false);
    }
    if(AIDOWNCOLOR==RED)
    {
        ui->AiFrist->setChecked(true);
    }
    if(AIDOWNCOLOR==BLUE)
    {
        ui->playerFrist->setChecked(true);
    }
    if(GAMEMOD==PVP)
    {
        ui->tabWidget->setCurrentIndex(0);
        ui->pvpSelet->setChecked(true);
    }
    if(GAMEMOD==PVE)
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->pveSelet->setChecked(true);
    }
    if(GAMEMOD==NETWORK)
    {
        ui->tabWidget->setCurrentIndex(2);
        ui->networkSelet->setChecked(true);
    }
}
GameSet::~GameSet()
{
    delete ui;
}
void GameSet::on_cancel_clicked()
{
    this->close();
}

void GameSet::on_pvpSelet_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void GameSet::on_pveSelet_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}
void GameSet::on_networkSelet_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void GameSet::on_comfirm_clicked()
{
    if(ui->pvpSelet->isChecked())
    {
        GAMEMOD=PVP;
    }
    if(ui->pveSelet->isChecked())
    {
        GAMEMOD=PVE;
        if(ui->AiFrist->isChecked())
        {
          AIDOWNCOLOR=RED;
        }
        if(ui->playerFrist->isChecked())
        {
          AIDOWNCOLOR=BLUE;
        }
    }
    if(ui->networkSelet->isChecked())
    {
        GAMEMOD=NETWORK;
    }
    this->close();
}
void GameSet::SetSerAndClient(Server & s1,Client & c1)
{
    server=&s1;
    client=&c1;
}
void GameSet::setNetWorkEnble(int type,bool isEnable)
{
    if(type==SERVER)
    {
        ui->serverPort->setEnabled(isEnable);
        ui->serverListen->setEnabled(isEnable);
    }
    if(type==CLIENT)
    {
        ui->clientConnect->setEnabled(isEnable);
        ui->clientIP->setEnabled(isEnable);
        ui->clientPort->setEnabled(isEnable);
    }
}

void GameSet::on_serverRadio_clicked()
{
    setNetWorkEnble(SERVER,true);
    setNetWorkEnble(CLIENT,false);
    NETWORKWAIT=true;
}
void GameSet::on_clientRadio_clicked()
{
    setNetWorkEnble(CLIENT,true);
    setNetWorkEnble(SERVER,false);
    NETWORKWAIT=true;
}

void GameSet::on_serverListen_clicked()
{
    if(ui->serverListen->text()==tr("侦听"))
    {
        if(server->listen(ui->serverPort->text().toInt()))
        {
            NETWORKMODE=SERVER;
            ui->serverListen->setText(tr("取消侦听"));
            ui->clientRadio->setEnabled(false);
            ui->serverPort->setEnabled(false);
        }
        else
        {
            QMessageBox::information(this,tr("提示"),tr("侦听失败"));
        }
    }
    else
    {
        ui->serverPort->setEnabled(true);
        ui->clientRadio->setEnabled(true);
        ui->serverListen->setText(tr("侦听"));
        NETWORKMODE=0;
        server->disConnect();
    }
}

void GameSet::on_clientConnect_clicked()
{
    if(ui->clientConnect->text()==tr("连接"))
    {
        ui->clientConnect->setText(tr("连接中"));
        if(client->connectToHost(ui->clientIP->text(),ui->clientPort->text().toInt()))
        {
            NETWORKMODE=CLIENT;
            ui->clientConnect->setText(tr("取消连接"));
            ui->serverRadio->setEnabled(false);
            ui->clientPort->setEnabled(false);
            ui->clientIP->setEnabled(false);
        }
        else
        {
            ui->clientConnect->setText(tr("连接"));
            QMessageBox::information(this,tr("提示"),tr("连接失败"));
        }
    }
    else
    {
        ui->clientPort->setEnabled(true);
        ui->clientIP->setEnabled(true);
        ui->serverRadio->setEnabled(true);
        ui->clientConnect->setText(tr("连接"));
        NETWORKMODE=0;
        client->disConnect();
    }
}
