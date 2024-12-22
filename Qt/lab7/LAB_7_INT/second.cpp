#include "second.h"
#include <QDebug>

Second::Second(QObject *parent)
    : QObject{parent}
{}

void Second::secondSlot(QString str){
    qDebug() << "Переданная строка" << str;
}
