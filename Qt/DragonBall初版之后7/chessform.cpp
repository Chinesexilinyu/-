#include "chessform.h"
#include "ui_chessform.h"
#include<QMediaPlayer>

chessForm::chessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessForm)
{
    ui->setupUi(this);
    Init();//初始化主界面
    //    this->setWindowIcon(QIcon(":/res/中文.png"));
    connect(ui->openGameBtn,&QPushButton::clicked,this,&chessForm::doProcessStartGame);
    connect(ui->exitBtn,&QPushButton::clicked,this,&chessForm::doProcessExitGame);
}

chessForm::~chessForm()
{
    delete ui;
}
void chessForm::paintEvent(QPaintEvent *)
{
    //绘制主界面背景
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap("://image/21.jpg"));
}

void chessForm::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","是否退出",QMessageBox::Yes,QMessageBox::No))
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
void chessForm::Init()
{
    //申请棋盘类空间
    myPlate = new chessPlate();
    //把棋盘放在主界面的容器中
    ui->gridLayout->addWidget(myPlate);
    //设置标题字
    //添加争先选择部件
    QStringList list;
    list.clear();
    list.append("白子先");
    list.append("黑子先");
    ui->comboBox->addItems(list);
    //显示白棋、黑棋行走标识
    showRole("://image/32.jpg","://image/33.jpg");
}

void chessForm::showRole(const QString whiteFileName, const QString blackFileName)
{
    ui->whiteLab->setPixmap(QPixmap(whiteFileName));
    ui->whiteLab->setScaledContents(true);
    ui->blackLab->setPixmap(QPixmap(blackFileName));
    ui->blackLab->setScaledContents(true);
}
void chessForm::setRole(chessPlate::ChessType Role)
{
    currentRole = Role;
    if(Role == chessPlate::Black)
    {
        ui->blackLab->setVisible(true);
        ui->whiteLab->setVisible(false);
    }
    else
    {
        ui->blackLab->setVisible(false);
        ui->whiteLab->setVisible(true);
    }
}
void chessForm::setChessInit()
{
    for (int i=0;i<15 ;i++ ) {
        for (int j = 0;j<15 ;j++ ) {
            formChessData[i][j]=chessPlate::Empty;
        }
    }
    myPlate->setChessStatus(formChessData);
    white_cnt=0;
    black_cnt=0;
    ui->lcdNumBlack->display(black_cnt);
    ui->lcdNumWhite->display(white_cnt);
}
bool chessForm::isGot(int i, int j)
{
    //扫面方式决定了，这种判断方式
    chessPlate::ChessType a;
    a= chessPlate::ChessType(formChessData[i][j]);
    if(i>10)//向右判断
    {
        //不向右判断
    }
    else
    {
        qDebug()<<"111111";
        if(formChessData[i+1][j]==a&&formChessData[i+2][j]==a&&formChessData[i+3][j]==a&&formChessData[i+4][j]==a)
        {return true;}
    }
    if(j>10)//向下判断
    {
        //不向下判断
    }
    else
    {
        if(formChessData[i][j+1]==a&&formChessData[i][j+2]==a&&formChessData[i][j+3]==a&&formChessData[i][j+4]==a)
        {return true;}
    }
    if(j>10||i>10)//向斜下判断
    {
        //不向斜下判断
    }
    else
    {
        if(formChessData[i+1][j+1]==a&&formChessData[i+2][j+2]==a&&formChessData[i+3][j+3]==a&&formChessData[i+4][j+4]==a)
        {return true;}
    }
    if(j<4||i>10)
    {
        //不向斜上判断
    }
    else
    {
        if(formChessData[i+1][j-1]==a&&formChessData[i+2][j-2]==a&&formChessData[i+3][j-3]==a&&formChessData[i+4][j-4]==a)
        {return true;}
    }
    return false;
}
void chessForm::doProcessStartGame()
{



    //界面初始化
    if(ui->comboBox->currentText().contains("白"))
    {
        setRole(chessPlate::White);
    }
    else
    {
        setRole(chessPlate::Black);
    }
    //棋盘初始化
    setChessInit();
    //可以开始下棋，连接信号槽
    connect(myPlate,&chessPlate::mousePosSend,this,&chessForm::doProcessFrushPlate);

}
void chessForm::doProcessExitGame()
{
    Bula_Dialogue*bula=new Bula_Dialogue;
    this->close();
    bula->show();
}
void chessForm::doProcessFrushPlate(int p, int q)
{

    if(formChessData[p][q]==chessPlate::Empty)
    {
        //可以下子 下哪一个子
        if(currentRole==chessPlate::Black)
        {
            formChessData[p][q]=chessPlate::Black;
            black_cnt++;
            currentRole = chessPlate::White;
        }
        else
        {
            formChessData[p][q] = chessPlate::White;
            white_cnt++;
            currentRole = chessPlate::Black;
        }

        myPlate->setChessStatus(formChessData);

        ui->lcdNumBlack->display(black_cnt);
        ui->lcdNumWhite->display(white_cnt);
         //判断是否胜利
        int i=0,j=0;
        for (i=0;i<15 ;i++ ) {
            for (j=0;j<15 ;j++ ) {
                if(formChessData[i][j]==0)
                {}
                else
                {
                    if(isGot(i,j))//这个棋子是否构成成功棋形判断函数
                    {break;}
               }
            }
            if(j!=15)
            {break;}

        }
        if((i!=15)&&formChessData[p][q] == chessPlate::White)
        {
            QMessageBox::information(this,"提示","恭喜白棋胜利！",QMessageBox::Ok);
            setChessInit();
            showRole("://image/32.jpg","://image/33.jpg");
            disconnect(myPlate,&chessPlate::mousePosSend,this,&chessForm::doProcessFrushPlate);
        }
        else if((i!=15)&&formChessData[p][q] == chessPlate::Black)
        {
           QMessageBox::information(this,"提示","恭喜黑棋胜利！",QMessageBox::Ok);
           setChessInit();
           showRole("://image/32.jpg","://image/33.jpg");
           disconnect(myPlate,&chessPlate::mousePosSend,this,&chessForm::doProcessFrushPlate);
        }
        else
        {}
    }
    else
    {}
}

void chessForm::on_pushButton_4_clicked()
{
    QMediaPlayer *startSound=new QMediaPlayer;  //创建一个音乐播放器
    startSound->setMedia(QUrl("qrc:/music/18.mp3"));
    startSound->setVolume(80);  //音量
    startSound->play();
}

void chessForm::on_pushButton_3_clicked()
{
    Yuzhou_dia*yuzhou=new Yuzhou_dia;
    yuzhou->show();
    this->close();
}
