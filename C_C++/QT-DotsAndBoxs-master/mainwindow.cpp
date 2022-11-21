#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(WINDOWS_LENGHT,WINDOWS_HEIGHT);
    ui->groupBox->setGeometry(CHESS_FX*2+(CHESS_X_NUM-1)*CHESS_LENGHT,CHESS_FY-30,191,41);
    QPixmap p1(":/img/backgound");
    Borad.inition();
    backGound=p1.scaled(width(),height());
    connect(&server,&Server::getData,this,&MainWindow::serverGetData);
    connect(&client,&Client::getData,this,&MainWindow::clientGetData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    ui->centralWidget->setMouseTracking(true);
    setMouseTracking(true);
    QPainter p(this);
    paintInition(p);
    paintBackGound(p);
    paintRectangle(p);
    paintLine(p);
    paintTempLine(p);
    paintCircle(p);
    paintWinNum(p);
}
void MainWindow::mouseMoveEvent(QMouseEvent *m)
{
    MousX=m->pos().x();
    MousY=m->pos().y();
    ChessMan c(Xcol(MousX,COLTYPE),ycol(MousY,COLTYPE));
    if(refresh)
    {
        update();
        refresh=!refresh;
    }
    if(!Borad.getRole(c.getIndex()))
    {
        update();
        refresh=true;
    }

}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(!Borad.isEnd())
    {
        Xcol x1(e->pos().x(),COLTYPE);
        ycol y1(e->pos().y(),COLTYPE);
        ChessMan down(x1,y1);
        if(GAMEMOD==PVP)
        {
            Borad.downHere(down.getIndex());
        }
        else if(GAMEMOD==PVE)
        {
            if(Borad.getColor()==!(AIDOWNCOLOR-1)+1)
            {
                Borad.downHere(down.getIndex());
            }
            if(Borad.getColor()==AIDOWNCOLOR)
            {
                bool isAiDown=false;
                greedAi simpleAi;
                while(true)
                {
                    simpleAi.setAiDown(isAiDown);
                    simpleAi.setBorad(Borad);
                    if(Borad.downHere(simpleAi.aiMove()))
                        break;
                    if(Borad.isEnd())
                        break;
                    isAiDown=true;
                }
            }
        }
        else if(GAMEMOD==NETWORK&&NETWORKWAIT)
        {
            if(FRISTNET)
            {
                NETWORKCOLOR=RED;
                Borad.inition();
                FRISTNET=false;
            }
            if(NETWORKMODE==SERVER)
            {
                server.sendData(DOWNTYPE,down.getIndex());
            }
            if(NETWORKMODE==CLIENT)
            {
                client.sendData(DOWNTYPE,down.getIndex());
            }
            if(Borad.downHere(down.getIndex()))
            {
               NETWORKWAIT=false;
            }

        }


        if(Borad.isEnd())
        {
            if(Borad.whoWin()==0)
                QMessageBox::information(this,tr("信息"),tr("游戏结束-平局"));
            if(Borad.whoWin()==1)
                QMessageBox::information(this,tr("信息"),tr("游戏结束-红方获胜"));
            if(Borad.whoWin()==2)
                QMessageBox::information(this,tr("信息"),tr("游戏结束-蓝方获胜"));
        }
    }
    update();
}
void MainWindow::paintInition(QPainter &p)
{

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(50);
    QBrush Brush;
    Brush.setStyle(Qt::SolidPattern);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setBrush(Brush);
    p.setFont(font);
}
void MainWindow::paintBackGound(QPainter &p)
{
    p.drawPixmap(0,0,backGound);
}
void MainWindow::paintCircle(QPainter &p)
{
    paintInition(p);
    QPen bi;
    bi.setWidth(8);
    bi.setColor(Qt::black);
    bi.setStyle(Qt::SolidLine);
    bi.setCapStyle(Qt::SquareCap);
    p.setPen(bi);
    for(int i=1;i<=CHESS_X_NUM;i++)
    {
        for(int j=1;j<=CHESS_Y_NUM;j++)
        {
          Xcol x1(i,XYTYPE);
          ycol y1(j,XYTYPE);
          p.drawEllipse(x1.toCol(),y1.toCol(),CHESS_CIRCEL_LENGHT,CHESS_CIRCEL_LENGHT);
        }
    }
}
void MainWindow::paintLine(QPainter &p)
{
    for(int i=1;i<=CHESS_ALL_SIDE_NUM;i++)
    {
        if(Borad.getRole(i))
        {
            QPen bi;
            bi.setWidth(8);
            bi.setStyle(Qt::SolidLine);
            bi.setCapStyle(Qt::SquareCap);
            if(Borad.getRole(i)==1)
            {
                bi.setColor(Qt::red);
            }
            else
            {
                bi.setColor(Qt::blue);
            }
            p.setPen(bi);
            ChessMan Temp(i);
            p.drawLine(Temp.getFristX().toCol()+5,Temp.getFristY().toCol()+5,Temp.getSecondX().toCol()+5,Temp.getSecondY().toCol()+5);
        }
    }
}
void MainWindow::paintRectangle(QPainter &p)
{
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(Borad.getBoxRole(i)==1||Borad.getBoxRole(i)==2)
        {
            QBrush bi;
            bi.setStyle(Qt::SolidPattern);
            if(Borad.getBoxRole(i)==1)
                bi.setColor(QColor(255,0,0,150));
            else if(Borad.getBoxRole(i)==2)
                bi.setColor(QColor(0,0,255,150));
            p.setPen(QPen(Qt::blue,0.1,Qt::DashLine));
            p.setBrush(bi);
            ChessMan L1(Borad.getFristLine(i));
            ChessMan L2(Borad.getSecondLine(i));
            p.drawRect(L1.getFristX().toCol()+5,L1.getFristY().toCol()+5,CHESS_LENGHT,CHESS_LENGHT);

        }

    }
}
void MainWindow::paintTempLine(QPainter &p)
{

    ChessMan c(Xcol(MousX,COLTYPE),ycol(MousY,COLTYPE));
    ui->centralWidget->setCursor(QCursor(Qt::ArrowCursor));
    if(!Borad.getRole(c.getIndex()))
    {
        if(NETWORKMODE)
            if(!NETWORKWAIT)
                return;
        ui->centralWidget->setCursor(QCursor(Qt::PointingHandCursor));
        QPen bi;
        bi.setWidth(8);
        bi.setStyle(Qt::SolidLine);
        bi.setCapStyle(Qt::SquareCap);
        if(Borad.getColor()==1)
            bi.setColor(QColor(255,0,0,100));
        else if(Borad.getColor()==2)
            bi.setColor(QColor(0,0,255,100));
        p.setPen(bi);
        p.drawLine(c.getFristX().toCol()+5,c.getFristY().toCol()+5,c.getSecondX().toCol()+5,c.getSecondY().toCol()+5);
    }
}
void MainWindow::paintWinNum(QPainter &p)
{

        for(int i=0;i<CHESS_BOX_NUM;i++)
        {
            ChessMan L1(Borad.getFristLine(i));
            ChessMan L2(Borad.getSecondLine(i));
            int x=(L1.getFristX().toCol()+L2.getSecondX().toCol())/2-15;
            int y=(L1.getFristY().toCol()+L2.getSecondY().toCol())/2+28;
            QPen bi;
            bi.setColor(Qt::white);
            p.setPen(bi);
            int RedNum=Borad.getRedBoxMark(i);
            int BlueNum=Borad.getBlueBoxMark(i);
            if(Borad.getBoxRole(i)==1)
            {
                if(RedNum>=10)
                    x-=20;
                p.drawText(x,y,QString::number(RedNum));
            }
            else if(Borad.getBoxRole(i)==2)
            {
                if(BlueNum>=10)
                    x-=20;
                p.drawText(x,y,QString::number(BlueNum));
            }
         }
}

