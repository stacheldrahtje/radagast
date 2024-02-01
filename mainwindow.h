#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void nextButton1_clicked(); // Intro_page -> Enter_page

    void nextButton2_clicked(); // Enter_page -> Summary_page

    void backButton1_clicked(); // Enter_page -> Intro_page && Summary_page -> Enter_page

    void backButton2_clicked(); // Summary_page -> Enter_page

    void commitButton_clicked(); // Commit_page -> Action

    void on_passwd_lineEdit_textChanged(const QString &arg1); // 1st passwd line check wrt 2nd passwd line

    void on_ret_passwd_lineEdit_textChanged(const QString &arg1); // 2nd passwd line check wrt 1st passwd line

    void uname_lineEdit_textChanged(); // check wether uname and passwd entries are filled

    void fname_lineEdit_textChanged(); // check wether uname and passwd entries are filled

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
