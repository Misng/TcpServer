#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
        ui->setupUi(this);
        connect(ui->pushButton_quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

Widget::~Widget()
{
        delete ui;
}

void Widget::on_pushButton_listen_clicked()
{
        ui->pushButton_listen->setEnabled(false);
        server = new TcpServer();
        if(!server->listen(QHostAddress("10.1.37.10"),58007)){
                qDebug()<<server->errorString();
                return;
        }
        qDebug()<<server->serverAddress().toString()<<server->serverPort();
}
