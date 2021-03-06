#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include "tcpserver.h"

class SocketThread : public QThread
{
        Q_OBJECT
public:
        explicit SocketThread(QObject *parent = 0);
//        SocketThread(QObject *parent,int socketDescriptor);
        SocketThread(int socketDescriptor);
//        ~SocketThread();

        void run();

signals:
        void sendData(int,QByteArray);
public slots:
        void readSocket();
        void displayErr(QAbstractSocket::SocketError);
private:
        int m_socketDescriptor;
        QTcpSocket * socket;

};

#endif // SOCKETTHREAD_H
