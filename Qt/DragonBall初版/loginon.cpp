#include "loginon.h"
#include "ui_loginon.h"

LoginOn::LoginOn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginOn)
{
    ui->setupUi(this);
}

LoginOn::~LoginOn()
{
    delete ui;
}

void LoginOn::on_LogOn_clicked()
{
    QString name,mima;
    name=ui->User_shuru->text();
    mima=ui->Mima_Shuru->text();
    if(name=="DragonBall")
        if(mima=="123456")
        {
            bb=new Background_Dialogue;
            bb->show();
            this->close();
        }
}
