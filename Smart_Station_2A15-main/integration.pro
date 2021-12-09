QT       += gui sql multimedia multimediawidgets printsupport charts serialport svg
QT       +=core network
QT       += core gui

#QT       += core websockets
QT += dbus widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    metro.cpp \
    chat.cpp \
    client.cpp \
    connection.cpp \
    exportexcelobject.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    popup.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    smtp.cpp \
    station.cpp \
    ticket.cpp \
    trajet.cpp

HEADERS += \
    metro.h \
    chat.h \
    client.h \
    connection.h \
    exportexcelobject.h \
    mainwindow.h \
    personnel.h \
    popup.h \
    qcustomplot.h \
    qrcode.h \
    smtp.h \
    station.h \
    ticket.h \
    trajet.h

FORMS += \
    chatmainwindow.ui \
    chatsetnickname.ui \
    mainwindow.ui \
    popup.ui

DBUS_ADAPTORS += org.example.chat.xml
DBUS_INTERFACES += org.example.chat.xml

# install
target.path = $$[QT_INSTALL_EXAMPLES]/dbus/chat
INSTALLS += target
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QT +=core gui sql printsupport multimedia
QT +=widgets multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DISTFILES += \
    org.example.chat.xml
