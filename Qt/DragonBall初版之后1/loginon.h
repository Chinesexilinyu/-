#ifndef LOGINON_H
#define LOGINON_H

#include <QWidget>
#include<background_dialogue.h>
namespace Ui {
class LoginOn;
}

class LoginOn : public QWidget
{
    Q_OBJECT

public:
    explicit LoginOn(QWidget *parent = nullptr);
    ~LoginOn();

private slots:
    void on_LogOn_clicked();

    void on_User_shuru_textChanged(const QString &arg1);

private:
    Ui::LoginOn *ui;
    Background_Dialogue*bb;
};

#endif // LOGINON_H
