/********************************************************************************
** Form generated from reading UI file 'free_difficulty.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREE_DIFFICULTY_H
#define UI_FREE_DIFFICULTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomDifficultyDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *hauteur_input;
    QLineEdit *largeur_input;
    QLabel *label_4;
    QLineEdit *pourcentage_input;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *validateButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CustomDifficultyDialog)
    {
        if (CustomDifficultyDialog->objectName().isEmpty())
            CustomDifficultyDialog->setObjectName(QString::fromUtf8("CustomDifficultyDialog"));
        CustomDifficultyDialog->resize(717, 288);
        verticalLayoutWidget = new QWidget(CustomDifficultyDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 701, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 10, 50, 10);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        hauteur_input = new QLineEdit(verticalLayoutWidget);
        hauteur_input->setObjectName(QString::fromUtf8("hauteur_input"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hauteur_input->sizePolicy().hasHeightForWidth());
        hauteur_input->setSizePolicy(sizePolicy);

        gridLayout->addWidget(hauteur_input, 1, 1, 1, 1);

        largeur_input = new QLineEdit(verticalLayoutWidget);
        largeur_input->setObjectName(QString::fromUtf8("largeur_input"));
        largeur_input->setEnabled(true);
        sizePolicy.setHeightForWidth(largeur_input->sizePolicy().hasHeightForWidth());
        largeur_input->setSizePolicy(sizePolicy);
        largeur_input->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(largeur_input, 0, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        pourcentage_input = new QLineEdit(verticalLayoutWidget);
        pourcentage_input->setObjectName(QString::fromUtf8("pourcentage_input"));
        sizePolicy.setHeightForWidth(pourcentage_input->sizePolicy().hasHeightForWidth());
        pourcentage_input->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pourcentage_input, 2, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        validateButton = new QPushButton(verticalLayoutWidget);
        validateButton->setObjectName(QString::fromUtf8("validateButton"));
        validateButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton { background-color: rgb(87, 227, 137); }\n"
""));

        horizontalLayout_2->addWidget(validateButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color:rgb(237, 51, 59); }\n"
""));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(CustomDifficultyDialog);

        QMetaObject::connectSlotsByName(CustomDifficultyDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomDifficultyDialog)
    {
        CustomDifficultyDialog->setWindowTitle(QCoreApplication::translate("CustomDifficultyDialog", "D\303\251mineur", nullptr));
        label->setText(QCoreApplication::translate("CustomDifficultyDialog", "Personnaliser", nullptr));
        label_2->setText(QCoreApplication::translate("CustomDifficultyDialog", "Largeur", nullptr));
        largeur_input->setText(QString());
        label_4->setText(QCoreApplication::translate("CustomDifficultyDialog", "Pourcentage de Mine", nullptr));
        label_3->setText(QCoreApplication::translate("CustomDifficultyDialog", "Hauteur", nullptr));
        validateButton->setText(QCoreApplication::translate("CustomDifficultyDialog", "D\303\251mmarer le jeu", nullptr));
        cancelButton->setText(QCoreApplication::translate("CustomDifficultyDialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomDifficultyDialog: public Ui_CustomDifficultyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREE_DIFFICULTY_H