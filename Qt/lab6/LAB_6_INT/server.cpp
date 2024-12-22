#include "server.h"

Server::Server()
{
    if (this->listen(QHostAddress::Any, 2323))
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* socket = new QTcpSocket(this);
    if (socket->setSocketDescriptor(socketDescriptor))
    {
        connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
        connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

        Sockets.push_back(socket);
        qDebug() << "Client connected" << socketDescriptor;
    }
    else
    {
        qDebug() << "Socket error";
        delete socket;
    }
}

void Server::slotReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (socket)
    {
        qDebug() << "Socket ready to read";
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_6_2);
        qDebug() << "Reading data...";
        QString str;
        in >> str;
        qDebug() << "Received data:" << str;
        SendToClient(str);
    }
    else
    {
        qDebug() << "DataStream error";
    }
}


void Server::SendToClient(const QString& str)
{
    QByteArray Data;
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << str;
    for(int i = 0; i < Sockets.size(); i++)
    {
        Sockets[i]->write(Data);
    }
}
