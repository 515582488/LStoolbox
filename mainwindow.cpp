#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

bool isPressed = false;//鼠标是否点击
QPoint curPos;//鼠标位置
QString addrs;
QString ServerTime = "正在计算中...";//时间
class NowTime : public QThread{
protected:
    void run(){
        auto ProcesVoid = [=](QString cmd){
            QProcess p;//启动外部程序
            p.start(cmd);//分离式启动，主程序退出后，外部程序继续运行。
            p.waitForFinished(-1);	//超时等待，设置为-1，直到执行完成。
            QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
            QStringList list = cmd.split(" ");
            result = result.remove(list.last(), Qt::CaseInsensitive);
            result = result.replace("\r", "");
            result = result.replace("\n", "");
            result = result.simplified();


            return result;
        };
        ServerTime = ProcesVoid("powershell \"$bootTime = (Get-CimInstance -ClassName Win32_OperatingSystem).LastBootUpTime.DateTime; $currentTime = Get-Date; New-TimeSpan -Start $bootTime -End $currentTime\"");
        ServerTime = QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find(":")+2,ServerTime.toStdString().find("H")-7))+"天"+ QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find("Hours")+8,ServerTime.toStdString().find("Minutes")-16))+"时"+ QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find("Minutes")+10,ServerTime.toStdString().find("Seconds")-28))+"分";

        QThread::msleep(10000);
        quit();
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_Hover);//鼠标追踪

    addrs = QCoreApplication::applicationDirPath() + "/Tool/Main";
    ui->mianEXE->raise();//设置如果重叠显示在最上层
    ToolGroup *Tool = new ToolGroup(ui->mianEXE);
    NowTime *nowtime = new NowTime;//更新事件线程
    nowtime->start();



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

        return result;
    };

    //顶部三块显示
    ui->systemModelLabel->setText("<p align='center'>"+ProcesVoid("wmic baseboard get manufacturer")+" "+ProcesVoid("wmic csproduct get name")+"</p>");
    ui->systemDataLabel->setText("<p align='center'>"+QString::fromStdString(ProcesVoid("wmic OS get Name").toStdString().substr(0,ProcesVoid("wmic OS get Name").toStdString().find("|")))+"</p>");

    connect(nowtime,&QThread::finished,this,[=](){nowtime->start();ui->satarTimeLabel->setText("<p align='center'>"+ServerTime+"</p>");});
    ui->satarTimeLabel->setText("<p align='center'>"+ServerTime+"</p>");




    connect(ui->CloseWindow,&QPushButton::clicked,this,[=](){this->close();});//关闭窗口
    connect(ui->SmallWindow,&QPushButton::clicked,this,[=](){this->showMinimized();});//窗口最小化


    //左侧列表
    connect(ui->indexButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Main",true);Tool->renewList();});
    connect(ui->CpuButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/CpuTool",false);Tool->renewList();});
    connect(ui->otherButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Other",false);Tool->renewList();});
    connect(ui->motherboardButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Motherboard",false);Tool->renewList();});
    connect(ui->MemoryButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Memory",false);Tool->renewList();});
    connect(ui->GpuButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Gpu",false);Tool->renewList();});
    connect(ui->diskButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Disk",false);Tool->renewList();});
    connect(ui->screenButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Screen",false);Tool->renewList();});
    connect(ui->comprehensiveButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Comprehensive",false);Tool->renewList();});
    connect(ui->peripheralButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Peripheral",false);Tool->renewList();});
    connect(ui->roastButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Roast",false);Tool->renewList();});
    connect(ui->gameButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Game",false);Tool->renewList();});
}
void MainWindow::listWidgetShow(QString listAddrs, bool isIndex){//左侧列表事件函数
    addrs = QCoreApplication::applicationDirPath() + listAddrs;

    if(isIndex){
        ui->mianEXE->setGeometry(217,190,793,398);
    }else{
        ui->mianEXE->setGeometry(217,63,793,525);
    }
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

void MainWindow::mousePressEvent(QMouseEvent*event)
{
    if(event->button()==Qt::LeftButton) //如果鼠标左键按下
    {
        isPressed=true;
        curPos=event->pos();    //记录当前的点击坐标
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(isPressed) //如果鼠标左键按下
    {
        this->move(event->pos()-curPos+this->pos());    //窗口移动
    }
}

//鼠标释放
void MainWindow::mouseReleaseEvent()
{
    isPressed=false;
}
