#!/bin/sh

dirpath=`dirname $0`
tmp="${dirpath#?}"

if [ "${dirpath%${tmp}}" != "/" ]; then
  dirpath=$PWD/${dirpath}
fi

deskpath=${dirpath}/share/applications
if [ ! -d ${deskpath} ]; then
  mkdir -p ${deskpath}
fi

username=`logname`
if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

packvern=3.1.0.0
packpath=${deskpath}/TTKWeather.desktop
userpath=${homepath}/.local/share/applications
iconpath="${dirpath}/share/pixmaps/ttkweather.png"
execpath="${dirpath}/../TTKWeather"

echo -n "[Desktop Entry]
Type=Application
Version=${packvern}
Name=TTKWeather
Name[zh_CN]=天气预报
Name[zh_TW]=天氣預報
GenericName=TTKWeather
GenericName[zh_CN]=天气预报
GenericName[zh_TW]=天氣預報
Comment=TTKWeather
Comment[zh_CN]=天气预报
Comment[zh_TW]=天氣預報
Icon=${iconpath}
Exec=${execpath}
Terminal=false
Keywords=multimedia;weather;
Categories=Weather;Qt;
MimeType=
X-KDE-StartupNotify=false\n" > ${packpath}

cp -rv ${packpath} ${userpath}
chmod +x ${userpath}
