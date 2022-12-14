#ifndef SAIYAWINNER_H
#define SAIYAWINNER_H

#include <QWidget>
#include<background_dialogue.h>
namespace Ui {
class SaiYaWinner;
}

class SaiYaWinner : public QWidget
{
    Q_OBJECT

public:
    explicit SaiYaWinner(QWidget *parent = nullptr);
    ~SaiYaWinner();

private slots:
    void on_Page_Button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SaiYaWinner *ui;
};

#endif // SAIYAWINNER_H
