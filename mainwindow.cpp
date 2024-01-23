#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainterPath>
#include <QPainter>
#include <QPixmap>
#include <QtMath>
#include <ctime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    captcha();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit_3->text()!=r){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Авторизация");
        msgBox.setText("Неправильная капча");
        msgBox.exec();
        captcha();
    } else {
                if (ui->lineEdit->text()!=login && ui->lineEdit_2->text()!=password){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Авторизация");
                    msgBox.setText("Неправильный логин или пароль");
                    msgBox.exec();
                    captcha();
                }
           }
     if (ui->lineEdit->text()==login && ui->lineEdit_2->text()==password && ui->lineEdit_3->text()==r){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Авторизация");
         msgBox.setText("Вы вошли");
         msgBox.exec();
         captcha();
     }
}

void MainWindow::captcha(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");

    srand(time(NULL));
    r.resize(len);
    for (int s = 0; s < len ; ++s)
        r[s] = QChar('A' + char(rand() % ('Z' - 'A')));

    QImage image(width, height, QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    QFont font;
       //font.setPointSize(20);
       font.setUnderline(true);
       font.setOverline(true);
       //font.setCapitalization(QFont::MixedCase);
       //font.setLetterSpacing(QFont::PercentageSpacing,70);
       font.setWeight(QFont::Medium);
       painter.setFont(font);
       //painter.rotate(10);
    painter.fillRect(image.rect(), Qt::white);
    //painter.drawText(image.rect(), Qt::AlignCenter | Qt::AlignVCenter, r);
    //MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
    for (int i=0;i<len;i++){
        int size =10 + rand() % (30 -10 + 1);
        int rotate = -10 + rand() % (10 + 10 + 1);
        int pixel = 40 + rand() % (255 - 40 + 1);
        font.setPixelSize(size);
        painter.rotate(rotate);
        painter.setPen(QColor::fromHsl(pixel, 255, 127).name());
        painter.setFont(font);
        painter.drawText(QRect(20*i+30, 40, 40, height-80), Qt::AlignCenter | Qt::AlignVCenter, r[i]);

    }
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(image));
    scene->setSceneRect(0,0,image.width(),image.height());
    ui->graphicsView->setScene(scene);
}

