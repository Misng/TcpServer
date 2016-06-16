#include "socketthread.h"

SocketThread::SocketThread(QObject *parent) :
        QThread(parent)
{
}

//SocketThread::SocketThread(QObject *parent, int socketDescriptor):
//        QThread(parent),m_socketDescriptor(socketDescriptor)
//{
//}
SocketThread::SocketThread(int socketDescriptor):m_socketDescriptor(socketDescriptor)
{
}

void SocketThread::run()
{
        socket = new QTcpSocket();
        if(!socket->setSocketDescriptor(m_socketDescriptor)){
                qDebug()<<socket->errorString();
                return;
        }
        connect(socket,SIGNAL(readyRead()),this,SLOT(readSocket()));
        connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
                this,SLOT(displayErr(QAbstractSocket::SocketError)));
        connect(socket,SIGNAL(disconnected()),socket,SLOT(deleteLater()));
        exec();
}

void SocketThread::readSocket()
{
        QByteArray array = socket->readAll();
//        qDebug()<<array.size()<<array.toHex().toUpper()<<socket->socketDescriptor();
          qDebug()<<array.size()<<array<<socket->socketDescriptor();
        socket->write(array);
}

void SocketThread::displayErr(QAbstractSocket::SocketError errNum)
{
        qDebug()<<errNum<<":"<<socket->errorString()<<socket->socketDescriptor();
        exit(1);
}
