#!/bin/sh

curpath=$PWD/deploy
if [ $# -eq 0 ]; then
  curpath=$PWD
fi

path=$curpath/share/applications
if [ ! -d $path ]; then
  mkdir $path
fi

packpath=$path/TTKWeather.desktop
userpath=~/.local/share/applications
iconpath="$curpath/share/pixmaps/ttkweather.png"
execpath="$curpath/../TTKWeather"

echo -n "[Desktop Entry]
Type=Application
Version=3.1.0.0
Name=TTKWeather
Name[zh_CN]=天气预报
Name[zh_TW]=天氣預報
GenericName=TTKWeather
GenericName[zh_CN]=天气预报
GenericName[zh_TW]=天氣預報
Comment=TTKWeather
Comment[zh_CN]=天气预报
Comment[zh_TW]=天氣預報
Icon=$iconpath
Exec=$execpath
Terminal=false
Keywords=multimedia;weather;
Categories=Weather;Qt;
MimeType=
X-KDE-StartupNotify=false\n" > $packpath

cp -rv $packpath $userpath
chmod +x $userpath