void MainWindow::on_newGame_triggered()
{
    Borad.inition();
    if(GAMEMOD==PVE&&AIDOWNCOLOR==RED)
    {
        greedAi Ai;
        Ai.setBorad(Borad);
        Borad.downHere(Ai.aiMove());
    }
    update();
}
void MainWindow::on_pushButton_clicked()
{
    if(GAMEMOD==PVP)
    {
        Borad.backBorad();
    }
    if(GAMEMOD==PVE)
    {
        Borad.backBorad();
    }
    if(GAMEMOD==NETWORK)
    {
        Borad.backBorad();
        if(NETWORKCOLOR==Borad.getColor())
            NETWORKWAIT=true;
        else
            NETWORKWAIT=false;
        if(NETWORKMODE==SERVER)
            server.sendData(BACKTYPE,0);
        if(NETWORKMODE==CLIENT)
            client.sendData(BACKTYPE,0);
    }
    update();
}
void MainWindow::on_gameSet_2_triggered()
{
    gameSetDialog=new GameSet();
    gameSetDialog->SetSerAndClient(server,client);
    gameSetDialog->exec();
}
void MainWindow::serverGetData(int &type,int &content)
{
    if(FRISTNET)
    {
        FRISTNET=false;
        NETWORKCOLOR=BLUE;
    }
    if(type==DOWNTYPE)
    {
       Borad.downHere(content);
       NETWORKWAIT=true;
    }
    if(type==BACKTYPE)
    {
       Borad.backBorad();
       if(Borad.getColor()==NETWORKCOLOR)
           NETWORKWAIT=true;
    }
    if(Borad.isEnd())
    {
        if(Borad.whoWin()==0)
            QMessageBox::information(this,tr("信息"),tr("游戏结束-平局"));
        if(Borad.whoWin()==1)
            QMessageBox::information(this,tr("信息"),tr("游戏结束-红方获胜"));
        if(Borad.whoWin()==2)
            QMessageBox::information(this,tr("信息"),tr("游戏结束-蓝方获胜"));
    }
    update();
}
void MainWindow::clientGetData(int &type,int &content)
{
    if(FRISTNET)
    {
        Borad.inition();
        FRISTNET=false;
        NETWORKCOLOR=BLUE;
    }
    if(type==DOWNTYPE)
    {
       Borad.downHere(content);
       NETWORKWAIT=true;
    }
    if(type==BACKTYPE)
    {
       Borad.backBorad();
       if(Borad.getColor()==NETWORKCOLOR)
           NETWORKWAIT=true;
    }
    if(Borad.isEnd())
    {
        if(Borad.whoWin()==0)
            QMessageBox::information(this,tr("信息"),tr("游戏结束-平局"));
        if(Borad.whoWin()==1)
            QMessageBox::information(this,tr("信息"),tr("游戏结束-红方获胜"));
        if(Borad.whoWin()==2)
            QMessageBox::information(this,tr("信息"),tr("游戏结束-蓝方获胜"));
    }
    update();
}
