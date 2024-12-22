#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./test_new.db");
    if(db.open()){
        qDebug("open");
    }
    else {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query -> exec("CREATE TABLE Polindrom(FirstWord TEXT, Polindrom TEXT);");
    model = new QSqlTableModel(this,db);
    model->setTable("Polindrom");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked(){
    model->insertRow(model->rowCount());
}
void MainWindow::on_pushButton_2_clicked(){
    model->removeRow(row);
}
void MainWindow::on_tableView_clicked(const QModelIndex &index){
    row=index.row();
}
