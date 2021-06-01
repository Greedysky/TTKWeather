#include "weatherapplication.h"
#include "weatherobject.h"
#if !TTK_QT_VERSION_CHECK(5,0,0)
#include <QTextCodec>
#endif
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if !TTK_QT_VERSION_CHECK(5,0,0)
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
