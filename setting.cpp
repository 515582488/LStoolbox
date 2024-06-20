#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    //初始化数据
        //初始化或读取基础设置
    QFile fileMainSetting("./Data/mainSetting.dat");
    if (fileMainSetting.open(QIODevice::ReadOnly)) {
        qreal diaphaneity;//透明度
        QDataStream in(&fileMainSetting);  // 使用 QDataStream 从二进制文件中读取数据
        in.setVersion(QDataStream::Qt_5_14);  // 设置数据版本

        in >> diaphaneity;
        fileMainSetting.close();
        //设置已保存的设置值
        ui->diaphaneity->setValue(diaphaneity);
    } else {
        qreal diaphaneity;//透明度
        //创建文件夹
        QDir qDir;
        if(!qDir.exists("Data")){
            qDir.mkdir("Data");
        }



        //初始化写入
        fileMainSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileMainSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        diaphaneity = 1;


        out << diaphaneity;
        fileMainSetting.close();
    }


        //初始化栏目样式
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
        //设置已保存的设置值
        ui->LanMuPhotoMode->setChecked(LanMuPhotoMode);
        ui->LanMuPhotoLineEdit->setText(LanMuPhotoLineEdit);
        ui->LanMuColorLineEdit->setText(LanMuColorLineEdit);

        ui->BoxNameLineEdit->setText(BoxNameLineEdit);
        ui->FenGeColorLineEdit->setText(FenGeColorLineEdit);

        ui->ListPhotoMode->setChecked(ListPhotoMode);
        ui->ListPhotoLineEdit->setText(ListPhotoLineEdit);
        ui->ListColorLineEdit->setText(ListColorLineEdit);
    } else {
        //创建文件夹
        QDir qDir;
        if(!qDir.exists("Data/Style")){
            qDir.mkdir("Data/Style");
        }

        //初始化写入
        fileStyleBackgroundSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileStyleBackgroundSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        bool LanMuPhotoMode = ui->LanMuPhotoMode->isChecked();//是否图片模式
        QString LanMuPhotoLineEdit = ui->LanMuPhotoLineEdit->text();//图片路径
        QString LanMuColorLineEdit = ui->LanMuColorLineEdit->text();//颜色字符

        QString BoxNameLineEdit = ui->BoxNameLineEdit->text();//工具箱名字
        QString BoxNameStyleLineEdit;//工具箱名字样式
        QString FenGeColorLineEdit = ui->FenGeColorLineEdit->text();//分割线颜色

        bool ListPhotoMode = ui->ListPhotoMode->isChecked();//是否图片模式
        QString ListPhotoLineEdit = ui->ListPhotoLineEdit->text();//图片路径
        QString ListColorLineEdit = ui->ListColorLineEdit->text();//颜色字符

        out << LanMuPhotoMode << LanMuPhotoLineEdit << LanMuColorLineEdit\
            << BoxNameLineEdit << BoxNameStyleLineEdit\
            << FenGeColorLineEdit\
            << ListPhotoMode << ListPhotoLineEdit << ListColorLineEdit;
        fileStyleBackgroundSetting.close();
    }

    //初始化栏目按钮样式
    QFile fileLanMuButtonSetting("./Data/Style/LanMuButton.dat");
    if (fileLanMuButtonSetting.open(QIODevice::ReadOnly)) {
        QDataStream in(&fileLanMuButtonSetting);  // 使用 QDataStream 从二进制文件中读取数据
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

        fileLanMuButtonSetting.close();

        ui->List1->setText(List1);
        ui->List2->setText(List2);
        ui->List3->setText(List3);
        ui->List4->setText(List4);
        ui->List5->setText(List5);
        ui->List6->setText(List6);
        ui->List7->setText(List7);
        ui->List8->setText(List8);
        ui->List9->setText(List9);
        ui->List10->setText(List10);
        ui->List11->setText(List11);
        ui->List12->setText(List12);
    } else {
        //初始化写入
        fileLanMuButtonSetting.open(QIODevice::WriteOnly);
        QString ButtonStyleLineEdit = ui->ButtonStyleLineEdit->text();
        QString ButtonFontColorLineEdit = ui->ButtonFontColorLineEdit->text();

        QString List1 = ui->List1->text();
        QString List2 = ui->List2->text();
        QString List3 = ui->List3->text();
        QString List4 = ui->List4->text();
        QString List5 = ui->List5->text();
        QString List6 = ui->List6->text();
        QString List7 = ui->List7->text();
        QString List8 = ui->List8->text();
        QString List9 = ui->List9->text();
        QString List10 = ui->List10->text();
        QString List11 = ui->List11->text();
        QString List12 = ui->List12->text();

        QDataStream out(&fileLanMuButtonSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本
        out << ButtonStyleLineEdit << ButtonFontColorLineEdit\
            << List1 << List2 << List3 << List4 << List5 << List6 << List7 << List8 << List9 << List10 << List11 << List12;
        fileLanMuButtonSetting.close();
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
        ui->DingBuMode->setChecked(DingBuMode);
        ui->DingBuPhotoLineEdit->setText(DingBuPhotoLineEdit);
        ui->DingBuColorLineEdit->setText(DingBuColorLineEdit);
        ui->DingBuButtonColorLineEdit->setText(DingBuButtonColorLineEdit);
    }else{
        fileDingSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileDingSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        bool DingBuMode = ui->DingBuMode->isChecked();
        QString DingBuPhotoLineEdit = ui->DingBuPhotoLineEdit->text();
        QString DingBuColorLineEdit = ui->DingBuColorLineEdit->text();
        QString DingBuButtonColorLineEdit = ui->DingBuButtonColorLineEdit->text();

        out << DingBuMode << DingBuPhotoLineEdit << DingBuColorLineEdit << DingBuButtonColorLineEdit;

        fileDingSetting.close();
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
        ui->StateMode->setChecked(StateMode);
        ui->StatePhotoLineEdit->setText(StatePhotoLineEdit);
        ui->StateColorLineEdit->setText(StateColorLineEdit);
        ui->lineEdit_54->setText(lineEdit_54);
    }else{
        fileStateSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileStateSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        bool StateMode = ui->StateMode->isChecked();
        QString StatePhotoLineEdit = ui->StatePhotoLineEdit->text();
        QString StateColorLineEdit = ui->StateColorLineEdit->text();
        QString lineEdit_54 = ui->lineEdit_54->text();

        out << StateMode << StatePhotoLineEdit << StateColorLineEdit << lineEdit_54;

        fileStateSetting.close();
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
        ui->RuanColorLineEdit->setText(RuanColorLineEdit);
        ui->RuanMode->setChecked(RuanMode);
        ui->RuanBackgroundPhotoLineEdit->setText(RuanBackgroundPhotoLineEdit);
        ui->RuanBackgroundColorLineEdit->setText(RuanBackgroundColorLineEdit);
    }else{
        fileRuanSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileRuanSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        QString RuanColorLineEdit = ui->RuanColorLineEdit->text();
        bool RuanMode = ui->RuanMode->isChecked();
        QString RuanBackgroundPhotoLineEdit = ui->RuanBackgroundPhotoLineEdit->text();
        QString RuanBackgroundColorLineEdit = ui->RuanBackgroundColorLineEdit->text();

        out << RuanColorLineEdit << RuanMode << RuanBackgroundPhotoLineEdit << RuanBackgroundColorLineEdit;

        fileRuanSetting.close();
    }




    //图片模式框
    connect(ui->LanMuPhotoMode,&QCheckBox::stateChanged,[=](bool state){//是否勾选了
        //图片模式控件操作
        ui->LanMuPhotoLineEdit->setEnabled(state);
        ui->LanMuPhotoXuanButton->setEnabled(state);
        //颜色模式控件操作
        ui->LanMuColorLineEdit->setEnabled(!state);
        ui->LanMuColorXuanButton->setEnabled(!state);
    });
    connect(ui->ListPhotoMode,&QCheckBox::stateChanged,[=](bool state){
        ui->ListPhotoLineEdit->setEnabled(state);
        ui->ListPhotoXuanButton->setEnabled(state);

        ui->ListColorLineEdit->setEnabled(!state);
        ui->ListColorXuanButto->setEnabled(!state);
    });
    connect(ui->DingBuMode,&QCheckBox::stateChanged,[=](bool state){
        ui->DingBuPhotoLineEdit->setEnabled(state);
        ui->DingBuPhotoXuanButton->setEnabled(state);

        ui->DingBuColorButton->setEnabled(!state);
        ui->DingBuColorLineEdit->setEnabled(!state);
    });
    connect(ui->StateMode,&QCheckBox::stateChanged,[=](bool state){
        ui->StatePhotoButton->setEnabled(state);
        ui->StatePhotoLineEdit->setEnabled(state);

        ui->StateColorButton->setEnabled(!state);
        ui->StateColorLineEdit->setEnabled(!state);
    });
    connect(ui->RuanMode,&QCheckBox::stateChanged,[=](bool state){
        ui->RuanBackgroundPhotoLineEdit->setEnabled(state);
        ui->StatePhotoButton_3->setEnabled(state);

        ui->RuanBackgroundColorLineEdit->setEnabled(!state);
        ui->StateColorButton_3->setEnabled(!state);
    });




    //保存设置
        //基础设置保存
    connect(ui->SaveMainSetting,&QPushButton::clicked,[=](){
        qreal diaphaneity = ui->diaphaneity->value();
        QFile file("./Data/mainSetting.dat");
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本
        out << diaphaneity;
        file.close();
        QMessageBox::question(this,"保存完成","已保存基础设置","是","好的");
    });
        //样式栏目背景设置保存
    connect(ui->SaveStyleLanBackgroundSetting,&QPushButton::clicked,[=](){
        //初始化写入
        QFile fileStyleBackgroundSetting("./Data/Style/LanMuBackground.dat");
        fileStyleBackgroundSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileStyleBackgroundSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        bool LanMuPhotoMode = ui->LanMuPhotoMode->isChecked();//是否图片模式
        QString LanMuPhotoLineEdit = ui->LanMuPhotoLineEdit->text();//图片路径
        QString LanMuColorLineEdit = ui->LanMuColorLineEdit->text();//颜色字符

        QString BoxNameLineEdit = ui->BoxNameLineEdit->text();//工具箱名字
        QString BoxNameStyleLineEdit;//工具箱名字样式
        QString FenGeColorLineEdit = ui->FenGeColorLineEdit->text();//分割线颜色

        bool ListPhotoMode = ui->ListPhotoMode->isChecked();//是否图片模式
        QString ListPhotoLineEdit = ui->ListPhotoLineEdit->text();//图片路径
        QString ListColorLineEdit = ui->ListColorLineEdit->text();//颜色字符

        out << LanMuPhotoMode << LanMuPhotoLineEdit << LanMuColorLineEdit\
            << BoxNameLineEdit << BoxNameStyleLineEdit\
            << FenGeColorLineEdit\
            << ListPhotoMode << ListPhotoLineEdit << ListColorLineEdit;
        fileStyleBackgroundSetting.close();
        QMessageBox::question(this,"保存完成","已保存栏目背景设置","是","好的");
    });
        //样式栏目按钮
    connect(ui->SaveStyleLanButtonSetting,&QPushButton::clicked,[=](){
        QString ButtonStyleLineEdit = ui->ButtonStyleLineEdit->text();
        QString ButtonFontColorLineEdit = ui->ButtonFontColorLineEdit->text();

        QString List1 = ui->List1->text();
        QString List2 = ui->List2->text();
        QString List3 = ui->List3->text();
        QString List4 = ui->List4->text();
        QString List5 = ui->List5->text();
        QString List6 = ui->List6->text();
        QString List7 = ui->List7->text();
        QString List8 = ui->List8->text();
        QString List9 = ui->List9->text();
        QString List10 = ui->List10->text();
        QString List11 = ui->List11->text();
        QString List12 = ui->List12->text();

        QFile file("./Data/Style/LanMuButton.dat");
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本
        out << ButtonStyleLineEdit << ButtonFontColorLineEdit\
            << List1 << List2 << List3 << List4 << List5 << List6 << List7 << List8 << List9 << List10 << List11 << List12;
        file.close();
        QMessageBox::question(this,"保存完成","已保存栏目按钮设置","是","好的");
    });
    connect(ui->SaveStyleDingBuSetting,&QPushButton::clicked,[=](){
        QFile fileDingSetting("./Data/Style/DingBu.dat");
        fileDingSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileDingSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        bool DingBuMode = ui->DingBuMode->isChecked();
        QString DingBuPhotoLineEdit = ui->DingBuPhotoLineEdit->text();
        QString DingBuColorLineEdit = ui->DingBuColorLineEdit->text();
        QString DingBuButtonColorLineEdit = ui->DingBuButtonColorLineEdit->text();

        out << DingBuMode << DingBuPhotoLineEdit << DingBuColorLineEdit << DingBuButtonColorLineEdit;

        fileDingSetting.close();
        QMessageBox::question(this,"保存完成","已保存栏目按钮设置","是","好的");
    });
    connect(ui->SaveStyleStateSetting,&QPushButton::clicked,[=](){
        QFile fileStateSetting("./Data/Style/State.dat");
        fileStateSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileStateSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        bool StateMode = ui->StateMode->isChecked();
        QString StatePhotoLineEdit = ui->StatePhotoLineEdit->text();
        QString StateColorLineEdit = ui->StateColorLineEdit->text();
        QString lineEdit_54 = ui->lineEdit_54->text();

        out << StateMode << StatePhotoLineEdit << StateColorLineEdit << lineEdit_54;

        fileStateSetting.close();
        QMessageBox::question(this,"保存完成","已保存栏目按钮设置","是","好的");
    });
    connect(ui->SaveStyleRuanSetting,&QPushButton::clicked,[=](){
        QFile fileRuanSetting("./Data/Style/Ruan.dat");
        fileRuanSetting.open(QIODevice::WriteOnly);
        QDataStream out(&fileRuanSetting);  // 使用 QDataStream 写入二进制文件
        out.setVersion(QDataStream::Qt_5_14);// 设置数据版本

        QString RuanColorLineEdit = ui->RuanColorLineEdit->text();
        bool RuanMode = ui->RuanMode->isChecked();
        QString RuanBackgroundPhotoLineEdit = ui->RuanBackgroundPhotoLineEdit->text();
        QString RuanBackgroundColorLineEdit = ui->RuanBackgroundColorLineEdit->text();

        out << RuanColorLineEdit << RuanMode << RuanBackgroundPhotoLineEdit << RuanBackgroundColorLineEdit;

        fileRuanSetting.close();
        QMessageBox::question(this,"保存完成","已保存栏目按钮设置","是","好的");
    });











    //样式页面按钮打开框
    connect(ui->LanMuPhotoXuanButton,&QPushButton::clicked,[=](){
        QString FileURL = QFileDialog::getOpenFileName(this,tr("打开图片"), "选取图片", tr("Image Files (*.png *.gif *.jpg *.jpge)"));
        ui->LanMuPhotoLineEdit->setText(FileURL);
    });
    connect(ui->LanMuColorXuanButton,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色");
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->LanMuColorLineEdit->setText(ColorString);
    });
    connect(ui->TitleColorButton,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->BoxNameStyleLineEdit->setText(ColorString);
    });
    connect(ui->FenGeColorButton,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->FenGeColorLineEdit->setText(ColorString);
    });
    connect(ui->ListPhotoXuanButton,&QPushButton::clicked,[=](){
        QString FileURL = QFileDialog::getOpenFileName(this,tr("打开图片"), "选取图片", tr("Image Files (*.png *.gif *.jpg *.jpge)"));
        ui->ListPhotoLineEdit->setText(FileURL);
    });
    connect(ui->ListColorXuanButto,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->ListColorLineEdit->setText(ColorString);
    });
    connect(ui->ButtonFontColorXuan,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->ButtonFontColorLineEdit->setText(ColorString);
    });
    connect(ui->DingBuColorButton,&QPushButton::clicked,[=](){
        QString FileURL = QFileDialog::getOpenFileName(this,tr("打开图片"), "选取图片", tr("Image Files (*.png *.gif *.jpg *.jpge)"));
        ui->DingBuColorLineEdit->setText(FileURL);
    });
    connect(ui->StatePhotoButton,&QPushButton::clicked,[=](){
        QString FileURL = QFileDialog::getOpenFileName(this,tr("打开图片"), "选取图片", tr("Image Files (*.png *.gif *.jpg *.jpge)"));
        ui->StatePhotoLineEdit->setText(FileURL);
    });
    connect(ui->StateColorButton,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->StateColorLineEdit->setText(ColorString);
    });
    connect(ui->pushButton_31,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->lineEdit_54->setText(ColorString);
    });
    connect(ui->pushButton_32,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->RuanColorLineEdit->setText(ColorString);
    });
    connect(ui->StatePhotoButton_3,&QPushButton::clicked,[=](){
        QString FileURL = QFileDialog::getOpenFileName(this,tr("打开图片"), "选取图片", tr("Image Files (*.png *.gif *.jpg *.jpge)"));
        ui->RuanBackgroundPhotoLineEdit->setText(FileURL);
    });
    connect(ui->StateColorButton_3,&QPushButton::clicked,[=](){
        QColor Color = QColorDialog::getColor(Qt::white,this,"选择颜色",QColorDialog::ShowAlphaChannel);
        QString ColorString = QString("rgba(%1 ,%2 ,%3 ,%4)").arg(Color.red()).arg(Color.green()).arg(Color.blue()).arg(Color.alpha());
        ui->RuanBackgroundColorLineEdit->setText(ColorString);
    });

}

Setting::~Setting()
{
    delete ui;
}


void Setting::closeEvent(QCloseEvent *event){
    int ret = QMessageBox::question(this,"关闭界面","请注意是否保存了所有设置!","是","否");
    if(ret == 0){
        event->accept();//自动处理
        return;
    }
    event->ignore();//不处理
}
