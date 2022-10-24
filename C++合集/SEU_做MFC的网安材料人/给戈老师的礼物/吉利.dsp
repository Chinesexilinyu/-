# Microsoft Developer Studio Project File - Name="吉利" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=吉利 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "吉利.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "吉利.mak" CFG="吉利 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "吉利 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "吉利 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "吉利 - Win32 Release"

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

!ELSEIF  "$(CFG)" == "吉利 - Win32 Debug"

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

# Name "吉利 - Win32 Release"
# Name "吉利 - Win32 Debug"
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

SOURCE=".\吉利.cpp"
# End Source File
# Begin Source File

SOURCE=".\吉利.rc"
# End Source File
# Begin Source File

SOURCE=".\吉利Dlg.cpp"
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

SOURCE=".\吉利.h"
# End Source File
# Begin Source File

SOURCE=".\吉利Dlg.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\吉利.ico"
# End Source File
# Begin Source File

SOURCE=".\res\吉利.rc2"
# End Source File
# Begin Source File

SOURCE=".\res\剪刀石头布.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=".\res\Taiky - 中国合伙人bgm（三个人酒席吵架）（翻自 金培达）.wav"
# End Source File
# Begin Source File

SOURCE=".\res\Yeegoo,柯雨 - 俠.wav"
# End Source File
# Begin Source File

SOURCE=".\res\川井憲次 - 叶问.wav"
# End Source File
# Begin Source File

SOURCE=".\res\胡伟立 - 偷功.wav"
# End Source File
# Begin Source File

SOURCE=".\res\胡伟立 - 雪千寻.wav"
# End Source File
# Begin Source File

SOURCE=".\res\空白名 - 云宫音.wav"
# End Source File
# Begin Source File

SOURCE=".\res\卢冠廷 - 賭神.wav"
# End Source File
# Begin Source File

SOURCE=".\res\却.wav"
# End Source File
# Begin Source File

SOURCE=".\res\群星 - 东南大学校歌.wav"
# End Source File
# Begin Source File

SOURCE=".\res\商易,夏飞云,上海民族乐团 - 小刀会序曲.wav"
# End Source File
# Begin Source File

SOURCE=".\res\武聆音雄 - 华山论剑--欢快版.wav"
# End Source File
# End Target
# End Project
