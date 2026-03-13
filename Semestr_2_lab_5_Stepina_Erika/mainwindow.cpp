#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::BigIntFromInput(QLineEdit* inp, BigInt& val, QString& errorMessage)
{
    QString text = inp->text();
    if (text.isEmpty()) {
        errorMessage = "Пустой аргумент!";
        return false;
    }

    try {
        val = BigInt(text.toStdString());
        return true;
    }
    catch (const std::exception& e) {
        errorMessage = "Введено нечисловое значение!";
        return false;
    }
}

void MainWindow::on_add_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    BigInt add_result = arg_1 + arg_2;

    std::ostringstream resString;
    resString << add_result;
    ui->add_res->setText(QString::fromStdString(resString.str()));
}


void MainWindow::on_sub_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    BigInt sub_result = arg_1 - arg_2;

    std::ostringstream resString;
    resString << sub_result;
    ui->sub_res->setText(QString::fromStdString(resString.str()));
}


void MainWindow::on_mult_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    BigInt mult_result = arg_1 * arg_2;

    std::ostringstream resString;
    resString << mult_result;
    ui->mult_res->setText(QString::fromStdString(resString.str()));
}


void MainWindow::on_comp_smaller_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    bool comp_smaller_result = arg_1 < arg_2;

    if (comp_smaller_result) {
        ui->smaller_res->setText("True");
    }
    else {
        ui->smaller_res->setText("False");
    }
}


void MainWindow::on_comp_bigger_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    bool comp_bigger_result = arg_1 > arg_2;

    if (comp_bigger_result) {
        ui->bigger_res->setText("True");
    }
    else {
        ui->bigger_res->setText("False");
    }
}


void MainWindow::on_comp_equal_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    bool comp_equal_result = arg_1 == arg_2;

    if (comp_equal_result) {
        ui->equal_res->setText("True");
    }
    else {
        ui->equal_res->setText("False");
    }
}


void MainWindow::on_comp_not_equal_button_clicked()
{
    QString errormes;

    BigInt arg_1, arg_2;

    if (!BigIntFromInput(ui->num_1, arg_1, errormes) ||
        !BigIntFromInput(ui->num_2, arg_2, errormes)) {
        QMessageBox::warning(this, "Ошибка", errormes);
        return;
    }

    bool comp_not_equal_result = arg_1 != arg_2;

    if (comp_not_equal_result) {
        ui->not_equal_res->setText("True");
    }
    else {
        ui->not_equal_res->setText("False");
    }
}

