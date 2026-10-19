//includes
#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <iostream>
#include <QFile>
#include <string>
#include <QMessageBox>
//set comstractor class
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //setup
    ui->setupUi(this);
}
//set vars
std::string defaultPath = "saves/";
//set delete class
Widget::~Widget()
{
    delete ui;
}
//
const char* getFile(QString name){return (defaultPath + name.toStdString()).c_str();}
//

void Widget::on_load_clicked()
{
    //set filenamee vars
    QString fileName = ui->fileName->text();
    QFile file(fileName);
    //fix if not file is open
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  QMessageBox::critical(this, "Error", "Cannot open or find the specified file.");
    //sread filee
    QTextStream in(&file);
    ui->text->setText(in.readAll());
    file.close();
}

void Widget::on_save_clicked()
{
    //set filenamee vars
    QString fileName = ui->fileName->text();
    QFile file(fileName);
    QString textToWrite = ui->fText->text();
    //fix if not file is open
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))  QMessageBox::critical(this, "Error", "Cannot open or find the specified file.");
    //sread filee
    QTextStream out(&file);
    out << textToWrite;
    file.close();
}
