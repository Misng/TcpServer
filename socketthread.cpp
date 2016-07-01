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

        QByteArray array;
        while (TRUE) {
            if(socket->waitForReadyRead()){
                array = socket->readAll();
                qDebug()<<array<<":Read";
                emit sendData(socket->socketDescriptor(),array);
            }else{
                qDebug()<<socket->errorString()<<":Read";
                break;
            }
            usleep(500);
            QMap<int,QByteArray> tmp;
            tmp = TcpServer::g_map;
            if(!TcpServer::g_map.isEmpty()){
                array = TcpServer::g_map.value(socket->socketDescriptor());
                socket->write(array);
                TcpServer::g_map.remove(socket->socketDescriptor());
            }
        }

        socket->deleteLater();


      /*  connect(socket,SIGNAL(readyRead()),this,SLOT(readSocket()));
        connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
                this,SLOT(displayErr(QAbstractSocket::SocketError)));
        connect(socket,SIGNAL(disconnected()),socket,SLOT(deleteLater()));
        exec();*/
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
