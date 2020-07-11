#ifndef TEMPERATURESENSORIF_H
#define TEMPERATURESENSORIF_H

#include <QObject>
#include <QDateTime>

class TemperatureSensorIF : public QObject
{
    Q_OBJECT
public:
    explicit TemperatureSensorIF(QObject *parent = nullptr);

signals:
    void newTemperature(QDateTime timestamp, float degreesCelcius);
};

#endif // TEMPERATURESENSORIF_H
