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
    QLabel *enter_nums;
    QLineEdit *num_2;
    QLineEdit *num_1;
    QPushButton *add_button;
    QPushButton *sub_button;
    QPushButton *mult_button;
    QPushButton *comp_smaller_button;
    QPushButton *comp_bigger_button;
    QPushButton *comp_equal_button;
    QPushButton *comp_not_equal_button;
    QLabel *opt;
    QLineEdit *add_res;
    QLineEdit *sub_res;
    QLineEdit *mult_res;
    QLineEdit *smaller_res;
    QLineEdit *bigger_res;
    QLineEdit *equal_res;
    QLineEdit *not_equal_res;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        enter_nums = new QLabel(centralwidget);
        enter_nums->setObjectName("enter_nums");
        enter_nums->setGeometry(QRect(50, 30, 211, 21));
        QFont font;
        font.setPointSize(14);
        enter_nums->setFont(font);
        enter_nums->setFrameShape(QFrame::Shape::NoFrame);
        num_2 = new QLineEdit(centralwidget);
        num_2->setObjectName("num_2");
        num_2->setGeometry(QRect(380, 30, 113, 21));
        num_1 = new QLineEdit(centralwidget);
        num_1->setObjectName("num_1");
        num_1->setGeometry(QRect(240, 30, 113, 21));
        add_button = new QPushButton(centralwidget);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(60, 120, 75, 24));
        add_button->setFont(font);
        sub_button = new QPushButton(centralwidget);
        sub_button->setObjectName("sub_button");
        sub_button->setGeometry(QRect(60, 180, 75, 24));
        sub_button->setFont(font);
        mult_button = new QPushButton(centralwidget);
        mult_button->setObjectName("mult_button");
        mult_button->setGeometry(QRect(60, 240, 75, 24));
        mult_button->setFont(font);
        comp_smaller_button = new QPushButton(centralwidget);
        comp_smaller_button->setObjectName("comp_smaller_button");
        comp_smaller_button->setGeometry(QRect(60, 300, 75, 24));
        comp_smaller_button->setFont(font);
        comp_bigger_button = new QPushButton(centralwidget);
        comp_bigger_button->setObjectName("comp_bigger_button");
        comp_bigger_button->setGeometry(QRect(60, 360, 75, 24));
        comp_bigger_button->setFont(font);
        comp_equal_button = new QPushButton(centralwidget);
        comp_equal_button->setObjectName("comp_equal_button");
        comp_equal_button->setGeometry(QRect(60, 420, 75, 24));
        comp_equal_button->setFont(font);
        comp_not_equal_button = new QPushButton(centralwidget);
        comp_not_equal_button->setObjectName("comp_not_equal_button");
        comp_not_equal_button->setGeometry(QRect(60, 480, 75, 24));
        comp_not_equal_button->setFont(font);
        opt = new QLabel(centralwidget);
        opt->setObjectName("opt");
        opt->setGeometry(QRect(50, 70, 191, 21));
        opt->setFont(font);
        add_res = new QLineEdit(centralwidget);
        add_res->setObjectName("add_res");
        add_res->setGeometry(QRect(180, 120, 113, 22));
        sub_res = new QLineEdit(centralwidget);
        sub_res->setObjectName("sub_res");
        sub_res->setGeometry(QRect(180, 180, 113, 22));
        mult_res = new QLineEdit(centralwidget);
        mult_res->setObjectName("mult_res");
        mult_res->setGeometry(QRect(180, 240, 113, 22));
        smaller_res = new QLineEdit(centralwidget);
        smaller_res->setObjectName("smaller_res");
        smaller_res->setGeometry(QRect(180, 300, 113, 22));
        bigger_res = new QLineEdit(centralwidget);
        bigger_res->setObjectName("bigger_res");
        bigger_res->setGeometry(QRect(180, 360, 113, 22));
        equal_res = new QLineEdit(centralwidget);
        equal_res->setObjectName("equal_res");
        equal_res->setGeometry(QRect(180, 420, 113, 22));
        not_equal_res = new QLineEdit(centralwidget);
        not_equal_res->setObjectName("not_equal_res");
        not_equal_res->setGeometry(QRect(180, 480, 113, 22));
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
        enter_nums->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\262\320\260 \321\207\320\270\321\201\320\273\320\260:", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        sub_button->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        mult_button->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        comp_smaller_button->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        comp_bigger_button->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        comp_equal_button->setText(QCoreApplication::translate("MainWindow", "==", nullptr));
        comp_not_equal_button->setText(QCoreApplication::translate("MainWindow", "!=", nullptr));
        opt->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
