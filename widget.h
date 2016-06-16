#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tcpserver.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
        Q_OBJECT
        
public:
        explicit Widget(QWidget *parent = 0);
        ~Widget();
        
private slots:
        void on_pushButton_listen_clicked();

private:
        Ui::Widget *ui;
        TcpServer * server;
};

#endif // WIDGET_H
