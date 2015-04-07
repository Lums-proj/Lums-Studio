#include <QUrl>
#include <QDir>
#include <QFile>
#include <QDebug>
#include "Studio.hpp"

Studio::Studio(QWidget* parent)
: QMainWindow(parent)
{
    setupUi(this);
}

Studio*
Studio::newFromPath(QString& path)
{
    Studio* s = new Studio;
    s->initProject(path);
    return s;
}

Studio*
Studio::open(QString& file)
{
    Studio* s = new Studio;
    s->openProject(file);
    return s;
}

// Private

void
Studio::initProject(QString& path)
{
    _name = QUrl(path).fileName();
    _projectDir = path;
    QDir().mkdir(path);

    QDir d(path);
    d.mkdir("Assets");
    d.mkdir("Assets/Images");
    d.mkdir("Sources");
    QFile(path + "/" + _name + ".lums-project").open(QIODevice::WriteOnly);
    initStudio();
}

void
Studio::openProject(QString& file)
{
    _name = QFileInfo(QUrl(file).fileName()).baseName();
    _projectDir = QFileInfo(file).absoluteDir().absolutePath();
    qDebug() << _projectDir;
    initStudio();
}

void
Studio::initStudio()
{
    setUnifiedTitleAndToolBarOnMac(true);
    setWindowTitle(_name);
    _projectModel = new QFileSystemModel;
    _projectModel->setRootPath(_projectDir);
    projectView->setModel(_projectModel);
    projectView->setRootIndex(_projectModel->index(_projectDir));
    projectView->hideColumn(1);
    projectView->hideColumn(2);
    projectView->hideColumn(3);
    _projectModel->setNameFilters(QStringList() << "*.txt" << "*.c" << "*.cpp" << "*.h" << "*.hpp" << "*.png");
    _projectModel->setNameFilterDisables(false);
}
