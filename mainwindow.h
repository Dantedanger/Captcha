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
    void captcha();
    QString login="admin";
    QString password="123";
    QString r;
    int len=6;
    int width=200;
    int height=140;
private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
