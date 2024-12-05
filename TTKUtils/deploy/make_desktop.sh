#!/bin/sh

path=share/applications
if [ ! -d $path ]; then
  mkdir $path
fi

datapath=$path/TTKWeather.desktop
packpath="$PWD/$datapath"
userpath=~/.local/$datapath
iconpath="$PWD/share/pixmaps/ttkweather.png"
execpath="$PWD/../TTKWeather"

echo -n "[Desktop Entry]
Type=Application
Version=3.0.0.0
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
