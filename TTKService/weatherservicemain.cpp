#include "ttkapplication.h"
#include "weatherapplication.h"
#include "weatherruntimemanager.h"
#include "weatherconfigmodule.h"
#include "ttkinitialization.h"

#include <QTranslator>

int main(int argc, char *argv[])
{
    TTK::initialize(TTK::Attribute::All);

    TTKApplication app(argc, argv);
    TTKInitialization ttk;

    // parse command line args
    QStringList args;
    for(int i = 0; i < argc; ++i)
    {
        const QString &arg = QString::fromLocal8Bit(argv[i]);
        if(ttk.argumentValid(arg))
        {
            args << arg;
        }
    }

    ttk.execute(args);

    if(app.isRunning())
    {
        TTK_INFO_STREAM("One app has already run");
        return EXIT_FAILURE;
    }

    WeatherConfigModule config;
    config.execute();

    WeatherRunTimeManager manager;
    manager.execute();

    ttk.generateFont();
    ttk.codecForLocale();

    QTranslator translator;
    if(!translator.load(manager.translator()))
    {
        TTK_ERROR_STREAM("Load translation error");
    }
    app.installTranslator(&translator);

    WeatherApplication w;
    w.hide();
    return app.exec();
}
