#include "earth_dia.h"
#include "ui_earth_dia.h"

Earth_Dia::Earth_Dia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Earth_Dia)
{
    ui->setupUi(this);
}

Earth_Dia::~Earth_Dia()
{
    delete ui;
}

void Earth_Dia::on_Change_but_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%2);
}

void Earth_Dia::on_Kaishi_buton_clicked()
{
    snake*sna=new snake;
    sna->show();
    this->close();
}
