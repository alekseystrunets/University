#ifndef SECOND_H
#define SECOND_H

#include <QObject>

class Second : public QObject
{
    Q_OBJECT
public:
    explicit Second(QObject *parent = nullptr);

signals:

public slots:
    void secondSlot(QString str);
};

#endif // SECOND_H
