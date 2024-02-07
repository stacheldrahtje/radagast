#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include "inputcontrol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
    ui->Dave->setVisible(false);
    ui->nextButton2->setEnabled(false);
    ui->fname_lineEdit->setFocus();

    // connector definition without passwd because they are on_****** and are located in separate functions.

    // connector nextButton1
    QObject::connect (ui->nextButton1, &QPushButton::clicked, this, &MainWindow::nextButton1_clicked);
    // connector backButton1
    QObject::connect (ui->backButton1, &QPushButton::clicked, this, &MainWindow::backButton1_clicked);
    // connector nextButton2
    QObject::connect (ui->nextButton2, &QPushButton::clicked, this, &MainWindow::nextButton2_clicked);
    // connector check uname_LineEdit has changed
    QObject::connect (ui->uname_lineEdit, &QLineEdit::textChanged, this, &MainWindow::uname_lineEdit_textChanged);
    // connector check fname_LineEdit has changed
    QObject::connect (ui->fname_lineEdit, &QLineEdit::textChanged, this, &MainWindow::fname_lineEdit_textChanged);
    // connector backButton1
    QObject::connect (ui->backButton2, &QPushButton::clicked, this, &MainWindow::backButton2_clicked);
    // connector commitButton1
    QObject::connect (ui->commitButton, &QPushButton::clicked, this, &MainWindow::commitButton_clicked);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uname_lineEdit_textChanged()
{    
    if (regcheck(ui->uname_lineEdit->text()) == true)
    {
        ui->Dave->setVisible(true);
        ui->nextButton2->setEnabled(false);
        return;
    } else {ui->Dave->setVisible(false);}
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
    if (ui->passwd_lineEdit->text().length() > 1 && ui->fname_lineEdit->text().length() > 1)
    {
           ui->nextButton2->setEnabled(true);
           return;
    }
};

void MainWindow::fname_lineEdit_textChanged()
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
    if (regcheck(ui->fname_lineEdit->text()) == true)
    {
           ui->Dave->setVisible(true);
           ui->nextButton2->setEnabled(false);
           return;
    } else {ui->Dave->setVisible(false);}
    if (ui->passwd_lineEdit->text().length() > 1 && ui->uname_lineEdit->text().length() > 1)
    {
           ui->nextButton2->setEnabled(true);
           return;
    }
};


void MainWindow::nextButton2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);   // signal next_Button2 points to Summary_page of stackedWidget
    ui->fname_l->setText(ui->fname_lineEdit->text()); // set label with fname_lineEdit
    ui->uname_l->setText(ui->uname_lineEdit->text()); // set label with uname_lineEdit
    ui->passwd_l->setText(ui->passwd_lineEdit->text()); // set label with passwd_lineEdit
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
    ui->fname_lineEdit->clear();
    ui->uname_lineEdit->clear();
    ui->passwd_lineEdit->clear();
    ui->ret_passwd_lineEdit->clear();
    ui->keyb_layout_lineEdit->clear();
    ui->stackedWidget->setCurrentIndex(1);
};

// if 1st password line != 2nd passwd line show red message passwords don't match
// and remove the red message when they are the same
void MainWindow::on_passwd_lineEdit_textChanged(const QString &arg1)
{
    if (regcheck(ui->passwd_lineEdit->text()) == true)
    {
           ui->Dave->setVisible(true);
           ui->nextButton2->setEnabled(false);
           return;
    } else {ui->Dave->setVisible(false);}
    if (ui->passwd_lineEdit->text() != ui->ret_passwd_lineEdit->text())
    {
        ui->label->setVisible(true);
        ui->nextButton2->setEnabled(false);
        //return;
    } else
    {
        ui->label->setVisible(false);
        if ( ui->uname_lineEdit->text().length() >= 1 && ui->fname_lineEdit->text().length() >= 1)
        {
            ui->nextButton2->setEnabled(true);
            return;
        }
    }
}

// if 2nd password line != 1st passwd line show red message passwords don't match
// and remove the red message when they are the same
void MainWindow::on_ret_passwd_lineEdit_textChanged(const QString &arg1)
{
    if (regcheck(ui->ret_passwd_lineEdit->text()) == true)
    {
        ui->Dave->setVisible(true);
        ui->nextButton2->setEnabled(false);
        return;
    } else {ui->Dave->setVisible(false);}
    if (ui->ret_passwd_lineEdit->text() != ui->passwd_lineEdit->text())
    {
        ui->label->setVisible(true);
        ui->nextButton2->setEnabled(false);
        //return;
    } else
    {
        ui->label->setVisible(false);
        if ( ui->uname_lineEdit->text().length() >= 1 && ui->fname_lineEdit->text().length() >= 1)
        {
            ui->nextButton2->setEnabled(true);
            return;
        }

    }
}

void MainWindow::commitButton_clicked(char uname, char passwd)
{
    //placeholder for now.
}
