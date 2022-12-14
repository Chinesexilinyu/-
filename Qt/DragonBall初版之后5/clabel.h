#ifndef CLABEL_H
#define CLABEL_H

#include <QObject>
#include<QLabel>
#include<QMouseEvent>
class CLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CLabel(QLabel *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent*event);
signals:
    void clicked();
public slots:
};

#endif // CLABEL_H
