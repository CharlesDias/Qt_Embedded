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
}

MainWindow::~MainWindow()
{
    delete ui;
}

