 #include "widget.h"
#include "ui_widget.h"
#include <QProcess>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->btn_start,&QPushButton::clicked,[this]()
    {
        QString appPath = qApp->applicationDirPath() + "/SubApp";
        QMessageBox::information(this,"appPath",appPath);
       // bool result = QProcess::startDetached(appPath);

        QProcess *process = new QProcess(this);
        process->start(appPath);

        //QMessageBox::information(this,"QProcess",result + QString::number(result));
    });
}

Widget::~Widget()
{
    delete ui;
}
