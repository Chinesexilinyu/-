; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLosserDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "吉利.h"

ClassCount=16
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=16
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ERROR2_G1320218
Class4=CLogonDlg
Resource4=IDD_MAINWORK
Class5=CRecordDlg
Resource5=IDD_WINNER_G1320218
Class6=CPlayerDlg
Resource6=IDD_MAIN
Class7=CWorkerDlg
Resource7=IDD_3_PLAYERLOGON
Class8=CError1Dlg
Resource8=IDD_2_LOGON
Class9=CMainDlg
Resource9=IDD_ERROR1_G1320218
Class10=CError2Dlg
Resource10=IDD_GUESSGAME
Class11=CMainWorkDlg
Resource11=IDD_2_RECORD
Class12=CGuessgameDlg
Resource12=IDD_MY_DIALOG
Class13=CMathGameDlg
Resource13=IDD_GAMBLGAME_G1320218
Class14=CGrambleGameDlg
Resource14=IDD_MATHGAME_G1320218
Class15=CWinnerDlg
Resource15=IDD_3_WORKERLOGON
Class16=CLosserDlg
Resource16=IDD_LOSER_G1320218

[CLS:CMyApp]
Type=0
HeaderFile=吉利.h
ImplementationFile=吉利.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=吉利Dlg.h
ImplementationFile=吉利Dlg.cpp
Filter=D
LastObject=CMyDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=吉利Dlg.h
ImplementationFile=吉利Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=3
Control1=IDC_LOGON,button,1342242816
Control2=IDC_RECORD,button,1342242816
Control3=IDC_STATIC,static,1342308865

[DLG:IDD_2_LOGON]
Type=1
Class=CLogonDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_PLAYER,button,1342242816
Control4=IDC_WORKER,button,1342242816

[CLS:CLogonDlg]
Type=0
HeaderFile=LogonDlg.h
ImplementationFile=LogonDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogonDlg
VirtualFilter=dWC

[DLG:IDD_2_RECORD]
Type=1
Class=CRecordDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_BUTTON1,button,1342242816

[CLS:CRecordDlg]
Type=0
HeaderFile=RecordDlg.h
ImplementationFile=RecordDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRecordDlg

[DLG:IDD_3_PLAYERLOGON]
Type=1
Class=CPlayerDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_PASSWORD,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_RIGHT,button,1342242816

[CLS:CPlayerDlg]
Type=0
HeaderFile=PlayerDlg.h
ImplementationFile=PlayerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NAME
VirtualFilter=dWC

[DLG:IDD_3_WORKERLOGON]
Type=1
Class=CWorkerDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PASSWORD,edit,1350631552
Control7=IDC_RIGHT,button,1342242816

[CLS:CWorkerDlg]
Type=0
HeaderFile=WorkerDlg.h
ImplementationFile=WorkerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NAME
VirtualFilter=dWC

[DLG:IDD_ERROR1_G1320218]
Type=1
Class=CError1Dlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308865

[CLS:CError1Dlg]
Type=0
HeaderFile=Error1Dlg.h
ImplementationFile=Error1Dlg.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_MAIN]
Type=1
Class=CMainDlg
ControlCount=7
Control1=IDCANCEL,button,1342242816
Control2=IDC_GUESS,static,1342308865
Control3=IDC_GUESSON,button,1342242816
Control4=IDC_STATIC,static,1342308865
Control5=IDC_MATHON,button,1342242816
Control6=IDC_STATIC,static,1342308865
Control7=IDC_GAMBLE,button,1342242816

[CLS:CMainDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMainDlg

[DLG:IDD_ERROR2_G1320218]
Type=1
Class=CError2Dlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308865

[CLS:CError2Dlg]
Type=0
HeaderFile=Error2Dlg.h
ImplementationFile=Error2Dlg.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_MAINWORK]
Type=1
Class=CMainWorkDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CMainWorkDlg]
Type=0
HeaderFile=MainWorkDlg.h
ImplementationFile=MainWorkDlg.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_GUESSGAME]
Type=1
Class=CGuessgameDlg
ControlCount=2
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342177294

[CLS:CGuessgameDlg]
Type=0
HeaderFile=GuessgameDlg.h
ImplementationFile=GuessgameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CGuessgameDlg
VirtualFilter=dWC

[DLG:IDD_MATHGAME_G1320218]
Type=1
Class=CMathGameDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CMathGameDlg]
Type=0
HeaderFile=MathGameDlg.h
ImplementationFile=MathGameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMathGameDlg

[DLG:IDD_GAMBLGAME_G1320218]
Type=1
Class=CGrambleGameDlg
ControlCount=7
Control1=IDCANCEL,button,1342242816
Control2=IDC_NUM1,edit,1350631552
Control3=IDC_NUM2,edit,1350631552
Control4=IDC_NUM3,edit,1350631552
Control5=IDC_OPERATOR,button,1342308361
Control6=IDC_RADIO2,button,1342177289
Control7=IDC_GOON,button,1342242816

[CLS:CGrambleGameDlg]
Type=0
HeaderFile=GrambleGameDlg.h
ImplementationFile=GrambleGameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CGrambleGameDlg
VirtualFilter=dWC

[DLG:IDD_WINNER_G1320218]
Type=1
Class=CWinnerDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1350701825

[CLS:CWinnerDlg]
Type=0
HeaderFile=WinnerDlg.h
ImplementationFile=WinnerDlg.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_LOSER_G1320218]
Type=1
Class=CLosserDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1350701825

[CLS:CLosserDlg]
Type=0
HeaderFile=LosserDlg.h
ImplementationFile=LosserDlg.cpp
BaseClass=CDialog
Filter=D

