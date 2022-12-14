#ifndef SAIYA_DIALOGUE_H
#define SAIYA_DIALOGUE_H

#include <QWidget>

namespace Ui {
class SaiYa_Dialogue;
}

class SaiYa_Dialogue : public QWidget
{
    Q_OBJECT

public:
    explicit SaiYa_Dialogue(QWidget *parent = nullptr);
    ~SaiYa_Dialogue();

private slots:
    void on_PageOn_Button_clicked();

private:
    Ui::SaiYa_Dialogue *ui;
};

#endif // SAIYA_DIALOGUE_H
