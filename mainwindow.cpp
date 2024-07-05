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
        ServerTime = QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find(":")+2,ServerTime.toStdString().find("H")-7))+"天"+ QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find("Hours")+8,ServerTime.toStdString().find("Minutes")-16))+"时"+ QString::fromStdString(ServerTime.toStdString().substr(ServerTime.toStdString().find("Minutes")+10,ServerTime.toStdString().find("Seconds")-27))+"分";

        QThread::msleep(10000);
        quit();
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowFlag(Qt::FramelessWindowHint,true);
    setAttribute(Qt::WA_Hover);//鼠标追踪
    setWindowIcon(QIcon("://logo.png"));

    addrs = QCoreApplication::applicationDirPath() + "/Tool/Main";
    ui->mianEXE->raise();//设置如果重叠显示在最上层
    ToolGroup *Tool = new ToolGroup(ui->mianEXE);
    NowTime *nowtime = new NowTime;//更新事件线程
    nowtime->start();




    //加载设置
    QFile fileMainSetting("./Data/mainSetting.dat");//基础设置
    if (fileMainSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileMainSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);
        qreal diaphaneity;//透明度
        in >> diaphaneity;
        fileMainSetting.close();
        //读取完了进行设置
        this->setWindowOpacity(diaphaneity);
    }else{QMessageBox::warning(this,"警告","设置数据读取失败","确定","关闭");}
    //样式页面背景样式
    QFile fileStyleBackgroundSetting("./Data/Style/LanMuBackground.dat");
    if (fileStyleBackgroundSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileStyleBackgroundSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);  // 设置数据版本

        bool LanMuPhotoMode;//是否图片模式
        QString LanMuPhotoLineEdit;//图片路径
        QString LanMuColorLineEdit;//颜色字符

        QString BoxNameLineEdit;//工具箱名字
        QString BoxNameStyleLineEdit;//工具箱名字样式
        QString FenGeColorLineEdit;//分割线颜色

        bool ListPhotoMode;//是否图片模式
        QString ListPhotoLineEdit;//图片路径
        QString ListColorLineEdit;//颜色字符

        in >> LanMuPhotoMode >> LanMuPhotoLineEdit >> LanMuColorLineEdit\
           >> BoxNameLineEdit >> BoxNameStyleLineEdit\
           >> FenGeColorLineEdit\
           >> ListPhotoMode >> ListPhotoLineEdit >> ListColorLineEdit;
        fileStyleBackgroundSetting.close();

        if(LanMuPhotoMode){//背景设置
            ui->centralwidget->setStyleSheet("background-image: url("+ LanMuPhotoLineEdit +");");
        }else{
            ui->centralwidget->setStyleSheet("background-color: "+LanMuColorLineEdit+";");
        }

        ui->Title->setText(BoxNameLineEdit);
        ui->Title->setPalette(QPalette(BoxNameStyleLineEdit));

        if(ListPhotoMode){
            ui->ListWidget->setStyleSheet("background-image: url("+ ListPhotoLineEdit +");");
        }else{
            ui->ListWidget->setStyleSheet("background-color: "+ListColorLineEdit+";");
        }
    }
    QFile fileStyleLanButtonSetting("./Data/Style/LanMuButton.dat");//基础设置
    if (fileStyleLanButtonSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileStyleLanButtonSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);

        QString ButtonStyleLineEdit;
        QString ButtonFontColorLineEdit;

        QString List1;
        QString List2;
        QString List3;
        QString List4;
        QString List5;
        QString List6;
        QString List7;
        QString List8;
        QString List9;
        QString List10;
        QString List11;
        QString List12;


        in >> ButtonStyleLineEdit >> ButtonFontColorLineEdit\
            >> List1 >> List2 >> List3 >> List4 >> List5 >> List6 >> List7 >> List8 >> List9 >> List10 >> List11 >> List12;

        fileStyleLanButtonSetting.close();
        //读取完了进行设置
        ui->indexButton->setText(List1);
        ui->CpuButton->setText(List2);
        ui->motherboardButton->setText(List3);
        ui->MemoryButton->setText(List4);
        ui->GpuButton->setText(List5);
        ui->diskButton->setText(List6);
        ui->screenButton->setText(List7);
        ui->comprehensiveButton->setText(List8);
        ui->peripheralButton->setText(List9);
        ui->roastButton->setText(List10);
        ui->gameButton->setText(List11);
        ui->otherButton->setText(List12);

        ui->indexButton->setStyleSheet(ButtonStyleLineEdit);
        ui->CpuButton->setStyleSheet(ButtonStyleLineEdit);
        ui->motherboardButton->setStyleSheet(ButtonStyleLineEdit);
        ui->MemoryButton->setStyleSheet(ButtonStyleLineEdit);
        ui->GpuButton->setStyleSheet(ButtonStyleLineEdit);
        ui->diskButton->setStyleSheet(ButtonStyleLineEdit);
        ui->screenButton->setStyleSheet(ButtonStyleLineEdit);
        ui->comprehensiveButton->setStyleSheet(ButtonStyleLineEdit);
        ui->peripheralButton->setStyleSheet(ButtonStyleLineEdit);
        ui->roastButton->setStyleSheet(ButtonStyleLineEdit);
        ui->gameButton->setStyleSheet(ButtonStyleLineEdit);
        ui->otherButton->setStyleSheet(ButtonStyleLineEdit);

        ui->ListWidget->setStyleSheet(ui->ListWidget->styleSheet() + "color:" + ButtonFontColorLineEdit + ";");
    }
    QFile fileDingSetting("./Data/Style/DingBu.dat");
    if (fileDingSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileDingSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);

        bool DingBuMode;
        QString DingBuPhotoLineEdit;
        QString DingBuColorLineEdit;
        QString DingBuButtonColorLineEdit;


        in >> DingBuMode >> DingBuPhotoLineEdit >> DingBuColorLineEdit >> DingBuButtonColorLineEdit;

        fileDingSetting.close();
        if(DingBuMode){
            ui->widget->setStyleSheet("background-image: url("+ DingBuPhotoLineEdit +");");
        }else{
            ui->widget->setStyleSheet("background-color: "+DingBuColorLineEdit+";");
        }
        ui->AttrWindow->setStyleSheet(DingBuButtonColorLineEdit);
        ui->SmallWindow->setStyleSheet(DingBuButtonColorLineEdit);
        ui->CloseWindow->setStyleSheet(DingBuButtonColorLineEdit);
    }
    QFile fileStateSetting("./Data/Style/State.dat");
    if (fileStateSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileStateSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);

        bool StateMode;
        QString StatePhotoLineEdit;
        QString StateColorLineEdit;
        QString lineEdit_54;


        in >> StateMode >> StatePhotoLineEdit >> StateColorLineEdit >> lineEdit_54;

        fileStateSetting.close();
        if(StateMode){
            ui->widget_3->setStyleSheet("background-image: url("+ StatePhotoLineEdit +");color:"+lineEdit_54+";");
            ui->widget_4->setStyleSheet("background-image: url("+ StatePhotoLineEdit +");color:"+lineEdit_54+";");
            ui->widget_5->setStyleSheet("background-image: url("+ StatePhotoLineEdit +");color:"+lineEdit_54+";");
        }else{
            ui->widget_3->setStyleSheet("background-color: "+StateColorLineEdit+";color:"+lineEdit_54+";");
            ui->widget_4->setStyleSheet("background-color: "+StateColorLineEdit+";color:"+lineEdit_54+";");
            ui->widget_5->setStyleSheet("background-color: "+StateColorLineEdit+";color:"+lineEdit_54+";");
        }
    }
    QFile fileRuanSetting("./Data/Style/Ruan.dat");
    if (fileRuanSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileRuanSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);

        QString RuanColorLineEdit;
        bool RuanMode;
        QString RuanBackgroundPhotoLineEdit;
        QString RuanBackgroundColorLineEdit;


        in >> RuanColorLineEdit >> RuanMode >> RuanBackgroundPhotoLineEdit >> RuanBackgroundColorLineEdit;

        fileRuanSetting.close();

        if(RuanMode){
            ui->mianEXE->setStyleSheet("background-image: url("+ RuanBackgroundPhotoLineEdit +");color:"+RuanColorLineEdit+";");
        }else{
            ui->mianEXE->setStyleSheet("background-color: "+RuanBackgroundColorLineEdit+";color:"+RuanColorLineEdit+";");
        }
    }








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
    connect(ui->AttrWindow,&QPushButton::clicked,this,[=](){//设置页面
        Setting *settingWidget = new Setting();
        settingWidget->show();
        settingWidget->setAttribute(Qt::WA_DeleteOnClose,true);

        connect(settingWidget,&QWidget::destroyed,this,[=](){//当窗口关闭
            QFile file("./Data/mainSetting.dat");//基础设置
            if (file.open(QIODevice::ReadOnly)) {
                QDataStream in(&file);  // 使用 QDataStream 从二进制文件中读取数据
                in.setVersion(QDataStream::Qt_5_14);
                qreal diaphaneity;//透明度
                in >> diaphaneity;
                file.close();
                //读取完了进行设置
                this->setWindowOpacity(diaphaneity);
            }else{QMessageBox::warning(this,"警告","设置数据读取失败","确定","关闭");}
            //样式页面背景样式
            QFile fileStyleBackgroundSetting("./Data/Style/LanMuBackground.dat");
            if (fileStyleBackgroundSetting.open(QIODevice::ReadOnly)) {
                QDataStream in(&fileStyleBackgroundSetting);  // 使用 QDataStream 从二进制文件中读取数据
                in.setVersion(QDataStream::Qt_5_14);  // 设置数据版本

                bool LanMuPhotoMode;//是否图片模式
                QString LanMuPhotoLineEdit;//图片路径
                QString LanMuColorLineEdit;//颜色字符

                QString BoxNameLineEdit;//工具箱名字
                QString BoxNameStyleLineEdit;//工具箱名字样式
                QString FenGeColorLineEdit;//分割线颜色

                bool ListPhotoMode;//是否图片模式
                QString ListPhotoLineEdit;//图片路径
                QString ListColorLineEdit;//颜色字符

                in >> LanMuPhotoMode >> LanMuPhotoLineEdit >> LanMuColorLineEdit\
                   >> BoxNameLineEdit >> BoxNameStyleLineEdit\
                   >> FenGeColorLineEdit\
                   >> ListPhotoMode >> ListPhotoLineEdit >> ListColorLineEdit;
                fileStyleBackgroundSetting.close();

                if(LanMuPhotoMode){//背景设置
                    ui->centralwidget->setStyleSheet("background-image: url("+ LanMuPhotoLineEdit +");");
                }else{
                    ui->centralwidget->setStyleSheet("background-color: "+LanMuColorLineEdit+";");
                }

                ui->Title->setText(BoxNameLineEdit);
                ui->Title->setPalette(QPalette(BoxNameStyleLineEdit));

                if(ListPhotoMode){
                    ui->ListWidget->setStyleSheet("background-image: url("+ ListPhotoLineEdit +");");
                }else{
                    ui->ListWidget->setStyleSheet("background-color: "+ListColorLineEdit+";");
                }
            }else{QMessageBox::warning(this,"警告","设置数据读取失败","确定","关闭");}
            QFile fileStyleLanButtonSetting("./Data/Style/LanMuButton.dat");//基础设置
            if (fileStyleLanButtonSetting.open(QIODevice::ReadOnly)) {
                QDataStream in(&fileStyleLanButtonSetting);  // 使用 QDataStream 从二进制文件中读取数据
                in.setVersion(QDataStream::Qt_5_14);

                QString ButtonStyleLineEdit;
                QString ButtonFontColorLineEdit;

                QString List1;
                QString List2;
                QString List3;
                QString List4;
                QString List5;
                QString List6;
                QString List7;
                QString List8;
                QString List9;
                QString List10;
                QString List11;
                QString List12;


                in >> ButtonStyleLineEdit >> ButtonFontColorLineEdit\
                    >> List1 >> List2 >> List3 >> List4 >> List5 >> List6 >> List7 >> List8 >> List9 >> List10 >> List11 >> List12;

                fileStyleLanButtonSetting.close();
                //读取完了进行设置
                ui->indexButton->setText(List1);
                ui->CpuButton->setText(List2);
                ui->motherboardButton->setText(List3);
                ui->MemoryButton->setText(List4);
                ui->GpuButton->setText(List5);
                ui->diskButton->setText(List6);
                ui->screenButton->setText(List7);
                ui->comprehensiveButton->setText(List8);
                ui->peripheralButton->setText(List9);
                ui->roastButton->setText(List10);
                ui->gameButton->setText(List11);
                ui->otherButton->setText(List12);

                ui->indexButton->setStyleSheet(ButtonStyleLineEdit);
                ui->CpuButton->setStyleSheet(ButtonStyleLineEdit);
                ui->motherboardButton->setStyleSheet(ButtonStyleLineEdit);
                ui->MemoryButton->setStyleSheet(ButtonStyleLineEdit);
                ui->GpuButton->setStyleSheet(ButtonStyleLineEdit);
                ui->diskButton->setStyleSheet(ButtonStyleLineEdit);
                ui->screenButton->setStyleSheet(ButtonStyleLineEdit);
                ui->comprehensiveButton->setStyleSheet(ButtonStyleLineEdit);
                ui->peripheralButton->setStyleSheet(ButtonStyleLineEdit);
                ui->roastButton->setStyleSheet(ButtonStyleLineEdit);
                ui->gameButton->setStyleSheet(ButtonStyleLineEdit);
                ui->otherButton->setStyleSheet(ButtonStyleLineEdit);

                ui->ListWidget->setStyleSheet(ui->ListWidget->styleSheet() + "color:" + ButtonFontColorLineEdit + ";");
            }
            QFile fileDingSetting("./Data/Style/DingBu.dat");
            if (fileDingSetting.open(QIODevice::ReadOnly)) {
                QDataStream in(&fileDingSetting);  // 使用 QDataStream 从二进制文件中读取数据
                in.setVersion(QDataStream::Qt_5_14);

                bool DingBuMode;
                QString DingBuPhotoLineEdit;
                QString DingBuColorLineEdit;
                QString DingBuButtonColorLineEdit;
                QString DingBuFontColorLineEdit;


                in >> DingBuMode >> DingBuPhotoLineEdit >> DingBuColorLineEdit >> DingBuButtonColorLineEdit >> DingBuFontColorLineEdit;

                fileDingSetting.close();
                if(DingBuMode){
                    ui->widget->setStyleSheet("background-image: url("+ DingBuPhotoLineEdit +");");
                }else{
                    ui->widget->setStyleSheet("background-color: "+DingBuColorLineEdit+";");
                }
                ui->AttrWindow->setStyleSheet(DingBuButtonColorLineEdit + ";color:"+DingBuFontColorLineEdit+";");
                ui->SmallWindow->setStyleSheet(DingBuButtonColorLineEdit + ";color:"+DingBuFontColorLineEdit+";");
                ui->CloseWindow->setStyleSheet(DingBuButtonColorLineEdit + ";color:"+DingBuFontColorLineEdit+";");
            }
            QFile fileStateSetting("./Data/Style/State.dat");
            if (fileStateSetting.open(QIODevice::ReadOnly)) {
                QDataStream in(&fileStateSetting);  // 使用 QDataStream 从二进制文件中读取数据
                in.setVersion(QDataStream::Qt_5_14);

                bool StateMode;
                QString StatePhotoLineEdit;
                QString StateColorLineEdit;
                QString lineEdit_54;


                in >> StateMode >> StatePhotoLineEdit >> StateColorLineEdit >> lineEdit_54;

                fileStateSetting.close();
                if(StateMode){
                    ui->widget_3->setStyleSheet("background-image: url("+ StatePhotoLineEdit +");color:"+lineEdit_54+";");
                    ui->widget_4->setStyleSheet("background-image: url("+ StatePhotoLineEdit +");color:"+lineEdit_54+";");
                    ui->widget_5->setStyleSheet("background-image: url("+ StatePhotoLineEdit +");color:"+lineEdit_54+";");
                }else{
                    ui->widget_3->setStyleSheet("background-color: "+StateColorLineEdit+";color:"+lineEdit_54+";");
                    ui->widget_4->setStyleSheet("background-color: "+StateColorLineEdit+";color:"+lineEdit_54+";");
                    ui->widget_5->setStyleSheet("background-color: "+StateColorLineEdit+";color:"+lineEdit_54+";");
                }
            }
            QFile fileRuanSetting("./Data/Style/Ruan.dat");
            if (fileRuanSetting.open(QIODevice::ReadOnly)) {
                QDataStream in(&fileRuanSetting);  // 使用 QDataStream 从二进制文件中读取数据
                in.setVersion(QDataStream::Qt_5_14);

                QString RuanColorLineEdit;
                bool RuanMode;
                QString RuanBackgroundPhotoLineEdit;
                QString RuanBackgroundColorLineEdit;


                in >> RuanColorLineEdit >> RuanMode >> RuanBackgroundPhotoLineEdit >> RuanBackgroundColorLineEdit;

                fileRuanSetting.close();

                if(RuanMode){
                    ui->mianEXE->setStyleSheet("background-image: url("+ RuanBackgroundPhotoLineEdit +");color:"+RuanColorLineEdit+";");
                }else{
                    ui->mianEXE->setStyleSheet("background-color: "+RuanBackgroundColorLineEdit+";color:"+RuanColorLineEdit+";");
                }
            }
        });
    });


    //左侧列表
    connect(ui->indexButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Main",true);Tool->renewList();});
    connect(ui->CpuButton,&QPushButton::clicked,this,[=](){listWidgetShow("/Tool/Cpu",false);Tool->renewList();});
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
