/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QFrame *x_axis;
    QFrame *y_axis;
    QPushButton *pushButtonCopy;
    QPushButton *pushButtonPaste;
    QLabel *label;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonSave;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spinBoxTabSize;
    QCheckBox *checkBoxIndentation;
    QPushButton *pushButtonFind;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(999, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        pushButtonCopy = new QPushButton(centralWidget);
        pushButtonCopy->setObjectName(QString::fromUtf8("pushButtonCopy"));
        pushButtonCopy->setGeometry(QRect(710, 170, 61, 31));
        pushButtonPaste = new QPushButton(centralWidget);
        pushButtonPaste->setObjectName(QString::fromUtf8("pushButtonPaste"));
        pushButtonPaste->setGeometry(QRect(780, 170, 61, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(790, 10, 121, 21));
        pushButtonNew = new QPushButton(centralWidget);
        pushButtonNew->setObjectName(QString::fromUtf8("pushButtonNew"));
        pushButtonNew->setGeometry(QRect(710, 40, 61, 31));
        pushButtonOpen = new QPushButton(centralWidget);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(780, 40, 61, 31));
        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(850, 40, 61, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(780, 140, 151, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(710, 210, 61, 21));
        spinBoxTabSize = new QSpinBox(centralWidget);
        spinBoxTabSize->setObjectName(QString::fromUtf8("spinBoxTabSize"));
        spinBoxTabSize->setGeometry(QRect(780, 210, 41, 21));
        checkBoxIndentation = new QCheckBox(centralWidget);
        checkBoxIndentation->setObjectName(QString::fromUtf8("checkBoxIndentation"));
        checkBoxIndentation->setGeometry(QRect(840, 210, 161, 21));
        pushButtonFind = new QPushButton(centralWidget);
        pushButtonFind->setObjectName(QString::fromUtf8("pushButtonFind"));
        pushButtonFind->setGeometry(QRect(850, 170, 61, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        pushButtonCopy->setText(QCoreApplication::translate("MainWindow", "COPY", nullptr));
        pushButtonPaste->setText(QCoreApplication::translate("MainWindow", "PASTE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "FILE OPERATIONS", nullptr));
        pushButtonNew->setText(QCoreApplication::translate("MainWindow", "NEW", nullptr));
        pushButtonOpen->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "EDITING OPERATIONS", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tab Size:", nullptr));
        checkBoxIndentation->setText(QCoreApplication::translate("MainWindow", "Maintain Indentation", nullptr));
        pushButtonFind->setText(QCoreApplication::translate("MainWindow", "FIND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
