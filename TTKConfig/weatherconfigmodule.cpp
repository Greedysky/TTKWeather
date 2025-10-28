#include "weatherconfigmodule.h"

#include <QProcess>

WeatherConfigModule::WeatherConfigModule(QObject *parent)
    : QObject(parent)
{

}

void WeatherConfigModule::valid() const
{
    checkDirectoryExist();
    checkFileNeededExist();
}

void WeatherConfigModule::initialize() const
{
    valid();
}

void WeatherConfigModule::reset() const
{

}

void WeatherConfigModule::directoryExist(const QString &name) const
{
    QDir dir;
    if(!dir.exists(name))
    {
        dir.mkpath(name);
    }
}

void WeatherConfigModule::checkDirectoryExist() const
{
    directoryExist(TTK_LANGUAGE_DIR_FULL);
}

void WeatherConfigModule::checkFileNeededExist() const
{
#ifdef Q_OS_UNIX
    if(!QFile::exists(MAIN_DIR_FULL + "ttk_runtime"))
    {
        copyLinuxShellFile(":/data/TTKRoutine.sh", TTK_ROUTINE_FULL);
        copyLinuxShellFile(":/data/TTKWeather.sh", TTK_APP_MAIN_FULL);
        copyLinuxShellFile(":/data/TTKRoutineCopy.sh", TTK_ROUTINECOPY_FULL);
        copyLinuxShellFile(":/data/TTKService.sh", TTK_SERVICE_FULL);
    }
#endif
}

void WeatherConfigModule::copyFileOverwrite(const QString &origin, const QString &des) const
{
    if(QFile::exists(des))
    {
        QFile::remove(des);
    }

    QFile::copy(origin, des);
    QFile::setPermissions(des, QFile::ReadOwner | QFile::WriteOwner);
}

void WeatherConfigModule::copyFile(const QString &origin, const QString &des) const
{
    if(!QFile::exists(des))
    {
        QFile::copy(origin, des);
        QFile::setPermissions(des, QFile::ReadOwner | QFile::WriteOwner);
    }
}

#ifdef Q_OS_UNIX
void WeatherConfigModule::copyLinuxShellFile(const QString &name, const QString &path) const
{
    copyFileOverwrite(name, path);
    QProcess::execute("chmod", {"+x", path});
}
#endif
