#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(TemperatureSensorIF *tempSensor, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_tempSensor(tempSensor)
{
    ui->setupUi(this);

    fixPixelSizeToEmbbed();

    connect(m_tempSensor, &TemperatureSensorIF::newTemperature, this, &MainWindow::updateTempDisplay);

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

void MainWindow::updateTempDisplay(QDateTime timestamp, float temperature)
{
    ui->tempDisplay->setText(QString("%1 °C").arg(temperature));
}

void MainWindow::fixPixelSizeToEmbbed()
{
    QFont font;

    font = ui->currentDateTime->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->currentDateTime->setFont(font);

    font = ui->tempDisplay->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->tempDisplay->setFont(font);
}

