QT += core gui widgets
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemineurApp
TEMPLATE = app

SOURCES += main.cpp \
           DifficultySelectionDialog.cpp \
           CustomDifficultyDialog.cpp \
           GameWindow.cpp \
           RecordsDialog.cpp \
           ScoreManager.cpp

HEADERS  += DifficultySelectionDialog.h \
            CustomDifficultyDialog.h \
            GameWindow.h \
            RecordsDialog.h \
            ScoreManager.h

FORMS    += choose_difficulty.ui \
            free_difficulty.ui \
            game.ui \
            records.ui

STATECHARTS +=

RESOURCES += \
    resources.qrc

