#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTabBar>

MainWindow::MainWindow(TemperatureSensorIF *tempSensor, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_tempSensor(tempSensor)
{
    this->setAttribute(Qt::WA_QuitOnClose);     // quit app when this window closes

    ui->setupUi(this);

    fixPixelSizeToEmbbed();

    connect(m_tempSensor, &TemperatureSensorIF::newTemperature, this, &MainWindow::updateTempDisplay);
    connect(m_tempSensor, &TemperatureSensorIF::newTemperature, ui->historyForm, &TemperatureHistoryForm::temperatureUpdate);

    m_updateTimer.setSingleShot(false);
    connect(&m_updateTimer, &QTimer::timeout, this, &MainWindow::updateDisplay);
    m_updateTimer.setInterval(1000);
    m_updateTimer.start();

    // uncomment these lines to automatically take a screen shot of each tab 2 seconds after the tab is changed
    //    connect(ui->tabWidget, &QTabWidget::tabBarClicked,
    //            [this] (int index){
    //                QTimer::singleShot(2000, [this, index]() {this->grab().save(QString("screenshot_%1.png").arg(index));});
    //    });
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

    font = ui->tabWidget->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->tabWidget->setFont(font);
}
