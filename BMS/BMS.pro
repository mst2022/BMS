QT       += core gui sql
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbus.cpp \
    addmovie.cpp \
    adminDashboard.cpp \
    bookbus.cpp \
    bookmovie.cpp \
    bus.cpp \
    busticketlist.cpp \
    changepassword.cpp \
    dashBoard.cpp \
    database.cpp \
    displaybus.cpp \
    displaymovie.cpp \
    editprofile.cpp \
    loadmoney.cpp \
    loginscreen.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    mybookings.cpp \
    myprofile.cpp \
    registerscreen.cpp \
    updateBookedBus.cpp \
    user.cpp \
    window.cpp

HEADERS += \
    bus.h \
    busticketlist.h \
    database.h \
    mainwindow.h \
    movie.h \
    user.h \
    window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32: LIBS += -L$$PWD/'../New folder/mysql-connector-c-6.1.11-winx64/lib/' -llibmysql

#INCLUDEPATH += $$PWD/'../New folder/mysql-connector-c-6.1.11-winx64/include'
#DEPENDPATH += $$PWD/'../New folder/mysql-connector-c-6.1.11-winx64/include'

RESOURCES += \
    resource.qrc

