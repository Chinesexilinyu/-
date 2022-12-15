#include "wuzi_dia.h"
#include "ui_wuzi_dia.h"

Wuzi_dia::Wuzi_dia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuzi_dia)
{
    ui->setupUi(this);
}

Wuzi_dia::~Wuzi_dia()
{
    delete ui;
}

void Wuzi_dia::on_Btn_choose_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%2);
}

void Wuzi_dia::on_Btn_Game_clicked()
{
    chessForm*che=new chessForm;
    che->show();
    this->close();
}
