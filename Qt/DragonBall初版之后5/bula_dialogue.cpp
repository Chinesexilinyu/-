#include "bula_dialogue.h"
#include "ui_bula_dialogue.h"

Bula_Dialogue::Bula_Dialogue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bula_Dialogue)
{
    ui->setupUi(this);
}

Bula_Dialogue::~Bula_Dialogue()
{
    delete ui;
}

void Bula_Dialogue::on_GoBack_Button_clicked()
{
    Background_Dialogue*Back=new Background_Dialogue;
    Back->show();
    this->close();
}
