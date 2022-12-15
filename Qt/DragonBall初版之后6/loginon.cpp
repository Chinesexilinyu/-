#include "loginon.h"
#include "ui_loginon.h"

LoginOn::LoginOn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginOn)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);

    //数据库连接
          //连接数据库
             //查看当前支持的数据库的驱动
              qDebug()<<QSqlDatabase::drivers();

              QSqlDatabase DB;//创建一个数据库的文件
             //加载数据库的文件
              QString aFile="./dataBase.db";
              if(aFile.isEmpty())
              {
                  qDebug()<<" 数据库文件加载失败 " ;
                  return ;
              }
              //打开数据库
              DB=QSqlDatabase::addDatabase("QSQLITE");//创建QSQLITE数据库连接
              DB.setDatabaseName(aFile); //数据库名
              if(!DB.open())
              {
                  //没有数据库文件则创建文件
                  qDebug()<<"数据库文件打开失败";
                  qDebug()<<DB.lastError().text();//输出错误信息
               }
              qDebug()<< " 打开数据库文件成功 " ;

          //从配置文件中读取用户名和密码：
              QSettings setting("config.ini",QSettings::IniFormat);
              QString account = setting.value("section/account").toString();
              QString password = setting.value("section/password").toString();
              ui->User_shuru->setText(account);
              ui->Mima_Shuru->setText(password);

             //用户注册，向数据库插入数据
              connect(ui->Register_Button,&QPushButton::clicked,this,[=](){

              //接受用户输入：
                  QString account = ui->User_shuru->text();//用户账号
                  QString password = ui->Mima_Shuru->text();//密码

              //创建自己需要使用的表格
                  QSqlQuery querry;
                  if(!querry.exec("create table user(account varchar(255) primary key, password varchar(255))"))
                  {
                      qDebug() << "Error: Fail to create table."<< querry.lastError();
                  }
                  else
                  {
                      qDebug() << "Table created!";
                  }


              //插入数据
                  QString qs = QString("insert into user(account,password) values('%1','%2')")
                          .arg(account).arg(password);

                  if(querry.exec(qs)) //如果插入成功
                  {
                      QMessageBox::information(this,"注册","注册成功");
                  }
                  else
                  {
                      QMessageBox::information(this,"注册","注册失败");
                      qDebug()<<querry.lastError().text();//输出错误信息
                      //return;
                  }

              //查看数据
                  //查看数据库中有的表格的名字
                  qDebug()<<"查看数据库中所有的表：";
                  QStringList str_table=DB.tables();
                  qDebug()<<str_table;
                  //查询数据库中的数据
                  qDebug()<<"查看数据库中数据";
                  querry.prepare ("SELECT * FROM user");
                  querry.exec();
                  while(querry.next())
                  {
                      qDebug()<<QString("account:%1,password:%2").
                                arg(querry.value("account").toString()).arg(querry.value("password").toString());
                  }

              });

          //用户登录：查询数据

              connect(ui->LogOn,&QPushButton::clicked,this,[=](){

                  //接受用户输入：
                   QString account = ui->User_shuru->text();//用户账号
                   QString password = ui->Mima_Shuru->text();//密码

                  //查询数据
                   QSqlQuery query(DB);
                   QString qs = QString("select * from user where account ='%1' and password='%2'").
                           arg(account).arg(password);

                   if(!query.exec(qs))//如果没有查到记录
                   {
                       qDebug() << query.lastError().text();//输出错误信息
                       return;
                   }

                   //获取查询的数据
                   if(query.next())//获取到数据
                   {
                       QMessageBox::information(this,"登录","登录成功");
                       Background_Dialogue*bb=new Background_Dialogue;
                       bb->show();
                       this->close();


                   }
                   else
                   {
                       QMessageBox::information(this,"登录","登录失败");
                   }
              });
}

LoginOn::~LoginOn()
{
    delete ui;
}


