#ifndef SAIYAWINNER_H
#define SAIYAWINNER_H

#include <QWidget>

namespace Ui {
class SaiYaWinner;
}

class SaiYaWinner : public QWidget
{
    Q_OBJECT

public:
    explicit SaiYaWinner(QWidget *parent = nullptr);
    ~SaiYaWinner();

private:
    Ui::SaiYaWinner *ui;
};

#endif // SAIYAWINNER_H
