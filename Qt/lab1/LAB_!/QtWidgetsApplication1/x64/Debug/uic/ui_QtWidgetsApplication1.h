/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_6;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName("QtWidgetsApplication1Class");
        QtWidgetsApplication1Class->resize(758, 515);
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName("centralWidget");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(270, 130, 157, 132));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        radioButton = new QRadioButton(widget);
        radioButton->setObjectName("radioButton");

        gridLayout->addWidget(radioButton, 1, 0, 1, 1);

        radioButton_4 = new QRadioButton(widget);
        radioButton_4->setObjectName("radioButton_4");

        gridLayout->addWidget(radioButton_4, 1, 1, 1, 1);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout->addWidget(radioButton_2, 2, 0, 1, 1);

        radioButton_5 = new QRadioButton(widget);
        radioButton_5->setObjectName("radioButton_5");

        gridLayout->addWidget(radioButton_5, 2, 1, 1, 1);

        radioButton_3 = new QRadioButton(widget);
        radioButton_3->setObjectName("radioButton_3");

        gridLayout->addWidget(radioButton_3, 3, 0, 1, 1);

        radioButton_6 = new QRadioButton(widget);
        radioButton_6->setObjectName("radioButton_6");

        gridLayout->addWidget(radioButton_6, 3, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 758, 21));
        QtWidgetsApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName("mainToolBar");
        QtWidgetsApplication1Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName("statusBar");
        QtWidgetsApplication1Class->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplication1Class);
        QObject::connect(pushButton, &QPushButton::clicked, QtWidgetsApplication1Class, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        label->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\320\255\321\202\320\260\320\266", nullptr));
        label_2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\262\320\260\321\200\321\202\320\270\321\200", nullptr));
        radioButton->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "10", nullptr));
        radioButton_4->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "1", nullptr));
        radioButton_2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "12", nullptr));
        radioButton_5->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "2", nullptr));
        radioButton_3->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "13", nullptr));
        radioButton_6->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "3", nullptr));
        pushButton->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
