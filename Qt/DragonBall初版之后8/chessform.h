#ifndef CHESSFORM_H
#define CHESSFORM_H

#include <QWidget>
#include "chessplate.h"
#include <QMessageBox>
#include<bula_dialogue.h>
#include<yuzhou_dia.h>

namespace Ui {
class chessForm;
}

class chessForm : public QWidget
{
    Q_OBJECT

public:
    explicit chessForm(QWidget *parent = nullptr);
    ~chessForm();
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *);
private:
    Ui::chessForm *ui;
    chessPlate * myPlate;
        chessPlate::ChessType currentRole;
        int formChessData[15][15];
        int black_cnt = 0,white_cnt = 0;
        void Init();
        void showRole(const QString whiteFileName,const QString blackFileName);
        void setRole(chessPlate::ChessType currentRole);//设置谁先下
        void setChessInit();
        bool isGot(int i,int j);
    public slots:
        void doProcessStartGame();
        void doProcessExitGame();
        void doProcessFrushPlate(int p,int q );
private slots:
        void on_pushButton_4_clicked();
        void on_pushButton_3_clicked();
};

#endif // CHESSFORM_H
