/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *number1Input;
    QLineEdit *number2Input;
    QPushButton *calculateButton;
    QLabel *resultLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(464, 274);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/C:/Users/HP/Downloads/Calculator.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        number1Input = new QLineEdit(centralwidget);
        number1Input->setObjectName("number1Input");
        number1Input->setGeometry(QRect(190, 90, 108, 24));
        number2Input = new QLineEdit(centralwidget);
        number2Input->setObjectName("number2Input");
        number2Input->setGeometry(QRect(190, 130, 108, 24));
        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName("calculateButton");
        calculateButton->setGeometry(QRect(260, 170, 80, 24));
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(310, 100, 91, 41));
        resultLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 90, 171, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 130, 171, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 50, 271, 51));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 464, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "\321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\321\202 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\262\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270 \321\201\321\216\320\264\320\260 \320\277\320\265\321\200\320\262\320\276\320\265 \321\207\320\270\321\201\320\273\320\276:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270 \321\201\321\216\320\264\320\260 \320\262\321\202\320\276\321\200\320\276\320\265 \321\207\320\270\321\201\320\273\320\276:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\321\202 \320\270\320\264\320\265\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\201\321\203\320\274\320\274\321\213 \321\207\320\270\321\201\320\273\320\265 \320\275\320\260 \320\270\321\205 \321\200\320\260\320\267\320\275\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
