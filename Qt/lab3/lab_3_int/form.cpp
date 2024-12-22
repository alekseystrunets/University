#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::slot(QString i){
    ui->label_4->setText(i);
}
void Form::second_slot(QString k){
    ui->label_5->setText(k);
}
void Form::third_slot(QString j){
    ui->label_6->setText(j);
}

