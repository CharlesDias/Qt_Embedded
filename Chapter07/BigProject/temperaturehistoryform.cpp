#include "temperaturehistoryform.h"
#include "ui_temperaturehistoryform.h"
#include "mainwindow.h"
#include <QStandardItem>
#include <QList>
#include <QVariant>
#include <QQmlEngine>
#include <QQmlContext>

#include <QTimer>

#include "temperaturestorage.h"

TemperatureHistoryForm::TemperatureHistoryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureHistoryForm)
{
    ui->setupUi(this);

    QFont font;

    font = ui->tableView->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->tableView->setFont(font);


    //** setup the table view **
    // define the headers for the temperature history
    m_tempRecord.setHorizontalHeaderLabels(QStringList({"Date & Time", "Temp (°C)"}));

    // tell the sort filter proxy what model to data from
    m_tempProxy.setSourceModel(&m_tempRecord);

    // tell the table view what model to use
    ui->tableView->setModel(&m_tempProxy);


    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // Remove the number of row
    ui->tableView->verticalHeader()->setVisible(false);


    ui->splitter->setSizes({140, 90});

    //** setup the QtQuick Chart **
    ui->quickWidget->resize(QSize(800, 480));
    ui->quickWidget->engine()->rootContext()->setContextProperty("temperatureData", this);
    ui->quickWidget->setSource(QUrl("qrc:/TemperatureChart.qml"));
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    font = ui->quickWidget->font();
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    ui->quickWidget->setFont(font);
}

TemperatureHistoryForm::~TemperatureHistoryForm()
{
    delete ui;
}

void TemperatureHistoryForm::temperatureUpdate(QDateTime timestamp, float temperature)
{
    static double start_time = timestamp.toSecsSinceEpoch();;

    // ** update the table **
    // create a row with the timestamp and temperature.
    auto time = new QStandardItem;  // a place for the timestamp
    auto temp = new QStandardItem;  // a place for the temperature

    // set the displayable data (Qt::DisplayRole)
    time->setData(timestamp, Qt::DisplayRole);
    temp->setData(temperature, Qt::DisplayRole);

    // create the row
    QList<QStandardItem *> row;
    row << time << temp;

    // add the row to the model
    m_tempRecord.appendRow(row);

    // Scrool to bottom
    ui->tableView->scrollToBottom();

    // ** update the m_lastReading **
    double xVal = timestamp.toSecsSinceEpoch() - start_time;

    setLastReading(QPointF(xVal, temperature));
}

TemperatureStorage *TemperatureHistoryForm::temperatureStorage() const
{
    return m_temperatureStorage;
}

void TemperatureHistoryForm::setTemperatureStorage(TemperatureStorage *temperatureStorage)
{
    m_temperatureStorage = temperatureStorage;
    m_tempProxy.setSourceModel(m_temperatureStorage->temperatureModel());
}

void TemperatureHistoryForm::setLastReading(const QPointF &lastReading)
{
    m_lastReading = lastReading;
    emit newReading();
}

QPointF TemperatureHistoryForm::lastReading() const
{
    return m_lastReading;
}
