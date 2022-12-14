#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *startSound=new QMediaPlayer;  //创建一个音乐播放器
    startSound->setMedia(QUrl("qrc:/music/26.mp3"));
    startSound->setVolume(80);  //音量
    startSound->play();
    a=new LoginOn;
    a->show();
    this->close();
}
