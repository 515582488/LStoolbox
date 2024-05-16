/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *CloseWindow;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_16;
    QLabel *systemModelLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QLabel *systemDataLabel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_21;
    QLabel *satarTimeLabel;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1000, 750);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 61, 72);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 67, 83);"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(20, 0));
        pushButton->setMaximumSize(QSize(20, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_3->addWidget(pushButton);

        CloseWindow = new QPushButton(widget);
        CloseWindow->setObjectName("CloseWindow");
        sizePolicy.setHeightForWidth(CloseWindow->sizePolicy().hasHeightForWidth());
        CloseWindow->setSizePolicy(sizePolicy);
        CloseWindow->setMinimumSize(QSize(20, 0));
        CloseWindow->setMaximumSize(QSize(20, 16777215));
        CloseWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_3->addWidget(CloseWindow);

        horizontalLayout_3->setStretch(0, 12);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        horizontalLayout->addWidget(widget);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 67, 83);"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_16 = new QLabel(widget_3);
        label_16->setObjectName("label_16");

        verticalLayout_4->addWidget(label_16);

        systemModelLabel = new QLabel(widget_3);
        systemModelLabel->setObjectName("systemModelLabel");
        systemModelLabel->setStyleSheet(QString::fromUtf8("align: center;"));

        verticalLayout_4->addWidget(systemModelLabel);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 9);

        horizontalLayout_4->addWidget(widget_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 67, 83);"));
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_18 = new QLabel(widget_4);
        label_18->setObjectName("label_18");

        verticalLayout_5->addWidget(label_18);

        systemDataLabel = new QLabel(widget_4);
        systemDataLabel->setObjectName("systemDataLabel");

        verticalLayout_5->addWidget(systemDataLabel);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 9);

        horizontalLayout_4->addWidget(widget_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName("widget_5");
        widget_5->setLayoutDirection(Qt::LeftToRight);
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 67, 83);"));
        verticalLayout_6 = new QVBoxLayout(widget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_21 = new QLabel(widget_5);
        label_21->setObjectName("label_21");

        verticalLayout_6->addWidget(label_21);

        satarTimeLabel = new QLabel(widget_5);
        satarTimeLabel->setObjectName("satarTimeLabel");

        verticalLayout_6->addWidget(satarTimeLabel);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 9);

        horizontalLayout_4->addWidget(widget_5);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 5);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 5);

        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        gridLayout_2->addWidget(listWidget, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 2);
        gridLayout_2->setRowStretch(1, 5);

        gridLayout->addLayout(gridLayout_2, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 34, 43);"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 10));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName("label_12");

        verticalLayout_2->addWidget(label_12);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName("label_11");

        verticalLayout_2->addWidget(label_11);

        label_13 = new QLabel(widget_2);
        label_13->setObjectName("label_13");

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName("label_14");

        verticalLayout_2->addWidget(label_14);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");

        verticalLayout_2->addWidget(label_8);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 120);

        verticalLayout->addWidget(widget_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 30);
        gridLayout->setColumnStretch(0, 8);
        gridLayout->setColumnStretch(1, 28);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\241\254\344\273\266\344\277\241\346\201\257", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        CloseWindow->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\347\224\265\350\204\221\345\236\213\345\217\267:", nullptr));
        systemModelLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Text</p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\344\277\241\346\201\257:", nullptr));
        systemDataLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\345\274\200\346\234\272\346\227\266\351\227\264:", nullptr));
        satarTimeLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\232\202\346\227\240\345\212\237\350\203\275</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">Sun\345\267\245\345\205\267\347\256\261</span></h1></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<hr style=\"color:white\">", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " \347\241\254\344\273\266\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " CPU\345\267\245\345\205\267", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", " \344\270\273\346\235\277\345\267\245\345\205\267", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " \345\206\205\345\255\230\345\267\245\345\205\267", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", " \346\230\276\345\215\241\345\267\245\345\205\267", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", " \347\241\254\347\233\230\345\267\245\345\205\267", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", " \345\261\217\345\271\225\345\267\245\345\205\267", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", " \347\273\274\345\220\210\346\243\200\346\265\213", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", " \345\244\226\350\256\276\345\267\245\345\205\267", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", " \347\203\244\351\270\241\345\267\245\345\205\267", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " \345\205\266\344\273\226\345\267\245\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
