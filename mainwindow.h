#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QtWidgets>
#include <QStatusBar>
#include <QPalette>
#include <QDesktopServices>
#include <QSystemTrayIcon>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void addBtn();
    void checkBtn(bool);
    void checkBtn2(bool);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void radioBtn(bool);
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();
};
#endif // MAINWINDOW_H
