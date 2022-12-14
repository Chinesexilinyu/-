#include "background_dialogue.h"
#include "ui_background_dialogue.h"

Background_Dialogue::Background_Dialogue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Background_Dialogue)
{
    ui->setupUi(this);
}

Background_Dialogue::~Background_Dialogue()
{
    delete ui;
}

void Background_Dialogue::on_Choose_button_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%2);
}

void Background_Dialogue::on_Hero_button_clicked()
{
    Renwu_Dialogue*Go=new Renwu_Dialogue;
    Go->show();
    this->close();
}
