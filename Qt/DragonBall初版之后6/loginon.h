#ifndef LOGINON_H
#define LOGINON_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include<background_dialogue.h>
#include <QStyle>
//数据库连接
#include <QtSql/QSqlQuery>//数据库操作函数
#include <QtSql/QSqlError>//输出错误信息
#include <QSettings>//读写配置文件
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

private:
    Ui::LoginOn *ui;

};

#endif // LOGINON_H
