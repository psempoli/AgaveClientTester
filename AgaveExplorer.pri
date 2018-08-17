include(../AgaveClientInterface/AgaveClientInterface.pri)

INCLUDEPATH += "../AgaveExplorer/"

SOURCES += \
    $$PWD/remoteFileOps/easyboollock.cpp \
    $$PWD/remoteFileOps/joboperator.cpp \
    $$PWD/utilFuncs/agavesetupdriver.cpp \
    $$PWD/utilFuncs/authform.cpp \
    $$PWD/utilFuncs/copyrightdialog.cpp \
    $$PWD/utilFuncs/singlelinedialog.cpp \
    $$PWD/remoteFileOps/joblistnode.cpp \
    $$PWD/ae_globals.cpp \
    $$PWD/remoteModelViews/linkedstandarditem.cpp \
    $$PWD/remoteModelViews/remotejoblister.cpp \
    $$PWD/utilFuncs/fixforssl.cpp \
    $$PWD/SimCenterCommon/FooterWidget.cpp \
    $$PWD/SimCenterCommon/HeaderWidget.cpp

HEADERS += \
    $$PWD/remoteFileOps/easyboollock.h \
    $$PWD/remoteFileOps/joboperator.h \
    $$PWD/utilFuncs/agavesetupdriver.h \
    $$PWD/utilFuncs/authform.h \
    $$PWD/utilFuncs/copyrightdialog.h \
    $$PWD/utilFuncs/singlelinedialog.h \
    $$PWD/remoteFileOps/joblistnode.h \
    $$PWD/ae_globals.h \
    $$PWD/remoteModelViews/linkedstandarditem.h \
    $$PWD/remoteModelViews/remotejoblister.h \
    $$PWD/utilFuncs/fixforssl.h \
    $$PWD/SimCenterCommon/FooterWidget.h \
    $$PWD/SimCenterCommon/HeaderWidget.h

FORMS += \
    $$PWD/utilFuncs/authform.ui \
    $$PWD/utilFuncs/copyrightdialog.ui \
    $$PWD/utilFuncs/singlelinedialog.ui

win32 {
FORMS += \
    $$PWD/utilFuncs/fixforssl.ui
}

RESOURCES += \
    $$PWD/SimCenterCommon/commonResources.qrc \
