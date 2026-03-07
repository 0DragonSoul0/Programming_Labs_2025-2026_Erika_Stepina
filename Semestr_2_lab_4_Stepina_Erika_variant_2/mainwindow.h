#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "carlib/car.h"

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
    //void updateCarInfo();

private slots:
    void on_addKm_clicked();

    void on_showGovNum_clicked();

private:
    Ui::MainWindow *ui;
    Car* myCar;
    void updateCarInfo();
};
#endif // MAINWINDOW_H
