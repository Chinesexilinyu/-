#include "yuzhou_dia.h"
#include "ui_yuzhou_dia.h"

Yuzhou_dia::Yuzhou_dia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yuzhou_dia)
{
    ui->setupUi(this);
}

Yuzhou_dia::~Yuzhou_dia()
{
    delete ui;
}

void Yuzhou_dia::on_pushButton_clicked()
{
    Background_Dialogue*back2=new Background_Dialogue;
    back2->show();
    this->close();
}
