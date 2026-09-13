#pragma once

#include <QWidget>
#include <fstream>
QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
private slots: 
    void on_load_clicked();
    void on_save_clicked();
};
