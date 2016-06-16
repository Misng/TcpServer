#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QTcpServer
{
        Q_OBJECT
public:
        explicit TcpServer(QObject *parent = 0);

        void incomingConnection(int handle);
signals:
        
public slots:
        void readSocket();
        void displayErr(QAbstractSocket::SocketError);
private:
        QTcpSocket * socket;
};

#endif // TCPSERVER_H
