#include "Studio.hpp"

Studio::Studio(QWidget* parent)
: QMainWindow(parent)
{
    setupUi(this);
}

Studio*
Studio::newFromPath(QString& path)
{
    return new Studio;
}
