#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form;

    connect(this,&MainWindow::signal,form,&Form::slot);
    connect(this,&MainWindow::second_signal,form,&Form::second_slot);
    connect(this,&MainWindow::third_signal,form,&Form::third_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    form->show();
    emit signal(ui->lineEdit->text());
    emit second_signal(ui->lineEdit_2->text());
    emit third_signal(ui->lineEdit_3->text());
}

