#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toolgroup.h"



#include <QEvent>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QMouseEvent>


#include <QPushButton>
#include <QMessageBox>
#include <QProcess>
#include <QStringList>
#include <QStringListModel>


#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);//关闭事件
    void mousePressEvent(QMouseEvent *event);//点击事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
    void mouseReleaseEvent();//鼠标松开事件
private:
    Ui::MainWindow *ui;

    void listWidgetShow(QString listAddrs,bool isIndex);
};
#endif // MAINWINDOW_H
