#include "saiya_dialogue.h"
#include "ui_saiya_dialogue.h"

SaiYa_Dialogue::SaiYa_Dialogue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaiYa_Dialogue)
{
    ui->setupUi(this);
}

SaiYa_Dialogue::~SaiYa_Dialogue()
{
    delete ui;
}

void SaiYa_Dialogue::on_PageOn_Button_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%2);
}
