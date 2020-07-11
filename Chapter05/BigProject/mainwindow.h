#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#define ADJUST_PIXEL_SIZE_FOR_STM32MP1      1.4


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void    updateDisplay();

private:
    Ui::MainWindow *ui;
    QTimer          m_updateTimer;

    void fixPixelSizeToEmbbed();
};
#endif // MAINWINDOW_H
