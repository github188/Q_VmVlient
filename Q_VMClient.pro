CONFIG += warnon
QT += qml quick sql


TEMPLATE = app
VERSION = 1.1.0
TARGET = vmtest



UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
DESTDIR = build/bin

INCLUDEPATH+=src \
             src/vmc \
             src/sql \
			 
			 
LIBS += -Llibs


SOURCES += \
    main.cpp \
    src/mainwindow.cpp \
    src/vmc/vmcmainflow.cpp \
    src/mainobject.cpp \
    src/sql/vmsql.cpp \
    src/sql/productobject.cpp

DISTFILES += \
    qml/main.qml \
    qml/VMFaultPage.qml \
    qml/Button.qml \
    qml/Product.qml \
    qml/VMStatusbar.qml \
    qml/VMTitlebar.qml \
    qml/VMPayPage.qml \
    qml/VMTransactionPage.qml \
    qml/VMAdsPage.qml \
    qml/VMGoodsListPage.qml \
    qml/VMWidget.qml \
    qml/VMTradeWidget.qml

HEADERS += \
    src/mainwindow.h \
    src/vmc/vmcmainflow.h \
    src/vmc/EVprotocol.h \
    src/mainobject.h \
    src/sql/vmsql.h \
    src/sql/productobject.h
