#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
    if (!socket->waitForConnected(3000)) {
        ui->textBrowser->append("Connection failed");
    }
}

void MainWindow::SendToServer(const QString &str) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    QString messageWithTime = "" + QDateTime::currentDateTime().toString("HH:mm:ss") + " " + str;
    out << messageWithTime;

    socket->write(data);
    ui->lineEdit->clear();
}


void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        QString str;
        in.startTransaction();
        in >> str;
        if (!in.commitTransaction()) {
            ui->textBrowser->append("read error");
            return;
        }
        ui->textBrowser->append(str);
    }
    else
    {
        ui->textBrowser->append("read error");
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
}

void MainWindow::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
}
