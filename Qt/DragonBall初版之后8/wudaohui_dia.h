#ifndef WUDAOHUI_DIA_H
#define WUDAOHUI_DIA_H

#include <QWidget>
#include<background_dialogue.h>

namespace Ui {
class Wudaohui_dia;
}

class Wudaohui_dia : public QWidget
{
    Q_OBJECT

public:
    explicit Wudaohui_dia(QWidget *parent = nullptr);
    ~Wudaohui_dia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Wudaohui_dia *ui;
};

#endif // WUDAOHUI_DIA_H
