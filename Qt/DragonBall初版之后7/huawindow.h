#ifndef HUAWINDOW_H
#define HUAWINDOW_H

#include <QWidget>
#include<clabel.h>
#include<QGridLayout>
#include<saiyawinner.h>

namespace Ui {
class HuaWindow;
}

class HuaWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HuaWindow(QWidget *parent = nullptr);
    ~HuaWindow();
    void initial();
    void unInitial();
private:
    Ui::HuaWindow *ui;
    CLabel *            m_curNullLab;       //当前空值标签
    CLabel *            m_curClickLab;      //当前点击标签
    QVector<CLabel *>   m_unuseLabVector;   //当前还未使用的标签容器
    QGridLayout *       m_layout;           //网格布局器
public slots:
    void labelUpdate();
private slots:
    void on_pushButton_clicked();
};

#endif // HUAWINDOW_H
