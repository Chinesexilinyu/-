#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
/*************定时器****************/
#include <QTime>
#include <QTimer>

/*************图形绘制***************/
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QPoint>
#include <QBrush>
#include <QLabel>

/***************弹窗相关*****************/
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <QProcess>

/****************程序调试*********************/
#include <QDebug>
#include<wudaohui_dia.h>
#include<earth_dia.h>


static const int RETCODE_RESTART = 773;
namespace Ui {
class snake;
}

class snake : public QWidget
{
    Q_OBJECT

public:
    explicit snake(QWidget *parent = nullptr);
    ~snake();
public:
    void Init();  //初始化函数界面
    /**************定时器相关**************************/
    public:
          QTimer *m_Timer;
          bool time_flag=false;
          int  base_time=0,time_s=0; //10ms的基础时间
          bool flag_times=false;
    private slots:
          void dida_time();
          void star_time();
          void stop_time();
          void restar_time();
    /**************界面相关**************************/
          void on_Next_but_clicked();

public:
                 int x,y,base;
                 int save[625][2]={{2,0},{1,0},{0,0}};
                 int length=3;
                 int mark=0;
                 int now_head_x,now_head_y;
                 int head_x=2,head_y=0;
                 int food_x=6,food_y=6;
                 bool food_flag=true;
                 char head_direction=4;  // ^1  v2  <3  >4
                 bool head_eat=false;
                 bool move_flag=false;
                 void reboot();
    protected:
                 void paintEvent(QPaintEvent *); //绘制
                 /**************按键相关*************************/
                 protected:
                          void keyPressEvent(QKeyEvent *event);
                          void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::snake *ui;
};

#endif // SNAKE_H
