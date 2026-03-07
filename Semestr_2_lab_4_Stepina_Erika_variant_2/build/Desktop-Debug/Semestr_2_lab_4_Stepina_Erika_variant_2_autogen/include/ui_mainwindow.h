/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
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
    QPushButton *addKm;
    QLineEdit *Km;
    QPushButton *showGovNum;
    QLineEdit *govNum;
    QLabel *myCarInfo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addKm = new QPushButton(centralwidget);
        addKm->setObjectName("addKm");
        addKm->setGeometry(QRect(60, 170, 111, 24));
        Km = new QLineEdit(centralwidget);
        Km->setObjectName("Km");
        Km->setGeometry(QRect(60, 130, 113, 22));
        showGovNum = new QPushButton(centralwidget);
        showGovNum->setObjectName("showGovNum");
        showGovNum->setGeometry(QRect(610, 130, 131, 24));
        govNum = new QLineEdit(centralwidget);
        govNum->setObjectName("govNum");
        govNum->setGeometry(QRect(620, 170, 113, 22));
        myCarInfo = new QLabel(centralwidget);
        myCarInfo->setObjectName("myCarInfo");
        myCarInfo->setGeometry(QRect(70, 30, 661, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        addKm->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\276\320\261\320\265\320\263", nullptr));
        showGovNum->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\320\276\321\201.\320\275\320\276\320\274\320\265\321\200", nullptr));
        myCarInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
