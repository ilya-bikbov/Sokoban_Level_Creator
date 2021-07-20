QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# Copies the given files to the destination directory
defineTest(copyToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$DESTDIR

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graphicsitem.cpp \
    graphicsitemgroup.cpp \
    graphicsscene.cpp \
    graphicsview.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    graphicsitem.h \
    graphicsitemgroup.h \
    graphicsscene.h \
    graphicsview.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    res/res.qrc

OBJECTS_DIR = .obj
MOC_DIR     = .moc
DESTDIR     = bin
CONFIG(debug, debug|release) {
    DESTDIR =  $$PWD/$$DESTDIR
}
CONFIG(release, debug|release) {
    DESTDIR = $$PWD/$$DESTDIR

}
win32 {
    copyToDestdir(libs_win32/*)
}

