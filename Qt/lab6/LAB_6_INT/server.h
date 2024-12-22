#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QObject>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void slotReadyRead();
    void SendToClient(const QString& str);

private:
    QVector<QTcpSocket*> Sockets;
};
#endif // SERVER_H
