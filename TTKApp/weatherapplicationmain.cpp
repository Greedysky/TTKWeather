#include "weatherapplication.h"
#include "weatherobject.h"

#include <QTextCodec>
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);
#if !TTK_QT_VERSION_CHECK(5,0,0)
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif

    QTranslator translator;
    if(!translator.load(QApplication::applicationDirPath() + "/GLanguage/cn.ln"))
    {
        TTK_LOGGER_ERROR("Load translation error");
    }
    a.installTranslator(&translator);

    WeatherApplication w;
    w.hide();

    return a.exec();
}
