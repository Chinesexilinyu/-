#ifndef BULA_DIALOGUE_H
#define BULA_DIALOGUE_H

#include <QWidget>
#include<background_dialogue.h>

namespace Ui {
class Bula_Dialogue;
}

class Bula_Dialogue : public QWidget
{
    Q_OBJECT

public:
    explicit Bula_Dialogue(QWidget *parent = nullptr);
    ~Bula_Dialogue();

private slots:
    void on_GoBack_Button_clicked();

private:
    Ui::Bula_Dialogue *ui;
};

#endif // BULA_DIALOGUE_H
