#include "renwu_dialogue.h"
#include "ui_renwu_dialogue.h"
#include<QMediaPlayer>


Renwu_Dialogue::Renwu_Dialogue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Renwu_Dialogue)
{
    ui->setupUi(this);
}

Renwu_Dialogue::~Renwu_Dialogue()
{
    delete ui;
}

void Renwu_Dialogue::on_Choose_Button_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%2);
}

void Renwu_Dialogue::on_Fan_Button_clicked()
{
    Background_Dialogue*b=new Background_Dialogue;
    this->close();
    b->show();
}

void Renwu_Dialogue::on_SaiYa_Button_clicked()
{
    SaiYa_Dialogue*SaiYa=new SaiYa_Dialogue;
    QMediaPlayer *startSound=new QMediaPlayer;  //创建一个音乐播放器
    startSound->setMedia(QUrl("qrc:/music/26.mp3"));
    startSound->stop();
    SaiYa->show();
    this->close();
}
