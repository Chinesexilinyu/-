#include "clabel.h"

CLabel::CLabel(QLabel *parent) : QLabel(parent)
{
    this->setAlignment(Qt::AlignCenter);
    this->setStyleSheet("background-color: white");
}
void CLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}
