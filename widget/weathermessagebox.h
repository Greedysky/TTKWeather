#ifndef WEATHERMESSAGEBOX_H
#define WEATHERMESSAGEBOX_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherabstractmovedialog.h"

namespace Ui {
class WeatherMessageBox;
}

class WEATHER_WIDGET_EXPORT WeatherMessageBox : public WeatherAbstractMoveDialog
{
    Q_OBJECT
public:
    explicit WeatherMessageBox(QWidget *parent = 0);
    virtual ~WeatherMessageBox();

    void setText(const QString &text) const;

public slots:
    void buttonClicked(int index);

protected:
    Ui::WeatherMessageBox *ui;
    int m_status;

};

#endif // WEATHERMESSAGEBOX_H
