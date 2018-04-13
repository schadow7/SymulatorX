TARGET = SymulatorX
QT += core gui
QT += charts
QT +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    mainwindow.h \
    simulator.h \
    simulationtab.h \
    configurationtab.h \
    controlloop.h \
    objectdiscrete.h \
    objectsiso.h \
    polymonial.h \
    observer.h \
    subject.h \
    chart.h  \
    qcustomplot.h \
    regulator.h \
    generator.h \
    regulatorpid.h \
    genrect.h \
    gensin.h \
    gentriang.h \
    genrand.h

SOURCES += \
    mainwindow.cpp \
    main.cpp \
    simulator.cpp \
    simulationtab.cpp \
    configurationtab.cpp \
    controlloop.cpp \
    objectdiscrete.cpp \
    polymonial.cpp \
    observer.cpp \
    subject.cpp \
    chart.cpp \
    qcustomplot.cpp \
    generator.cpp \
    regulatorpid.cpp \
    regulator.cpp \
    genrect.cpp \
    gensin.cpp \
    gentriang.cpp \
    genrand.cpp


RESOURCES += \
    resources.qrc

DISTFILES +=

RC_FILE = SymulatorX.rc
