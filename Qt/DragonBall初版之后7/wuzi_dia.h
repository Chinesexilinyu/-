#ifndef WUZI_DIA_H
#define WUZI_DIA_H

#include <QWidget>
#include<chessform.h>

namespace Ui {
class Wuzi_dia;
}

class Wuzi_dia : public QWidget
{
    Q_OBJECT

public:
    explicit Wuzi_dia(QWidget *parent = nullptr);
    ~Wuzi_dia();

private slots:
    void on_Btn_choose_clicked();

    void on_Btn_Game_clicked();

private:
    Ui::Wuzi_dia *ui;
};

#endif // WUZI_DIA_H
