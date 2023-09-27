#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);   // signal next_Button clicked will result to up a page on de stackedWidget
}


void MainWindow::on_passwd_lineEdit_textChanged(const QString &arg1)
{
    if (ui->passwd_lineEdit != ui->ret_passwd_lineEdit)
    {

    }
}

