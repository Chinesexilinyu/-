#ifndef RENWU_DIALOGUE_H
#define RENWU_DIALOGUE_H

#include <QWidget>
#include<background_dialogue.h>
#include<saiya_dialogue.h>
#include<earth_dia.h>
namespace Ui {
class Renwu_Dialogue;
}

class Renwu_Dialogue : public QWidget
{
    Q_OBJECT

public:
    explicit Renwu_Dialogue(QWidget *parent = nullptr);
    ~Renwu_Dialogue();

private slots:
    void on_Choose_Button_clicked();

    void on_Fan_Button_clicked();

    void on_SaiYa_Button_clicked();

    void on_Earth_Button_clicked();

private:
    Ui::Renwu_Dialogue *ui;
};

#endif // RENWU_DIALOGUE_H
