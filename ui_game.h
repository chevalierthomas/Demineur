/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QVBoxLayout *verticalLayout_WholeWindow;
    QScrollArea *gameAreaScroll;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridMines;
    QHBoxLayout *horizontalLayout_Controls;
    QPushButton *change_difficulty;
    QPushButton *restart;
    QSpacerItem *horizontalSpacer;
    QLabel *labelFlagIcon;
    QLabel *flag_count;
    QLabel *labelTimeIcon;
    QLabel *time;

    void setupUi(QDialog *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(391, 120);
        verticalLayout_WholeWindow = new QVBoxLayout(GameWindow);
        verticalLayout_WholeWindow->setObjectName(QString::fromUtf8("verticalLayout_WholeWindow"));
        gameAreaScroll = new QScrollArea(GameWindow);
        gameAreaScroll->setObjectName(QString::fromUtf8("gameAreaScroll"));
        gameAreaScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 371, 68));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridMines = new QGridLayout(scrollAreaWidgetContents);
        gridMines->setObjectName(QString::fromUtf8("gridMines"));
        gameAreaScroll->setWidget(scrollAreaWidgetContents);

        verticalLayout_WholeWindow->addWidget(gameAreaScroll);

        horizontalLayout_Controls = new QHBoxLayout();
        horizontalLayout_Controls->setObjectName(QString::fromUtf8("horizontalLayout_Controls"));
        change_difficulty = new QPushButton(GameWindow);
        change_difficulty->setObjectName(QString::fromUtf8("change_difficulty"));

        horizontalLayout_Controls->addWidget(change_difficulty);

        restart = new QPushButton(GameWindow);
        restart->setObjectName(QString::fromUtf8("restart"));

        horizontalLayout_Controls->addWidget(restart);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Controls->addItem(horizontalSpacer);

        labelFlagIcon = new QLabel(GameWindow);
        labelFlagIcon->setObjectName(QString::fromUtf8("labelFlagIcon"));
        labelFlagIcon->setMinimumSize(QSize(24, 24));
        labelFlagIcon->setMaximumSize(QSize(24, 24));
        labelFlagIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/flag.png")));
        labelFlagIcon->setScaledContents(true);

        horizontalLayout_Controls->addWidget(labelFlagIcon);

        flag_count = new QLabel(GameWindow);
        flag_count->setObjectName(QString::fromUtf8("flag_count"));

        horizontalLayout_Controls->addWidget(flag_count);

        labelTimeIcon = new QLabel(GameWindow);
        labelTimeIcon->setObjectName(QString::fromUtf8("labelTimeIcon"));
        labelTimeIcon->setMinimumSize(QSize(24, 24));
        labelTimeIcon->setMaximumSize(QSize(24, 24));
        labelTimeIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/time.png")));
        labelTimeIcon->setScaledContents(true);

        horizontalLayout_Controls->addWidget(labelTimeIcon);

        time = new QLabel(GameWindow);
        time->setObjectName(QString::fromUtf8("time"));

        horizontalLayout_Controls->addWidget(time);


        verticalLayout_WholeWindow->addLayout(horizontalLayout_Controls);


        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QDialog *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "D\303\251mineur", nullptr));
        change_difficulty->setText(QCoreApplication::translate("GameWindow", "Changer la difficult\303\251", nullptr));
        restart->setText(QCoreApplication::translate("GameWindow", "Recommencer", nullptr));
        flag_count->setText(QCoreApplication::translate("GameWindow", "0/0", nullptr));
        time->setText(QCoreApplication::translate("GameWindow", "00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
