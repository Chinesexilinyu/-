#include "wudaohui_dia.h"
#include "ui_wudaohui_dia.h"

Wudaohui_dia::Wudaohui_dia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wudaohui_dia)
{
    ui->setupUi(this);
}

Wudaohui_dia::~Wudaohui_dia()
{
    delete ui;
}
