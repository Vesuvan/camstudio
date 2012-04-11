; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPlayplusView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "playplus.h"
LastPage=0

ClassCount=6
Class1=CMainFrame
Class2=CPlayplusApp
Class3=CAboutDlg
Class4=CPlayplusDoc
Class5=CPlayplusView
Class6=CSlideToolBar

ResourceCount=5
Resource1=IDR_PLAYERTOOLBAR
Resource2=IDD_ABOUTBOX
Resource3=IDD_AUDIODIALOG
Resource4=IDR_MENUPLAYER
Resource5=IDR_MAINFRAME

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

[CLS:CPlayplusApp]
Type=0
BaseClass=CWinApp
HeaderFile=playplus.h
ImplementationFile=playplus.cpp
LastObject=CPlayplusApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=playplus.cpp
ImplementationFile=playplus.cpp
LastObject=CAboutDlg
Filter=D
VirtualFilter=dWC

[CLS:CPlayplusDoc]
Type=0
BaseClass=CDocument
HeaderFile=playplusDoc.h
ImplementationFile=playplusDoc.cpp
LastObject=CPlayplusDoc

[CLS:CPlayplusView]
Type=0
BaseClass=CView
HeaderFile=playplusView.h
ImplementationFile=playplusView.cpp
LastObject=ID_FILE_PLAY
Filter=C
VirtualFilter=VWC

[CLS:CSlideToolBar]
Type=0
BaseClass=CToolBar
HeaderFile=SlideToolBar.h
ImplementationFile=SlideToolBar.cpp
LastObject=CSlideToolBar

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_IMAGE,static,1342177294
Control2=IDC_TITLE,static,1342177281
Control3=IDC_STATIC,static,1342177281
Control4=IDC_STATIC,static,1342177281
Control5=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=CPlayplusView
Command1=ID_FILE_PLAY
Command2=ID_FILE_STOP
Command3=ID_FILE_REWIND
Command4=ID_FILE_LASTFRAME
Command5=ID_BUTTON32785
Command6=ID_BUTTON32784
Command7=ID_BUTTON32786
Command8=ID_BUTTON32787
Command9=ID_BUTTON32788
Command10=ID_BUTTON32789
Command11=ID_BUTTON32790
Command12=ID_BUTTON32791
Command13=ID_BUTTON32792
Command14=ID_BUTTON32793
Command15=ID_BUTTON32794
Command16=ID_BUTTON32795
Command17=ID_BUTTON32796
Command18=ID_BUTTON32797
Command19=ID_BUTTON32798
Command20=ID_BUTTON32799
Command21=ID_BUTTON32800
Command22=ID_BUTTON32801
Command23=ID_BUTTON32802
Command24=ID_BUTTON32803
CommandCount=24

[MNU:IDR_MAINFRAME]
Type=1
Class=CPlayplusView
Command1=ID_FILE_OPEN
Command2=ID_FILE_CLOSE
Command3=ID_FILE_SAVEAS
Command4=ID_APP_EXIT
Command5=ID_AUDIO_REMOVEEXISTINGAUDIOTRACKS
Command6=ID_AUDIO_ADDAUDIOFROMWAVEFILE
Command7=ID_AUDIO_AUDIOOPTIONS
Command8=ID_AUDIO_EXTENSION
Command9=ID_FILE_PLAY
Command10=ID_FILE_STOP
Command11=ID_FILE_REWIND
Command12=ID_FILE_LASTFRAME
Command13=ID_ZOOM_QUARTER
Command14=ID_ZOOM_HALF
Command15=ID_ZOOM_1
Command16=ID_ZOOM_2
Command17=ID_ZOOM_4
Command18=ID_ZOOM_RESIZETOMOVIESIZE
Command19=ID_ZOOM_TESTAUDIO
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_AUDIODIALOG]
Type=1
Class=?
ControlCount=16
Control1=IDC_RECORDFORMAT,combobox,1344339970
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_CHOOSE,button,1342242816
Control5=IDC_COMPRESSEDFORMATTAG,edit,1350633600
Control6=IDC_COMPRESSEDFORMAT,edit,1350633600
Control7=IDC_IFACTOR,edit,1350639744
Control8=IDC_INTERLEAVE,button,1342242819
Control9=IDC_STATIC,button,1342177287
Control10=IDVOLUME,button,1342242817
Control11=IDOK,button,1342242817
Control12=IDCANCEL,button,1342242816
Control13=IDC_INPUTDEVICE,combobox,1344339970
Control14=IDC_STATIC,button,1342177287
Control15=IDC_INTERLEAVEFRAMES,button,1342177289
Control16=IDC_INTERLEAVESECONDS,button,1342177289

[MNU:IDR_MENUPLAYER]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_CLOSE
Command3=ID_APP_EXIT
Command4=ID_FILE_PLAY
Command5=ID_FILE_STOP
Command6=ID_FILE_REWIND
Command7=ID_FILE_LASTFRAME
Command8=ID_ZOOM_QUARTER
Command9=ID_ZOOM_HALF
Command10=ID_ZOOM_1
Command11=ID_ZOOM_2
Command12=ID_ZOOM_4
Command13=ID_ZOOM_RESIZETOMOVIESIZE
Command14=ID_APP_ABOUT
CommandCount=14

[TB:IDR_PLAYERTOOLBAR]
Type=1
Class=?
Command1=ID_FILE_PLAY
Command2=ID_FILE_STOP
Command3=ID_FILE_REWIND
Command4=ID_FILE_LASTFRAME
Command5=ID_BUTTON32784
Command6=ID_BUTTON32826
Command7=ID_BUTTON32827
Command8=ID_BUTTON32828
Command9=ID_BUTTON32829
Command10=ID_BUTTON32830
Command11=ID_BUTTON32831
Command12=ID_BUTTON32832
Command13=ID_BUTTON32833
Command14=ID_BUTTON32834
Command15=ID_BUTTON32835
Command16=ID_BUTTON32836
Command17=ID_BUTTON32837
Command18=ID_BUTTON32838
Command19=ID_BUTTON32839
Command20=ID_BUTTON32840
Command21=ID_BUTTON32841
CommandCount=21
