/********************************************************************************
** Form generated from reading UI file 'choose_difficulty.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_DIFFICULTY_H
#define UI_CHOOSE_DIFFICULTY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseDifficultyDialog
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *headerLayout;
    QLabel *label;
    QPushButton *soundButton;
    QGridLayout *gridLayout;
    QPushButton *schema_30_16;
    QPushButton *schema_free;
    QPushButton *schema_8_8;
    QPushButton *schema_16_16;
    QPushButton *exitButton;

    void setupUi(QDialog *ChooseDifficultyDialog)
    {
        if (ChooseDifficultyDialog->objectName().isEmpty())
            ChooseDifficultyDialog->setObjectName(QString::fromUtf8("ChooseDifficultyDialog"));
        ChooseDifficultyDialog->resize(1000, 1000);
        ChooseDifficultyDialog->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { background-color: rgb(119, 118, 123); }\n"
""));
        verticalLayoutWidget_2 = new QWidget(ChooseDifficultyDialog);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 981, 981));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 10, 20, 10);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        headerLayout->addWidget(label);

        soundButton = new QPushButton(verticalLayoutWidget_2);
        soundButton->setObjectName(QString::fromUtf8("soundButton"));
        soundButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { max-width: 40px; max-height: 40px; }\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/sound-off.png"), QSize(), QIcon::Normal, QIcon::Off);
        soundButton->setIcon(icon);

        headerLayout->addWidget(soundButton);


        verticalLayout_2->addLayout(headerLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(50);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, 0, -1);
        schema_30_16 = new QPushButton(verticalLayoutWidget_2);
        schema_30_16->setObjectName(QString::fromUtf8("schema_30_16"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(schema_30_16->sizePolicy().hasHeightForWidth());
        schema_30_16->setSizePolicy(sizePolicy);
        schema_30_16->setFont(font);
        schema_30_16->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { background-color: rgb(255, 190, 111); }\n"
""));

        gridLayout->addWidget(schema_30_16, 1, 0, 1, 1);

        schema_free = new QPushButton(verticalLayoutWidget_2);
        schema_free->setObjectName(QString::fromUtf8("schema_free"));
        sizePolicy.setHeightForWidth(schema_free->sizePolicy().hasHeightForWidth());
        schema_free->setSizePolicy(sizePolicy);
        schema_free->setFont(font);
        schema_free->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { background-color: rgb(255, 190, 111); }\n"
""));

        gridLayout->addWidget(schema_free, 1, 1, 1, 1);

        schema_8_8 = new QPushButton(verticalLayoutWidget_2);
        schema_8_8->setObjectName(QString::fromUtf8("schema_8_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(schema_8_8->sizePolicy().hasHeightForWidth());
        schema_8_8->setSizePolicy(sizePolicy1);
        schema_8_8->setMinimumSize(QSize(0, 0));
        schema_8_8->setFont(font);
        schema_8_8->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { background-color: rgb(255, 190, 111); }\n"
""));

        gridLayout->addWidget(schema_8_8, 0, 0, 1, 1);

        schema_16_16 = new QPushButton(verticalLayoutWidget_2);
        schema_16_16->setObjectName(QString::fromUtf8("schema_16_16"));
        sizePolicy.setHeightForWidth(schema_16_16->sizePolicy().hasHeightForWidth());
        schema_16_16->setSizePolicy(sizePolicy);
        schema_16_16->setFont(font);
        schema_16_16->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { background-color: rgb(255, 190, 111); }\n"
""));

        gridLayout->addWidget(schema_16_16, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        exitButton = new QPushButton(verticalLayoutWidget_2);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color:rgb(237, 51, 59); }\n"
""));

        verticalLayout_2->addWidget(exitButton);


        retranslateUi(ChooseDifficultyDialog);

        QMetaObject::connectSlotsByName(ChooseDifficultyDialog);
    } // setupUi

    void retranslateUi(QDialog *ChooseDifficultyDialog)
    {
        ChooseDifficultyDialog->setWindowTitle(QCoreApplication::translate("ChooseDifficultyDialog", "D\303\251mineur", nullptr));
        label->setText(QCoreApplication::translate("ChooseDifficultyDialog", "Bienvenue sur notre d\303\251mineur", nullptr));
        schema_30_16->setText(QCoreApplication::translate("ChooseDifficultyDialog", "30 x 16", nullptr));
        schema_free->setText(QCoreApplication::translate("ChooseDifficultyDialog", "Personnaliser", nullptr));
        schema_8_8->setText(QCoreApplication::translate("ChooseDifficultyDialog", "8 x 8", nullptr));
        schema_16_16->setText(QCoreApplication::translate("ChooseDifficultyDialog", "16 x 16", nullptr));
        exitButton->setText(QCoreApplication::translate("ChooseDifficultyDialog", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseDifficultyDialog: public Ui_ChooseDifficultyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_DIFFICULTY_H
