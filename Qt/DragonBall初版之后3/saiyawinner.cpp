#include "saiyawinner.h"
#include "ui_saiyawinner.h"

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
