#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFont>

#include "mocktempsensor.h"

#define STM32MP157C_DK2

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MockTempSensor  mockTemp;
    MainWindow w(&mockTemp);

    QFont font = QApplication::font(&w);;
    font.setPixelSize(font.pointSize() * ADJUST_PIXEL_SIZE_FOR_STM32MP1);
    QApplication::setFont(font);

#ifdef STM32MP157C_DK2
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    view->setGeometry(view->geometry());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addWidget(&w);
    view->setScene(scene);
    view->show();
    view->rotate(270);
#else
    w.show();
#endif

    return a.exec();
}
