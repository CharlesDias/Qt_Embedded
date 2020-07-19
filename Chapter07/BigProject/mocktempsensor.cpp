#include "mocktempsensor.h"
#include <QScxmlStateMachine>

MockTempSensor::MockTempSensor(QObject *parent) :
    TemperatureSensorIF (parent),
    m_sm(nullptr)
{
//    m_lastTemp = 25.0;
//    m_sendTempTimer.setInterval(1000);
//    m_sendTempTimer.setSingleShot(false);

//    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

//    connect(&m_sendTempTimer, &QTimer::timeout, this, [this]() {
//        QDateTime now = QDateTime::currentDateTime();

//        // create a temp change of -4 to 5 based on the time
//        m_lastTemp = 24.0;
//        float change = static_cast<float>(now.time().second() % 5 - 3);

//        float change = (qrand() % 20) / 10.0;

//        m_lastTemp += change;

//        emit newTemperature(now, m_lastTemp);
//    });

//    m_sendTempTimer.start();

    m_lastTemp = 17.5;
    m_sendTempTimer.setInterval(1000);
    m_sendTempTimer.setSingleShot(false);

    connect(&m_sendTempTimer, &QTimer::timeout, this, [this]() {
        QDateTime now = QDateTime::currentDateTime();

        // create a temp change of -4 to 5 based on the time
        float change;

        auto states = (m_sm != nullptr) ? m_sm->activeStateNames(false) : QStringList();

        if (states.contains("Heating"))
        {
            change = 0.4;
        }
        else if (states.contains("Cooling"))
        {
            change = -0.4;
        }
        else
        {
            float delta = states.contains("Fan") ? (float) 0.01 : (float) 0.04;
            change = static_cast<float>(((qrand() % 100) - 51) * 0.04);
        }
        m_lastTemp += change;

        emit newTemperature(now, m_lastTemp);
    });

    m_sendTempTimer.start();
}

const QScxmlStateMachine *MockTempSensor::sm() const
{
    return m_sm;
}

void MockTempSensor::setSm(const QScxmlStateMachine *sm)
{
    m_sm = sm;
}
