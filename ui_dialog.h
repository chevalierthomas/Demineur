/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTreeWidget *treeWidget;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDial *dial;
    QScrollBar *horizontalScrollBar;
    QKeySequenceEdit *keySequenceEdit;
    QSpinBox *spinBox;
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QCommandLinkButton *commandLinkButton;
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox_2;
    QFrame *frame;
    QWidget *widget;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1079, 951);
        treeWidget = new QTreeWidget(Dialog);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(530, 460, 256, 192));
        timeEdit = new QTimeEdit(Dialog);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(420, 820, 118, 26));
        dateEdit = new QDateEdit(Dialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(420, 790, 110, 26));
        dial = new QDial(Dialog);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(90, 770, 50, 64));
        horizontalScrollBar = new QScrollBar(Dialog);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(120, 870, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        keySequenceEdit = new QKeySequenceEdit(Dialog);
        keySequenceEdit->setObjectName(QString::fromUtf8("keySequenceEdit"));
        keySequenceEdit->setGeometry(QRect(290, 760, 113, 25));
        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 580, 71, 21));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(230, 460, 104, 70));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(350, 170, 127, 80));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 170, 256, 192));
        commandLinkButton = new QCommandLinkButton(Dialog);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(420, 340, 177, 41));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 440, 89, 25));
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(710, 170, 211, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_2);

        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(630, 740, 291, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 181, 71));

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Dialog", "Zinzin", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Dialog", "1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Dialog", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Dialog", "Tab 2", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("Dialog", "CommandLinkButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
