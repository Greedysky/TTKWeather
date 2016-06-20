#include "weatherapplication.h"
#include "weatherobject.h"
#ifndef MUSIC_QT_5
#include <QTextCodec>
#endif
#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifndef MUSIC_QT_5
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif

    QTranslator translator;
    translator.load(QApplication::applicationDirPath() + "/MLanguage/cn.ln");
    a.installTranslator(&translator);

    WeatherApplication w;
    w.hide();

    return a.exec();
}
