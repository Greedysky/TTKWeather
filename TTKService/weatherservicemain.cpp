#include "ttkapplication.h"
#include "weatherapplication.h"
#include "weatherobject.h"
#include "ttkinitialization.h"

#include <QTranslator>

int main(int argc, char *argv[])
{
    TTK::loadApplicationScaleFactor();

    TTKApplication app(argc, argv);
    TTKInitialization ttk;

    if(app.isRunning())
    {
        TTK_INFO_STREAM("One app has already run");
        return EXIT_FAILURE;
    }

    ttk.generateFont();
    ttk.codecForLocale();
    ttk.execute();

    QTranslator translator;
    if(!translator.load(QApplication::applicationDirPath() + "/GLanguage/cn.ln"))
    {
        TTK_ERROR_STREAM("Load translation error");
    }
    app.installTranslator(&translator);

    WeatherApplication w;
    w.hide();
    return app.exec();
}
