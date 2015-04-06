#ifndef STUDIO_HPP
#define STUDIO_HPP

#include "ui_Studio.h"

class Studio : public QMainWindow, private Ui::Studio
{
    Q_OBJECT

public:
    Studio(QWidget* parent = 0);
    static Studio*  newFromPath(QString& path);
};

#endif