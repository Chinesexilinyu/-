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
