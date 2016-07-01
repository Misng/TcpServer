#include "tcpserver.h"

QMap<int,QByteArray> TcpServer::g_map;

TcpServer::TcpServer(QObject *parent) :
        QTcpServer(parent)
{
}

void TcpServer::incomingConnection(int handle)
{
        SocketThread * thread = new SocketThread(handle);
        connect(thread,SIGNAL(finished()),this,SLOT(threadFinished()));
        thread->start();
        thread->moveToThread(thread);
        qDebug()<<handle;

        connect(thread,SIGNAL(sendData(int,QByteArray)),this,SLOT(recvData(int,QByteArray)));

}

void TcpServer::threadFinished()
{
        qDebug("SocketThread Finished!");
}

void TcpServer::recvData(int socketNum, QByteArray array)
{
    g_map.insert(socketNum,array);
    qDebug()<<g_map;
}
