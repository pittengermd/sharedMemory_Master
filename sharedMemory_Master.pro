TEMPLATE = app
CONFIG += console
CONFIG += c++latest
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += /usr/local/include/boost

unix:!macx: LIBS += -L$$PWD/../../../../Development/lib/ -lsharedmemoryd -lrt -lpthread -lm

INCLUDEPATH += $$PWD/../../../../Development/include
DEPENDPATH += $$PWD/../../../../Development/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../Development/lib/libsharedmemoryd.a -lpthread -lm
