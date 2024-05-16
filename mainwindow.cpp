#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowFlags(Qt::FramelessWindowHint);




    //顶部三列检测
    auto ProcesVoid = [=](QString cmd){
        QProcess p;//启动外部程序
        p.start(cmd);//一体式启动，不分离，主程序退出则启动程序退出,使用close关闭
        //p.startDetached(cmd)	//分离式启动，主程序退出后，外部程序继续运行。
        p.waitForFinished(-1);	//超时等待，设置为-1，直到执行完成。
        QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
        QStringList list = cmd.split(" ");
        result = result.remove(list.last(), Qt::CaseInsensitive);
        result = result.replace("\r", "");
        result = result.replace("\n", "");
        result = result.simplified();
        p.close();

        //qDebug()<< "测试" << result;
        return result;
    };

    ui->systemModelLabel->setText("<p align='center'>"+ProcesVoid("wmic baseboard get manufacturer")+" "+ProcesVoid("wmic csproduct get name")+"</p>");
    ui->systemDataLabel->setText("<p align='center'>"+QString::fromStdString(ProcesVoid("wmic OS get Name").toStdString().substr(0,ProcesVoid("wmic OS get Name").toStdString().find("|")))+"</p>");

    QString ServerTime =ProcesVoid("powershell \"$bootTime = (Get-CimInstance -ClassName Win32_OperatingSystem).LastBootUpTime.DateTime; $currentTime = Get-Date; New-TimeSpan -Start $bootTime -End $currentTime\"");
    ServerTime = QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find(":")+2,ServerTime.toStdString().find("H")-7))+"天"\
            + QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find("Hours")+8,ServerTime.toStdString().find("Minutes")-16))+"时"\
            + QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find("Minutes")+10,ServerTime.toStdString().find("Seconds")-27))+"分";
    ui->satarTimeLabel->setText("<p align='center'>"+ServerTime+"</p>");





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







