#ifndef EARTH_DIA_H
#define EARTH_DIA_H

#include <QWidget>
#include<snake.h>

namespace Ui {
class Earth_Dia;
}

class Earth_Dia : public QWidget
{
    Q_OBJECT

public:
    explicit Earth_Dia(QWidget *parent = nullptr);
    ~Earth_Dia();

private slots:
    void on_Change_but_clicked();

    void on_Kaishi_buton_clicked();

private:
    Ui::Earth_Dia *ui;
};

#endif // EARTH_DIA_H
