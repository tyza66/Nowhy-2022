#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <gogal.h>
#include <caculate.h>
#include <chessborad.h>
#include <QMouseEvent>
#include <greedai.h>
#include <gameset.h>
#include <client.h>
#include <server.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *m);
    Client client;
    Server server;
private slots:
    void on_newGame_triggered();
    void on_pushButton_clicked();
    void on_gameSet_2_triggered();
    void serverGetData(int &type,int &content);
    void clientGetData(int &type,int &content);
private:
    int MousX;
    int MousY;
    bool refresh=false;
    chessBorad Borad;
    QPixmap backGound;
    void paintBackGound(QPainter &p);
    void paintInition(QPainter &p);
    void paintCircle(QPainter &p);
    void paintLine(QPainter &p);
    void paintRectangle(QPainter &p);
    void paintTempLine(QPainter &p);
    void paintWinNum(QPainter &p);
    GameSet * gameSetDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
