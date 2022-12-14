#ifndef BACKGROUND_DIALOGUE_H
#define BACKGROUND_DIALOGUE_H

#include <QWidget>
#include<renwu_dialogue.h>

namespace Ui {
class Background_Dialogue;
}

class Background_Dialogue : public QWidget
{
    Q_OBJECT

public:
    explicit Background_Dialogue(QWidget *parent = nullptr);
    ~Background_Dialogue();

private slots:
    void on_Choose_button_clicked();

    void on_Hero_button_clicked();

private:
    Ui::Background_Dialogue *ui;
};

#endif // BACKGROUND_DIALOGUE_H
