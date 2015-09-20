#include "weatherapplication.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("cn.qm");
    a.installTranslator(&translator);

    WeatherApplication w;
    w.hide();

    return a.exec();
}
