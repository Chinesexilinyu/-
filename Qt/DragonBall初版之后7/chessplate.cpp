#include "chessplate.h"

chessPlate::chessPlate(QWidget *parent) : QWidget(parent)
{
    Init();
}
chessPlate::~chessPlate()
{
}

void chessPlate::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //画背景
    QRect rect(QPoint(0,0),QSize(this->width(),this->height()));
    QPixmap pix(bgFileName);
    painter.drawPixmap(rect,pix);
//    QPixmap pix2("://image/33.jpg");
//    painter.drawPixmap(QPoint(100,30),pix2);

    //画线
    QPen pen;
    pen.setColor(lineColor);
    pen.setStyle(lineStyle);
    pen.setWidth(lineWidth);
    painter.setPen(pen);

    for (int i = 0;i<15 ;i++ ) {
        //画线
        painter.drawLine(startX,startY+i*gridHeight,startX+14*gridWidth,startY+i*gridHeight);//x
        painter.drawLine(startX+i*gridWidth,startY,startX+i*gridWidth,startY+14*gridHeight);//y

    }
    //画上四个圆点
    QBrush brs;
    brs.setColor(Qt::black);
    brs.setStyle(Qt::SolidPattern);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setBrush(brs);
    painter.drawEllipse(QPoint(4*gridWidth,4*gridHeight),6,6);
    painter.drawEllipse(QPoint(12*gridWidth,4*gridHeight),6,6);
    painter.drawEllipse(QPoint(8*gridWidth,8*gridHeight),6,6);
    painter.drawEllipse(QPoint(12*gridWidth,12*gridHeight),6,6);
    painter.drawEllipse(QPoint(4*gridWidth,12*gridHeight),6,6);
    painter.setPen(pen);

    //落子展示
    QString chessFilename;
    for (int i= 0;i<15 ;i++ ) {
        for (int j = 0;j<15 ;j++ ) {
            if(chessData[i][j]==White){
                chessFilename = "://image/32.jpg";
            }
            else if(chessData[i][j]==Black){
                chessFilename = "://image/33.jpg";
            }
            else
            {
                chessFilename.clear();
                continue;
            }
            painter.drawPixmap(startX/2+i*gridWidth,startY/2+j*gridHeight,gridWidth,gridHeight,QPixmap(chessFilename));
        }
    }
}
void chessPlate::resizeEvent(QResizeEvent *event)
{
    this->gridWidth = event->size().width()/GRIDCOUNT;
    this->gridHeight = event->size().height()/GRIDCOUNT;
    startX = gridWidth;
    startY = gridHeight;
}
void chessPlate::mousePressEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();
    //x
    if(x>=startX/2 &&(x<=startX/2+15*gridWidth)){
        //y
        if(y>=startY/2&&(y<=startY/2+15*gridHeight))
        {
            //得出当前坐标属于哪个格子 格子与实际格子并未对应，是因为，把他放在对角线上
            int i = 0,j =0;
            i = (x-startX/2)/gridWidth;
            j = (y-startY/2)/gridHeight;
//            chessData[i][j]=Black;
//            this->update();
            mousePosSend(i,j);
        }
    }
}
void chessPlate::Init()
{
    //初始化函数:设置成员变量初始值（默认值）;设置界面的标题与图标等初始状态


    bgFileName.clear();
    bgFileName = "://image/21.jpg";
    lineColor = Qt::black;
    lineStyle = Qt::SolidLine;
    lineWidth = 3;

    for (int i=0;i<15 ;i++ ) {
        for (int j = 0;j<15 ;j++ ) {
            chessData[i][j]=Empty;
        }
    }
//    chessData[3][3] = White;
//    chessData[4][4] = Black;

}

void chessPlate::setBackGroundPic(const QString filename)
{
    this->bgFileName = filename;
    this->update();
}
void chessPlate::setPlateLine(const QColor color, const Qt::PenStyle style, const int width)
{
    this->lineColor = color;
    this->lineStyle = style;
    this->lineWidth = width;
    this->update();
}
void chessPlate::setChessStatus(void *p)
{
    memcpy(chessData,p,sizeof(int)*15*15);
    this->update();
}
