#include <QFileDialog>
#include "Splash.hpp"
#include "Studio.hpp"

Splash::Splash(QWidget* parent)
: QWidget(parent)
{
    setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

void
Splash::on_create_clicked()
{
    QString project = QFileDialog::getSaveFileName(this, tr("New Project"), QString(), tr("Lums Project"), 0, QFileDialog::ShowDirsOnly);
    Studio* studio = Studio::newFromPath(project);
    studio->show();
    deleteLater();
}

void
Splash::on_open_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open project"), QString(), tr("Lums Project (*.lums-project)"));

    if (file != "")
    {
        Studio* studio = Studio::open(file);
        studio->show();
        deleteLater();
    }
}
