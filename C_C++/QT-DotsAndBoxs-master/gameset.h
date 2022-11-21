#ifndef GAMESET_H
#define GAMESET_H
#include <QString>
#include <QDialog>
#include <gogal.h>
#include <server.h>
#include <client.h>
#include <QWidget>
#include <QMessageBox>
namespace Ui {
class GameSet;
}

class GameSet : public QDialog
{
    Q_OBJECT
public:
    explicit GameSet(QWidget *parent = 0);
    void SetSerAndClient(Server & s1,Client & c1);
    ~GameSet();
private slots:
    void on_cancel_clicked();
    void on_pvpSelet_clicked();
    void on_pveSelet_clicked();
    void on_networkSelet_clicked();
    void on_comfirm_clicked();
    void on_serverRadio_clicked();
    void on_clientRadio_clicked();
    void on_serverListen_clicked();
    void on_clientConnect_clicked();
private:
    void setNetWorkEnble(int type,bool isEnable);
    Server  *server;
    Client  *client;
    Ui::GameSet *ui;
};

#endif // GAMESET_H
