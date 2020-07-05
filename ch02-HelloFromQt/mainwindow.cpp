#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font;

    font = ui->label->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->label->setFont(font);

    font = ui->label_2->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->label_2->setFont(font);

    font = ui->lineEdit->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->lineEdit->setFont(font);

    font = ui->pushButton->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->pushButton->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    ui->label->setText(QString("Nice to meet you %1!").arg(name));
}
