#include "mocktempsensor.h"

MockTempSensor::MockTempSensor(QObject *parent) :
    TemperatureSensorIF (parent)
{
    m_lastTemp = 25.0;
    m_sendTempTimer.setInterval(1000);
    m_sendTempTimer.setSingleShot(false);

    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

    connect(&m_sendTempTimer, &QTimer::timeout, this, [this]() {
        QDateTime now = QDateTime::currentDateTime();

        // create a temp change of -4 to 5 based on the time
        m_lastTemp = 24.0;
//        float change = static_cast<float>(now.time().second() % 5 - 3);

        float change = (qrand() % 20) / 10.0;

        m_lastTemp += change;

        emit newTemperature(now, m_lastTemp);
    });

    m_sendTempTimer.start();
}
