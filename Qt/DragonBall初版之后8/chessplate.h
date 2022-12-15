#ifndef CHESSPLATE_H
#define CHESSPLATE_H

#include <QWidget>
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>
#include <QMouseEvent>
#define  GRIDCOUNT   16

class chessPlate : public QWidget
{
    Q_OBJECT
public:
    explicit chessPlate(QWidget *parent = nullptr);
    ~chessPlate();

        enum ChessType{Empty=0,White,Black};
        //提供修改背景图片的方法
        void setBackGroundPic(const QString filename);
        //修改棋盘线风格
        void setPlateLine(const QColor color,const Qt::PenStyle style,const int width);
        //刷新棋盘
        void setChessStatus(void *p);
protected:
        void paintEvent(QPaintEvent *);
        void resizeEvent(QResizeEvent *);
        void mousePressEvent(QMouseEvent *);
private:
        QString bgFileName;
        QColor lineColor;
        Qt::PenStyle lineStyle;
        int lineWidth;
        //格子宽高，画线起始点
        int gridWidth, gridHeight,startX,startY;
        int chessData[15][15];
        void Init();
signals:
        void mousePosSend(int i,int j);
};

#endif // CHESSPLATE_H
