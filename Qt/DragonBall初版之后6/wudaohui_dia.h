#ifndef WUDAOHUI_DIA_H
#define WUDAOHUI_DIA_H

#include <QWidget>

namespace Ui {
class Wudaohui_dia;
}

class Wudaohui_dia : public QWidget
{
    Q_OBJECT

public:
    explicit Wudaohui_dia(QWidget *parent = nullptr);
    ~Wudaohui_dia();

private:
    Ui::Wudaohui_dia *ui;
};

#endif // WUDAOHUI_DIA_H
