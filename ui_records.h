/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RecordsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *scoresTable;
    QHBoxLayout *buttonLayout;
    QPushButton *clearButton;
    QPushButton *returnButton;

    void setupUi(QDialog *RecordsDialog)
    {
        if (RecordsDialog->objectName().isEmpty())
            RecordsDialog->setObjectName(QString::fromUtf8("RecordsDialog"));
        RecordsDialog->resize(440, 488);
        RecordsDialog->setBaseSize(QSize(440, 490));
        verticalLayout = new QVBoxLayout(RecordsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(RecordsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        scoresTable = new QTableWidget(RecordsDialog);
        if (scoresTable->columnCount() < 4)
            scoresTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        scoresTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        scoresTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        scoresTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        scoresTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        scoresTable->setObjectName(QString::fromUtf8("scoresTable"));
        scoresTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(scoresTable);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        clearButton = new QPushButton(RecordsDialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 87, 34); color: white; }"));

        buttonLayout->addWidget(clearButton);

        returnButton = new QPushButton(RecordsDialog);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: red; color: white; }"));

        buttonLayout->addWidget(returnButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(RecordsDialog);

        QMetaObject::connectSlotsByName(RecordsDialog);
    } // setupUi

    void retranslateUi(QDialog *RecordsDialog)
    {
        RecordsDialog->setWindowTitle(QCoreApplication::translate("RecordsDialog", "Records", nullptr));
        label->setText(QCoreApplication::translate("RecordsDialog", "Scores", nullptr));
        QTableWidgetItem *___qtablewidgetitem = scoresTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RecordsDialog", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = scoresTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RecordsDialog", "Temps", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = scoresTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RecordsDialog", "Hauteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = scoresTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("RecordsDialog", "Largeur", nullptr));
        scoresTable->setProperty("horizontalHeader", QVariant(QStringList()
            << QCoreApplication::translate("RecordsDialog", "Name", nullptr)
            << QCoreApplication::translate("RecordsDialog", "Time", nullptr)
            << QCoreApplication::translate("RecordsDialog", "Height", nullptr)
            << QCoreApplication::translate("RecordsDialog", "Width", nullptr)));
        clearButton->setText(QCoreApplication::translate("RecordsDialog", "Clear", nullptr));
        returnButton->setText(QCoreApplication::translate("RecordsDialog", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordsDialog: public Ui_RecordsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
