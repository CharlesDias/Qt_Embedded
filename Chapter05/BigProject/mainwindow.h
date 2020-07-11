#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "temperaturesensorif.h"

#define ADJUST_PIXEL_SIZE_FOR_STM32MP1      1.4


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(TemperatureSensorIF *tempSensor, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void    updateDisplay();
    void    updateTempDisplay(QDateTime timestamp, float temperature);

private:
    Ui::MainWindow      *ui;
    QTimer              m_updateTimer;
    TemperatureSensorIF *m_tempSensor;

    void fixPixelSizeToEmbbed();
};
#endif // MAINWINDOW_H
