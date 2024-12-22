#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <second.h>

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

public slots:
    void test();

signals:
    void secondSignal(QString str);
private slots:
    void on_pushButton_clicked();
protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    Ui::MainWindow *ui;

    Second *second;
};
#endif // MAINWINDOW_H
