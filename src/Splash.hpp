#ifndef SPLASH_HPP
#define SPLASH_HPP

#include "ui_Splash.h"

class Splash : public QWidget, private Ui::Splash
{
    Q_OBJECT

public:
    Splash(QWidget* parent = 0);

private slots:
    void    on_create_clicked();
};

#endif
