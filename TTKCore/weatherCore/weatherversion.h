#ifndef WEATHERVERSION_H
#define WEATHERVERSION_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

//update time 2016.06.20
#define TTKWEATHER_STR         "TTKWeather"
#define TTKWEATHER_VERSION_STR "1.0.0.0"

#define TTKWEATHER_MAJOR_VERSION 1
#define TTKWEATHER_MIDLE_VERSION 0
#define TTKWEATHER_MINOR_VERSION 0
#define TTKWEATHER_PATCH_VERSION 0

#define TTKWEATHER_VERSION 0x01000

#define TTKWEATHER_VERSION_CHECK(major, middle, minor, patch) ((major<<12)|(middle<<8)|(minor<<4)|(patch))


#endif // WEATHERVERSION_H

