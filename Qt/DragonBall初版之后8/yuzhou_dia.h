#ifndef YUZHOU_DIA_H
#define YUZHOU_DIA_H

#include <QWidget>
#include<background_dialogue.h>

namespace Ui {
class Yuzhou_dia;
}

class Yuzhou_dia : public QWidget
{
    Q_OBJECT

public:
    explicit Yuzhou_dia(QWidget *parent = nullptr);
    ~Yuzhou_dia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Yuzhou_dia *ui;
};

#endif // YUZHOU_DIA_H
