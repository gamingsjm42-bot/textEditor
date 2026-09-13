//includes
#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <iostream>
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
    
    const int maxSizeFile = 999999999;
    //set f variabel
    FILE * f = NULL;
    //set file var
    char * fileVar =(char*)malloc(maxSizeFile*sizeof(char)) ; 
    //set load
    f=  fopen( ui->fileName->text().toStdString().c_str(),"r");
    //set error 
    if(f ==NULL) QMessageBox::critical(this,"Error","no sush file");
    //set fileVar
    //set text editor
    //ui->text->setText(fileVar);
    //fix memorey
    free(fileVar);
}

void Widget::on_save_clicked()
{
    //set file variable
    FILE * f =  NULL;
    //open file
    f = fopen(ui->fileName->text().toStdString().c_str(),"w+");
    //set file print
    fprintf(f,ui->fText->text().toStdString().c_str());
    //close file 
    fclose(f);
}