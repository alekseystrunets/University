#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "qevent.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    second = new Second(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(test()));

    connect(this,&MainWindow::secondSignal,second,&Second::secondSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(){
    qDebug() << "Слот тест запущен:";
    emit secondSignal(ui->lineEdit->text());
}

void MainWindow::on_pushButton_clicked(){
    QMessageBox::critical(this,"Критическая ошибка","Блин");

}
void MainWindow::keyPressEvent(QKeyEvent* e) {
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit(); // Закрывает приложение
    }
    QMainWindow::keyPressEvent(e);
}
