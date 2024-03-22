/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridMines;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *flag_count;
    QLabel *label_3;
    QLabel *time;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QPushButton *change_difficulty;
    QPushButton *restart;

    void setupUi(QDialog *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(1320, 1099);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWindow->sizePolicy().hasHeightForWidth());
        GameWindow->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(GameWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1051, 1081));
        gridMines = new QGridLayout(layoutWidget);
        gridMines->setSpacing(0);
        gridMines->setObjectName(QString::fromUtf8("gridMines"));
        gridMines->setSizeConstraint(QLayout::SetNoConstraint);
        gridMines->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(GameWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1070, 10, 241, 1081));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        flag_count = new QLabel(verticalLayoutWidget);
        flag_count->setObjectName(QString::fromUtf8("flag_count"));

        gridLayout->addWidget(flag_count, 0, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        time = new QLabel(verticalLayoutWidget);
        time->setObjectName(QString::fromUtf8("time"));

        gridLayout->addWidget(time, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        change_difficulty = new QPushButton(verticalLayoutWidget);
        change_difficulty->setObjectName(QString::fromUtf8("change_difficulty"));

        verticalLayout->addWidget(change_difficulty);

        restart = new QPushButton(verticalLayoutWidget);
        restart->setObjectName(QString::fromUtf8("restart"));

        verticalLayout->addWidget(restart);


        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QDialog *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "D\303\251mineur", nullptr));
        flag_count->setText(QString());
        label_3->setText(QCoreApplication::translate("GameWindow", "<html>\n"
"<head/>\n"
"<body>\n"
"<p><img src=\":/images/time.png\" width=\"40\"/></p>\n"
"</body>\n"
"</html>\n"
"", nullptr));
        time->setText(QString());
        label->setText(QCoreApplication::translate("GameWindow", "<html>\n"
"<head/>\n"
"<body>\n"
"<p><img src=\":/images/flag.png\" width=\"40\" height=\"40\"/></p>\n"
"</body>\n"
"</html>\n"
"", nullptr));
        change_difficulty->setText(QCoreApplication::translate("GameWindow", "Changer la difficult\303\251", nullptr));
        restart->setText(QCoreApplication::translate("GameWindow", "Recommencer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
