#ifndef MOCKTEMPSENSOR_H
#define MOCKTEMPSENSOR_H

#include "temperaturesensorif.h"
#include <QTimer>

class QScxmlStateMachine;

class MockTempSensor : public TemperatureSensorIF
{
public:
    MockTempSensor(QObject *parent = nullptr);

    const QScxmlStateMachine *sm() const;
    void setSm(const QScxmlStateMachine *sm);

private:
    QTimer  m_sendTempTimer;
    float   m_lastTemp;

    const QScxmlStateMachine *m_sm;
};

#endif // MOCKTEMPSENSOR_H
