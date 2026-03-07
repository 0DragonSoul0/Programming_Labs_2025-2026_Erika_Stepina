#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myCar = new Car("Toyota", "Camry", 2020, "A123BC", 15000);

    updateCarInfo();
}

MainWindow::~MainWindow()
{
    delete myCar;
    delete ui;
}

void MainWindow::updateCarInfo()
{
    QString carInfo = QString::fromStdString(myCar->toString());
    ui->myCarInfo->setText(carInfo);
}

void MainWindow::on_addKm_clicked()
{
    QString km = ui->Km->text();

    if(km.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пустое поле ввода километров!");
        return;
    }


    bool validKm;
    int kmChecked = km.toInt(&validKm);
    if(!validKm || kmChecked < 0) {
        QMessageBox::warning(this, "Ошибка", "Некорректно указанное значение километров!");
        return;
    }

    myCar->addMileage(kmChecked);

    updateCarInfo();

}


void MainWindow::on_showGovNum_clicked()
{
    QString govNumber = QString::fromStdString(myCar->getGovNumber());
    ui->govNum->setText(govNumber);
}




