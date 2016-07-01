#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "socketthread.h"

class TcpServer : public QTcpServer
{
        Q_OBJECT
public:
        explicit TcpServer(QObject *parent = 0);

        void incomingConnection(int handle);
signals:
        
public slots:
        void threadFinished();
        void recvData(int socketNum,QByteArray array);
public:
        static QMap<int,QByteArray> g_map;
};

#endif // TCPSERVER_H
