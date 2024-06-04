#include "toolgroup.h"
#include "ui_toolgroup.h"


extern QString addrs;
int FileNumber = -1;
class doubleClickedThread : public QThread{
protected:
    void run(){
        sleep(1);
        FileNumber = -1;
    }
};

ToolGroup::ToolGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolGroup)
{
    ui->setupUi(this);


    QDir dir(addrs);
    if(!dir.exists()){
        QMessageBox::warning(this,"警告","找不到指定文件,可能会导致不显示工具,建议您重新安装");
    }
    renewList();

    connect(ui->homeButton,&QPushButton::clicked,this,[=](){//返回最开始的页面
        int number = addrs.toStdString().rfind("/Tool/")+6;
        number = addrs.toStdString().find("/",number);
        addrs = QString::fromStdString(addrs.toStdString().substr(0,number));
        renewList();
    });

    connect(ui->backButton,&QPushButton::clicked,this,[=](){//上一页
        int homeNumber = addrs.toStdString().rfind("/Tool/")+6;
        homeNumber = addrs.toStdString().find("/",homeNumber);
        QString homeAddrs = QString::fromStdString(addrs.toStdString().substr(0,homeNumber));
        if(homeAddrs!=addrs){
            addrs = QString::fromStdString(addrs.toStdString().substr(0,addrs.toStdString().rfind("/")));
            renewList();
        }
    });
}

ToolGroup::~ToolGroup()
{
    delete ui;
}


QFileInfoList ToolGroup::FlieList(QString *Addrs){
    QDir dir(*Addrs);
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);//取所有文件夹和文件,但是去掉.和..的文件夹
    dir.setSorting(QDir::DirsFirst);//文件夹优先
    QFileInfoList list = dir.entryInfoList();


    return list;
}

void ToolGroup::newItem(int number, QString label, QFileInfo ToolInfo,bool isDir){
    QFileIconProvider icon_provider;
    number++;
    QPushButton *newIcon = new QPushButton(this);
    newIcon->setIcon(icon_provider.icon(ToolInfo));
    newIcon->setIconSize(QSize(64,64));
    newIcon->setGeometry(ui->pushButton->geometry().x(),ui->pushButton->geometry().y(),64,64);
    newIcon->setStyleSheet("QPushButton{background-color: rgba(255, 255, 255, 0);font: 15pt \"Arial\";}\nQPushButton:hover{background-color: rgba(255, 255, 255, 60)}");
    newIcon->show();

    QLabel *newLael = new QLabel(this);
    newLael->setGeometry(ui->label->geometry().x(),ui->label->geometry().y(),64,12);
    if(strstr(label.toStdString().c_str(),"/")==NULL){
        newLael->setText("<p align=\"center\">" + label + "</p>");
    }else{
        newLael->setText("<p align=\"center\">" + QString::fromStdString(label.toStdString().substr(label.toStdString().rfind("/")+1,label.toStdString().length())) + "</p>");
        qDebug() << label;
    }

    newLael->show();

    ui->pushButton->move(69*(number%11)+5,81*(number/11)+5);
    ui->label->move(ui->pushButton->geometry().x(),ui->pushButton->geometry().y()+64);
    if(isDir){//如果是文件夹
        connect(newIcon,&QPushButton::clicked,this,[=](){//addrs + "/" + label
            if(FileNumber==-1||FileNumber!=number){
                FileNumber = number;
                doubleClickedThread *thread = new doubleClickedThread;
                thread->start();
            }else{
                FileNumber = -1;
                addrs = addrs+"/"+label;
                renewList();
            }
        });
    }else{//不是文件夹
        connect(newIcon,&QPushButton::clicked,this,[=](){//addrs + "/" + label
            if(FileNumber==-1||FileNumber!=number){
                FileNumber = number;
                doubleClickedThread *thread = new doubleClickedThread;
                thread->start();
            }else{
                FileNumber = -1;
                QProcess p;
                p.startDetached(ToolInfo.absoluteFilePath());
                p.close();
            }
        });
    }
}

void ToolGroup::renewList(){//刷新列表
    QList<QPushButton*> btns = this->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {
        if(btn!=ui->pushButton&&btn!=ui->backButton&&btn!=ui->homeButton){
            delete btn;
        }
    }
    QList<QLabel*> labels = this->findChildren<QLabel*>();
    foreach (QLabel* label, labels) {
        if(label!=ui->label){
            delete label;
        }
    }

    ui->pushButton->move(5,5);
    ui->label->move(5,69);

    QFileInfoList list = FlieList(&addrs);
    for(int i = 0,j = 0;i < list.size();i++){
        QString suffix = list[i].suffix();//获取所有文件后缀名

        if(list[i].isDir()){//如果是文件夹
            newItem(i-j,list[i].fileName(),list[i],true);
        }else if(suffix.compare("lnk")==0||suffix.compare("exe")==0){//如果后缀是快捷方式或exe
            newItem(i-j,list[i].fileName(),list[i],false);
        }else if(suffix.compare("tool")==0){
            QString Addrs_Tool = list[i].fileName().replace("_","/");
            Addrs_Tool.chop(5);
            int removeList = 0;
            QString path = list[i].path();
            while (strstr(Addrs_Tool.toStdString().c_str(),"../")!=NULL) {
                removeList++;
                Addrs_Tool = QString::fromStdString(Addrs_Tool.toStdString().substr(3,Addrs_Tool.toStdString().length()));
            }
            while (removeList!=0) {
                removeList--;
                path = QString::fromStdString(path.toStdString().substr(0,path.toStdString().rfind("/")));
            }
            QFileInfo ToolInfo(path+"/"+Addrs_Tool);
            newItem(i-j,Addrs_Tool,ToolInfo,false);
        }else{j++;}
    }
}
