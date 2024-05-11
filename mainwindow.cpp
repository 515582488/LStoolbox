#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowFlags(Qt::FramelessWindowHint);


    QString ListCmd[3] = {"Wmic csproduct get name","wmic OS get Name","powershell \"$bootTime = (Get-CimInstance -ClassName Win32_OperatingSystem).LastBootUpTime.DateTime; $currentTime = Get-Date; New-TimeSpan -Start $bootTime -End $currentTime\""};
    for(int i=0;i<3;i++) {
        QProcess p;//启动外部程序
        p.start(ListCmd[i]);//一体式启动，不分离，主程序退出则启动程序退出,使用close关闭
        //p.startDetached(cmd)	//分离式启动，主程序退出后，外部程序继续运行。
        p.waitForFinished(-1);	//超时等待，设置为-1，直到执行完成。
        QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
        QStringList list = ListCmd[i].split(" ");
        result = result.remove(list.last(), Qt::CaseInsensitive);
        result = result.replace("\r", "");
        result = result.replace("\n", "");
        result = result.simplified();
        p.close();

        qDebug() << result;
        if(i==0){
            ui->systemModelLabel->setText("<p align='center'>"+result+"</p>");
        }else{
            ui->systemDataLabel->setText("<p align='center'>"+QString::fromStdString(result.toStdString().substr(0,result.toStdString().find("|")))+"</p>");
        }
    }






    connect(ui->CloseWindow,&QPushButton::clicked,this,[=](){this->close();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    int ret = QMessageBox::question(this,"关闭窗口","是否要关闭窗口","是","否");
    if(ret == 0){
        event->accept();//自动处理
        return;
    }
    event->ignore();//不处理
}







