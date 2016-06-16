#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) :
        QTcpServer(parent)
{
}

void TcpServer::incomingConnection(int handle)
{
       /* socket = new QTcpSocket();
        if(!socket->setSocketDescriptor(handle)){
                qDebug()<<socket->errorString();
                return;
        }
        connect(socket,SIGNAL(readyRead()),this,SLOT(readSocket()));
        connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
                this,SLOT(displayErr(QAbstractSocket::SocketError)));*/
        SocketThread * thread = new SocketThread(handle);
        connect(thread,SIGNAL(finished()),this,SLOT(threadFinished()));
        thread->start();
        thread->moveToThread(thread);
}
/*
void TcpServer::readSocket()
{
        QByteArray array = socket->readAll();
        qDebug()<<array.size()<<array.toHex().toUpper();
        qDebug()<<array.size()<<array;
        socket->write(array);
}

void TcpServer::displayErr(QAbstractSocket::SocketError errNum)
{
        qDebug()<<errNum<<":"<<socket->errorString();
}*/

void TcpServer::threadFinished()
{
        qDebug("SocketThread Finished!");
}
