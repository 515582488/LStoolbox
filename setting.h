#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

#include <QCloseEvent>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <QFontDialog>
#include <QFileDialog>
#include <QColorDialog>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::Setting *ui;
};

#endif // SETTING_H
