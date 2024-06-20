#ifndef TOOLGROUP_H
#define TOOLGROUP_H

#include <QWidget>

#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QFileIconProvider>
#include <QFileInfo>
#include <QProcess>
#include <QThread>
#include <QGuiApplication>
#include <QFileDialog>

namespace Ui {
class ToolGroup;
}

class ToolGroup : public QWidget
{
    Q_OBJECT

public:
    ToolGroup(QWidget *parent = nullptr);
    ~ToolGroup();
    void renewList();
signals:
    void OpenNewFloder();
private:
    Ui::ToolGroup *ui;

    QFileInfoList FlieList(QString *Addrs);
    void newItem(int number,QString label,QFileInfo ToolInfo,bool isDir);
};

#endif // TOOLGROUP_H
