#ifndef STUDIO_HPP
#define STUDIO_HPP

#include <QFileSystemModel>
#include "ui_Studio.h"

class Studio : public QMainWindow, private Ui::Studio
{
    Q_OBJECT

public:
    Studio(QWidget* parent = 0);
    static Studio*  newFromPath(QString& path);
    static Studio*  open(QString& file);

private:
    void            initProject(QString& path);
    void            openProject(QString& file);
    void            initStudio();

    QString             _name;
    QString             _projectDir;
    QFileSystemModel*   _projectModel;
};

#endif