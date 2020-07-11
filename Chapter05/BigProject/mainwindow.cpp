#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdatetime.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fixPixelSizeToEmbbed();

    connect(&m_updateTimer, &QTimer::timeout, this, &MainWindow::updateDisplay);
    m_updateTimer.setSingleShot(false);
    m_updateTimer.setInterval(1000);
    m_updateTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    QDateTime   now = QDateTime::currentDateTime();
    ui->currentDateTime->setText(now.toString());
}

void MainWindow::fixPixelSizeToEmbbed()
{
    QFont font;

    font = ui->currentDateTime->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->currentDateTime->setFont(font);
}

