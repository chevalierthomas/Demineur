QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemineurApp
TEMPLATE = app

SOURCES += main.cpp \
           DifficultySelectionDialog.cpp \
           CustomDifficultyDialog.cpp \
           GameWindow.cpp

HEADERS  += DifficultySelectionDialog.h \
            CustomDifficultyDialog.h \
            GameWindow.h

FORMS    += choose_difficulty.ui \
            free_difficulty.ui \
            game.ui

STATECHARTS +=

RESOURCES += \
    resources.qrc

