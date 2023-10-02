#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
    ui->nextButton2->setEnabled(false);

    QObject::connect (ui->nextButton1, &QPushButton::clicked, this, &MainWindow::nextButton1_clicked); // connector nextButton1
    QObject::connect (ui->backButton1, &QPushButton::clicked, this, &MainWindow::backButton1_clicked); // connector backButton1
    QObject::connect (ui->nextButton2, &QPushButton::clicked, this, &MainWindow::nextButton2_clicked); // connector nextButton2
    QObject::connect (ui->uname_lineEdit, &QLineEdit::textChanged, this, &MainWindow::uname_lineEdit_textChanged); // connector check uname_LineEdit has changed
    QObject::connect (ui->backButton2, &QPushButton::clicked, this, &MainWindow::backButton2_clicked); // connector backButton1
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uname_lineEdit_textChanged()
{

    if (ui->passwd_lineEdit->text() != ui->ret_passwd_lineEdit->text())
    {
           ui->nextButton2->setEnabled(false);
           return;
    }
    if (ui->ret_passwd_lineEdit->text() != ui->passwd_lineEdit->text())
    {
           ui->nextButton2->setEnabled(false);
           return;
    }

    int count = ui->passwd_lineEdit->text().length();
    qDebug() << count;
    if (count > 1)
    {
           //qDebug() << ui->passwd_lineEdit->text().length();
           ui->nextButton2->setEnabled(true);
           qDebug() << "True";
           return;
    }
};


void MainWindow::nextButton2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);   // signal next_Button2 points to Summary_page of stackedWidget
};


void MainWindow::nextButton1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);   // signal next_Button1 points to Enter_page of stackedWidget
};

void MainWindow::backButton1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);   // signal back_Button1 points to Intro_page of stackedWidget
};

void MainWindow::backButton2_clicked()
{
    ui->uname_lineEdit->setText(nullptr);
    ui->passwd_lineEdit->setText(nullptr);
    ui->ret_passwd_lineEdit->setText(nullptr);
    ui->keyb_layout_lineEdit->setText(nullptr);
    ui->stackedWidget->setCurrentIndex(1);
};

// if 1st password line != 2nd passwd line show red message passwords don't match
// and remove the red message when they are the same
void MainWindow::on_passwd_lineEdit_textChanged(const QString &arg1)
{
    if (ui->passwd_lineEdit->text() != ui->ret_passwd_lineEdit->text())
    {
        ui->label->setVisible(true);
        ui->nextButton2->setEnabled(false);
    } else
    {
        ui->label->setVisible(false);
        /*if (ui->passwd_lineEdit->text().length() > 1);
        {
            qDebug() << ui->passwd_lineEdit->text().length();
            ui->nextButton2->setEnabled(true);
            return;
        }*/
    }
}

// if 2nd password line != 1st passwd line show red message passwords don't match
// and remove the red message when they are the same
void MainWindow::on_ret_passwd_lineEdit_textChanged(const QString &arg1)  // this code needs editing
{
    if (ui->ret_passwd_lineEdit->text() != ui->passwd_lineEdit->text())
    {
        ui->label->setVisible(true);
        ui->nextButton2->setEnabled(false);
    } else
    {
        ui->label->setVisible(false);
        /*if (ui->passwd_lineEdit->text().length() > 1);
        {
            qDebug() << ui->passwd_lineEdit->text().length();
            ui->nextButton2->setEnabled(true);
            return;
        }*/
    }
}



