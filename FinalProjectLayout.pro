QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    database.cpp \
    doctorview.cpp \
    main.cpp \
    Login.cpp \
    newuser.cpp \
    nurseview.cpp \
    resetpassword.cpp

HEADERS += \
    Login.h \
    adminwindow.h \
    database.h \
    doctorview.h \
    newuser.h \
    nurseview.h \
    resetpassword.h

FORMS += \
    Login.ui \
    adminwindow.ui \
    doctorview.ui \
    newuser.ui \
    nurseview.ui \
    resetpassword.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
