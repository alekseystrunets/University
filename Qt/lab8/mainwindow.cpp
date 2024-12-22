#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QPixmap bkgnd(":/new/img/C:/Users/STRunec/Pictures/Screenshots/photo_2024-11-24_21-07-12.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(bkgnd));
    this->setPalette(palette);

    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::onCalculateButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onCalculateButtonClicked() {
    double num1 = ui->number1Input->text().toDouble();
    double num2 = ui->number2Input->text().toDouble();
    surprise.setNumbers(num1, num2);

    try {
        double result = surprise.check();
        ui->resultLabel->setText(QString::number(result));
    } catch (const std::runtime_error &e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}
