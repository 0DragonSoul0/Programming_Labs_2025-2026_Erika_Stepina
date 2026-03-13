#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "bigintlib/bigint.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool BigIntFromInput(QLineEdit* inp, BigInt& val, QString& errorMessage);

private slots:
    void on_add_button_clicked();

    void on_sub_button_clicked();

    void on_mult_button_clicked();

    void on_comp_smaller_button_clicked();

    void on_comp_bigger_button_clicked();

    void on_comp_equal_button_clicked();

    void on_comp_not_equal_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
