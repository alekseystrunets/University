#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);

    if(ui->radioButton->isChecked()){
        ui->label->setStyleSheet("image: url(:/new/images/222.png);");
        ui->label_2->setText("15");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    ui->label->setStyleSheet("image: url(:/new/images/222.png);");
    ui->label_2->setText("15");
}


void MainWindow::on_radioButton_2_clicked(bool checked)
{
    ui->label->setStyleSheet("image: url(:/new/images/111.png);");
    ui->label_2->setText("10");
}

