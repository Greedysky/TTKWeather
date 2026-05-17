#!/bin/sh

username=`logname`
if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

rm -f ${homepath}/.local/share/applications/TTKWeather.desktop
rm -f ${homepath}/.local/share/metainfo/ttkweather.metainfo.xml
