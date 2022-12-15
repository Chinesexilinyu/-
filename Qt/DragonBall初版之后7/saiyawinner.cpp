#include "saiyawinner.h"
#include "ui_saiyawinner.h"
#include<QMediaPlayer>

SaiYaWinner::SaiYaWinner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaiYaWinner)
{
    ui->setupUi(this);

}

SaiYaWinner::~SaiYaWinner()
{
    delete ui;
}

void SaiYaWinner::on_Page_Button_clicked()
{
    static int i;
    ui->stackedWidget->setCurrentIndex(++i%2);
}
QMediaPlayer *startSound=new QMediaPlayer;  //创建一个音乐播放器

void SaiYaWinner::on_pushButton_clicked()
{
    startSound->setMedia(QUrl("qrc:/music/16.mp3"));
    startSound->setVolume(100);  //音量
    startSound->play();
}

void SaiYaWinner::on_pushButton_3_clicked()
{
    startSound->stop();
    Background_Dialogue*Backg=new Background_Dialogue;
    Backg->show();
    this->close();
}

void SaiYaWinner::on_pushButton_2_clicked()
{
    QApplication*app;
    app->exit(0);
}
