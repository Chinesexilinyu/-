# Microsoft Developer Studio Project File - Name="����" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=���� - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "����.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "����.mak" CFG="���� - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "���� - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "���� - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "���� - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "���� - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "���� - Win32 Release"
# Name "���� - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "PlayerDlg.cpp()"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\Error1Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Error2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GambleRuleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GrambleGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GuessgameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GuessRuleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LogonDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LosserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainWorkDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Math24_WrongDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MathGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MathgameRuleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NoWinnerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Password_InconsistentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\REGISTER_TO_MAINDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\WinnerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkerDlg.cpp
# End Source File
# Begin Source File

SOURCE=".\����.cpp"
# End Source File
# Begin Source File

SOURCE=".\����.rc"
# End Source File
# Begin Source File

SOURCE=".\����Dlg.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Error1Dlg.h
# End Source File
# Begin Source File

SOURCE=.\Error2Dlg.h
# End Source File
# Begin Source File

SOURCE=.\GambleRuleDlg.h
# End Source File
# Begin Source File

SOURCE=.\GrambleGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\GuessgameDlg.h
# End Source File
# Begin Source File

SOURCE=.\GuessRuleDlg.h
# End Source File
# Begin Source File

SOURCE=.\LogonDlg.h
# End Source File
# Begin Source File

SOURCE=.\LosserDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainWorkDlg.h
# End Source File
# Begin Source File

SOURCE=.\Math24_WrongDlg.h
# End Source File
# Begin Source File

SOURCE=.\MathGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\MathgameRuleDlg.h
# End Source File
# Begin Source File

SOURCE=.\NoWinnerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Password_InconsistentDlg.h
# End Source File
# Begin Source File

SOURCE=.\PlayerDlg.h
# End Source File
# Begin Source File

SOURCE=.\RecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\REGISTER_TO_MAINDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\WinnerDlg.h
# End Source File
# Begin Source File

SOURCE=.\WorkerDlg.h
# End Source File
# Begin Source File

SOURCE=".\����.h"
# End Source File
# Begin Source File

SOURCE=".\����Dlg.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\����.ico"
# End Source File
# Begin Source File

SOURCE=".\res\����.rc2"
# End Source File
# Begin Source File

SOURCE=".\res\����ʯͷ��.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=".\res\Taiky - �й��ϻ���bgm�������˾�ϯ���ܣ������� ����.wav"
# End Source File
# Begin Source File

SOURCE=".\res\Yeegoo,���� - �b.wav"
# End Source File
# Begin Source File

SOURCE=".\res\�������� - Ҷ��.wav"
# End Source File
# Begin Source File

SOURCE=".\res\��ΰ�� - ͵��.wav"
# End Source File
# Begin Source File

SOURCE=".\res\��ΰ�� - ѩǧѰ.wav"
# End Source File
# Begin Source File

SOURCE=".\res\�հ��� - �ƹ���.wav"
# End Source File
# Begin Source File

SOURCE=".\res\¬��͢ - ـ��.wav"
# End Source File
# Begin Source File

SOURCE=".\res\ȴ.wav"
# End Source File
# Begin Source File

SOURCE=".\res\Ⱥ�� - ���ϴ�ѧУ��.wav"
# End Source File
# Begin Source File

SOURCE=".\res\����,�ķ���,�Ϻ��������� - С��������.wav"
# End Source File
# Begin Source File

SOURCE=".\res\�������� - ��ɽ�۽�--�����.wav"
# End Source File
# End Target
# End Project
