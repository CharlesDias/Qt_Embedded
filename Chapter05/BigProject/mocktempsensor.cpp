#include "mocktempsensor.h"

MockTempSensor::MockTempSensor(QObject *parent) :
    TemperatureSensorIF (parent)
{
    m_lastTemp = 20.0;
    m_sendTempTimer.setInterval(3000);
    m_sendTempTimer.setSingleShot(false);

    connect(&m_sendTempTimer, &QTimer::timeout, this, [this]() {
        QDateTime now = QDateTime::currentDateTime();

        // create a temp change of -4 to 5 based on the time
        m_lastTemp = 30.0;
        float change = static_cast<float>(now.time().second() % 5 - 5);
        m_lastTemp += change;

        emit newTemperature(now, m_lastTemp);
    });

    m_sendTempTimer.start();
}
