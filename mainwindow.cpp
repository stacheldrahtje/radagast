#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);

    QObject::connect (ui->nextButton1, &QPushButton::clicked, this, &MainWindow::nextButton1_clicked); // this connect works!
    QObject::connect (ui->backButton1, &QPushButton::clicked, this, &MainWindow::backButton1_clicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::nextButton1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);   // signal next_Button clicked will result to up a page on de stackedWidget
}

void MainWindow::backButton1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


// if 1st password line != 2nd passwd line show red message passwords don't match
// and remove the red message when they are the same
void MainWindow::on_passwd_lineEdit_textChanged(const QString &arg1)
{
    if (ui->passwd_lineEdit->text() != ui->ret_passwd_lineEdit->text())
    {
        ui->label->setVisible(true);
    } else
    {
        ui->label->setVisible(false);
    }
}

// if 2nd password line != 1st passwd line show red message passwords don't match
// and remove the red message when they are the same
void MainWindow::on_ret_passwd_lineEdit_textChanged(const QString &arg1)  // this code needs editing
{
    if (ui->ret_passwd_lineEdit->text() != ui->passwd_lineEdit->text())
    {
        ui->label->setVisible(true);
    } else
    {
        ui->label->setVisible(false);
    }
}
