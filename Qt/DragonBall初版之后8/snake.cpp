#include "snake.h"
#include "ui_snake.h"

snake::snake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::snake)
{
    ui->setupUi(this);
    this->Init();  //初始化界面函数
}

snake::~snake()
{
    delete ui;
}
void snake::Init()//初始化函数
{

  ui->lcd_mark->display(0);
  ui->lcd_time->display(0);


  //关联按键和信号函数
  connect(ui->btn_star,SIGNAL(clicked()),this,SLOT(star_time()));
  connect(ui->btn_stop,SIGNAL(clicked()),this,SLOT(stop_time()));
  connect(ui->btn_restar,SIGNAL(clicked()),this,SLOT(restar_time()));
}

void snake::star_time() //开启定时器
{
    m_Timer = new QTimer(this);
    m_Timer->start(100);//设定溢出时间100ms
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(dida_time()));//溢出后自动调用dida_time
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  //  qDebug("OK!");
    time_flag=true;
}

void snake::stop_time() //断开连接信号，即无法自动调用dida_time
{
    if(time_flag==true)
 { disconnect(m_Timer,SIGNAL(timeout()),this,SLOT(dida_time())); time_flag=false; }
}

void snake::restar_time() //调用重启函数
{
  reboot();
}

void snake::dida_time() //每100ms调用一次
{
   base_time++;
   time_s=base_time/10;
   ui->lcd_time->display(time_s); //累加时间

 // if(base_time%10==1) //1s时间到
   {

      /*********************是否吃掉食物********************************************/
       if(head_x==food_x && head_y==food_y)
       {
            head_eat=true;
            mark++;
            length++;
            ui->lcd_mark->display(mark);
       }


       /**********************随机格子**************************/
         if(head_eat==false) //旧食物
         {

         }
         else  //新生成食物
         {

             food_x=qrand()%25; //在25x25的格子内生成食物
             food_y=qrand()%25;

             for(int i=1;i<length; i++) //防止食物为蛇身
             {
                 if(food_x==save[i][0] && food_y==save[i][1])//若为蛇身，重构食物
                 {
                     food_x=qrand()%25;
                     food_y=qrand()%25;
                     i=1;
                 }
             }

             head_eat=false;
         }

  // qDebug("????");
    now_head_x=head_x; //获取当前蛇头位置
    now_head_y=head_y;

    switch(head_direction) //添加蛇头位置
    {
      case 1: head_y--;  break;  // ^
      case 2: head_y++;  break;  // v
      case 3: head_x--;  break;  // <
      case 4: head_x++;  break;  // >
    }

    /************************检查是否死亡************************/
    for(int i=1;i<length; i++)
    {
        if(head_x==save[i][0] && head_y==save[i][1])//是否为自环死亡
          {
            disconnect(m_Timer,SIGNAL(timeout()),this,SLOT(dida_time()));
             QMessageBox message(QMessageBox::NoIcon, "挑战失败", "the game is over!");
               message.exec();
               Earth_Dia*earth=new Earth_Dia;
               earth->show();
               this->close();
           }
        else
        {
         if(head_x>24 || head_y>24 ||head_x<0 || head_y<0)//是否为撞墙死亡
         {
             disconnect(m_Timer,SIGNAL(timeout()),this,SLOT(dida_time()));
              QMessageBox message(QMessageBox::NoIcon, "挑战失败", "the game is over!");
                message.exec();
                Earth_Dia*earth=new Earth_Dia;
                earth->show();
                this->close();
         }
        }
    }

    //  qDebug("direcrtion:%d  head_x:%d  head_y:%d",head_direction,head_x,head_y);

   for(int i=1;i<length; i++)//更新蛇身位置信息
   {
       save[length-i][0]=save[length-i-1][0];
       save[length-i][1]=save[length-i-1][1];
   }

     save[0][0]=head_x; //更新蛇头位置
     save[0][1]=head_y;

     update(); //刷新屏幕显示
   }

}

void snake::paintEvent(QPaintEvent *)
{

   QPainter painter(this);

 //  painter.drawLine(80,80,100,200);  //图形绘制代码测试
 //  painter.setPen(Qt::red);
 //  painter.drawRect(10,10,100,100);

/***********************画底格****************************/
   painter.setPen(QPen(Qt::blue,2)); //外框色 宽度
   painter.setBrush(Qt::black);  //内涂色
   base=20;
   for(x=0;x<25;x++)for(y=0;y<25;y++)
   painter.drawRect(x*base,y*base,base,base);  // 画25x25格子


/***********************绘制蛇身*****************************/
  painter.setPen(QPen(Qt::yellow,2)); //外框色 宽度
  painter.setBrush(Qt::green);  //内涂色
  for(int num=0;num<length;num++)
    {
       painter.drawRect(save[num][0]*base,save[num][1]*base,base,base);  // 画格子
    }

/***********************画食物*****************************/
    painter.setPen(QPen(Qt::white,2)); //外框色 宽度
    painter.setBrush(Qt::red);  //内涂色
    painter.drawRect(food_x*base,food_y*base,base,base);  // 画格子


  // painter.drawEllipse(50,150,200,200);//画圆
}

void snake::keyPressEvent(QKeyEvent *event)       // 键盘按下事件d
    {
    switch (event->key())
    {
      case Qt::Key_W:
           qDebug("I get up!");   if(head_direction!=2) head_direction=1;   break;
      case Qt::Key_S:
           qDebug("I get down!"); if(head_direction!=1) head_direction=2;   break;
      case Qt::Key_A:
           qDebug("I get left!"); if(head_direction!=4) head_direction=3;   break;
      case Qt::Key_D:
           qDebug("I get right!");if(head_direction!=3) head_direction=4;   break;
      case Qt::Key_Space:
           qDebug("I get Space!"); break;
      default: QWidget::keyPressEvent(event);  break;
    }
    update();
}
void snake::keyReleaseEvent(QKeyEvent *)     // 按键释放事件
{
    // 其他操作
}
void snake::reboot()//重启软件函数
{
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
    exit(0);
}

void snake::on_Next_but_clicked()
{
    Wudaohui_dia*wudao=new Wudaohui_dia;
    wudao->show();
    this->close();
}
