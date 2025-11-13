#include "weatherruntimemanager.h"
#include "weatherobject.h"

#include <QFont>
#include <QApplication>

namespace TTK
{
    /*!
     * Generate core language resource.
     */
    static QString languageCore(int index);

}

QString TTK::languageCore(int index)
{
    QString lan(LANGUAGE_DIR_FULL);
    switch(index)
    {
        case 0: return lan.append("cn.ln");
        case 1: return lan.append("tc.ln");
        case 2: return lan.append("en.ln");
        default: return {};
    }
}


void WeatherRunTimeManager::execute() const
{
    TTK_INFO_STREAM("WeatherApplication Run")
#ifdef Q_OS_UNIX
    QFont font;
    font.setPixelSize(13);
    qApp->setFont(font);
#endif
}

QString WeatherRunTimeManager::translator() const
{
    return TTK::languageCore(0);
}
