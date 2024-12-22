#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
public slots:
    void slot(QString i);
    void second_slot(QString k);
    void third_slot(QString j);
};

#endif // FORM_H
