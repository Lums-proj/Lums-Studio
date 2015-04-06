#include <QApplication>
#include "Splash.hpp"

int
main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Splash* s = new Splash;

    s->show();
    return a.exec();
}