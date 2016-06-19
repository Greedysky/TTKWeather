#include "weatherapplication.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("MLanguage/cn.ln");
    a.installTranslator(&translator);

    WeatherApplication w;
    w.hide();

    return a.exec();
}
