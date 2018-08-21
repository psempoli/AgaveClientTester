include($$PWD/../AgaveClientInterface/AgaveClientInterface.pri)

INCLUDEPATH += "$$PWD/"

SOURCES += \
    $$PWD/utilFuncs/agavesetupdriver.cpp \
    $$PWD/utilFuncs/authform.cpp \
    $$PWD/utilFuncs/copyrightdialog.cpp \
    $$PWD/utilFuncs/singlelinedialog.cpp \
    $$PWD/utilFuncs/fixforssl.cpp \
    $$PWD/ae_globals.cpp \   
    $$PWD/SimCenterCommon/FooterWidget.cpp \
    $$PWD/SimCenterCommon/HeaderWidget.cpp

HEADERS += \
    $$PWD/utilFuncs/agavesetupdriver.h \
    $$PWD/utilFuncs/authform.h \
    $$PWD/utilFuncs/copyrightdialog.h \
    $$PWD/utilFuncs/singlelinedialog.h \
    $$PWD/utilFuncs/fixforssl.h \
    $$PWD/ae_globals.h \
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
