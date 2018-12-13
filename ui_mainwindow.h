/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *gameBoard;
    QGraphicsView *p1Graph;
    QTextBrowser *p1TextBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *p1Points;
    QLabel *p1Water;
    QLabel *p1Sugar;
    QLabel *p1Money;
    QTextBrowser *p2Breakdown;
    QGraphicsView *p2Graph;
    QTextBrowser *p3Breakdown;
    QGraphicsView *p3Graph;
    QLabel *label_5;
    QLabel *p2Water;
    QLabel *p2Money;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *p2Points;
    QLabel *label_8;
    QLabel *p2Sugar;
    QTextBrowser *p2TextBrowser;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *p3Water;
    QLabel *p3Money;
    QLabel *label_15;
    QLabel *p3Points;
    QTextBrowser *p3TextBrowser;
    QLabel *label_16;
    QLabel *p3Sugar;
    QPushButton *endButton;
    QTextBrowser *currRecord;
    QPushButton *diceButton;
    QGraphicsView *diceView;
    QFrame *line;
    QFrame *frame;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QFrame *line_2;
    QLabel *label_21;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QLabel *p1TotMoney;
    QLabel *p1TotSugar;
    QLabel *p1TotWater;
    QLabel *label_33;
    QLabel *label_34;
    QFrame *line_12;
    QLabel *p1UsedSugar;
    QLabel *p1UsedWater;
    QLabel *p1UsedMoney;
    QLabel *p2UsedMoney;
    QLabel *p2TotMoney;
    QLabel *p2UsedWater;
    QLabel *label_22;
    QFrame *line_11;
    QFrame *line_13;
    QLabel *p2TotSugar;
    QLabel *label_37;
    QLabel *p2TotWater;
    QLabel *p2UsedSugar;
    QLabel *label_36;
    QFrame *line_14;
    QLabel *label_47;
    QLabel *label_23;
    QFrame *line_15;
    QLabel *p3TotWater;
    QLabel *p3TotMoney;
    QFrame *line_17;
    QLabel *p3UsedWater;
    QLabel *label_44;
    QLabel *p3TotSugar;
    QFrame *line_16;
    QLabel *p3UsedSugar;
    QLabel *p3UsedMoney;
    QLabel *totMoneyLabel;
    QLabel *totWaterLabel;
    QLabel *totSugarLabel;
    QFrame *line_18;
    QPushButton *roadButton;
    QPushButton *mansionButton;
    QPushButton *houseButton;
    QTextBrowser *infoBrowser;
    QTextBrowser *statusbar;
    QLabel *status_label;
    QTextBrowser *p1Breakdown;
    QPushButton *p1_graph_button;
    QPushButton *p2_graph_button;
    QPushButton *p3_graph_button;
    QLabel *player1_label;
    QLabel *player2_label;
    QLabel *player3_label;
    QPushButton *start_button;
    QLineEdit *start_input;
    QLabel *p1_ai;
    QLabel *p2_ai;
    QLabel *p3_ai;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 678);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gameBoard = new QGraphicsView(centralWidget);
        gameBoard->setObjectName(QString::fromUtf8("gameBoard"));
        gameBoard->setGeometry(QRect(10, 50, 581, 371));
        QFont font;
        font.setPointSize(30);
        gameBoard->setFont(font);
        gameBoard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gameBoard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p1Graph = new QGraphicsView(centralWidget);
        p1Graph->setObjectName(QString::fromUtf8("p1Graph"));
        p1Graph->setEnabled(true);
        p1Graph->setGeometry(QRect(600, 120, 391, 201));
        p1Graph->setMouseTracking(false);
        p1Graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p1Graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p1TextBrowser = new QTextBrowser(centralWidget);
        p1TextBrowser->setObjectName(QString::fromUtf8("p1TextBrowser"));
        p1TextBrowser->setGeometry(QRect(600, 0, 201, 101));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 40, 51, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(600, 20, 51, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(600, 60, 51, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(600, 80, 47, 14));
        p1Points = new QLabel(centralWidget);
        p1Points->setObjectName(QString::fromUtf8("p1Points"));
        p1Points->setGeometry(QRect(650, 80, 51, 16));
        p1Water = new QLabel(centralWidget);
        p1Water->setObjectName(QString::fromUtf8("p1Water"));
        p1Water->setGeometry(QRect(650, 40, 51, 16));
        p1Sugar = new QLabel(centralWidget);
        p1Sugar->setObjectName(QString::fromUtf8("p1Sugar"));
        p1Sugar->setGeometry(QRect(650, 60, 51, 16));
        p1Money = new QLabel(centralWidget);
        p1Money->setObjectName(QString::fromUtf8("p1Money"));
        p1Money->setGeometry(QRect(650, 20, 51, 16));
        p2Breakdown = new QTextBrowser(centralWidget);
        p2Breakdown->setObjectName(QString::fromUtf8("p2Breakdown"));
        p2Breakdown->setGeometry(QRect(800, 160, 191, 101));
        p2Graph = new QGraphicsView(centralWidget);
        p2Graph->setObjectName(QString::fromUtf8("p2Graph"));
        p2Graph->setGeometry(QRect(600, 280, 391, 201));
        p2Graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p2Graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p3Breakdown = new QTextBrowser(centralWidget);
        p3Breakdown->setObjectName(QString::fromUtf8("p3Breakdown"));
        p3Breakdown->setGeometry(QRect(800, 320, 191, 111));
        p3Graph = new QGraphicsView(centralWidget);
        p3Graph->setObjectName(QString::fromUtf8("p3Graph"));
        p3Graph->setGeometry(QRect(600, 450, 391, 201));
        p3Graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p3Graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(600, 180, 51, 16));
        p2Water = new QLabel(centralWidget);
        p2Water->setObjectName(QString::fromUtf8("p2Water"));
        p2Water->setGeometry(QRect(650, 200, 51, 16));
        p2Money = new QLabel(centralWidget);
        p2Money->setObjectName(QString::fromUtf8("p2Money"));
        p2Money->setGeometry(QRect(650, 180, 51, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(600, 240, 47, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(600, 200, 51, 16));
        p2Points = new QLabel(centralWidget);
        p2Points->setObjectName(QString::fromUtf8("p2Points"));
        p2Points->setGeometry(QRect(650, 240, 51, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(600, 220, 51, 16));
        p2Sugar = new QLabel(centralWidget);
        p2Sugar->setObjectName(QString::fromUtf8("p2Sugar"));
        p2Sugar->setGeometry(QRect(650, 220, 51, 16));
        p2TextBrowser = new QTextBrowser(centralWidget);
        p2TextBrowser->setObjectName(QString::fromUtf8("p2TextBrowser"));
        p2TextBrowser->setGeometry(QRect(600, 160, 201, 101));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(600, 340, 51, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(600, 380, 51, 16));
        p3Water = new QLabel(centralWidget);
        p3Water->setObjectName(QString::fromUtf8("p3Water"));
        p3Water->setGeometry(QRect(650, 360, 51, 16));
        p3Money = new QLabel(centralWidget);
        p3Money->setObjectName(QString::fromUtf8("p3Money"));
        p3Money->setGeometry(QRect(650, 340, 51, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(600, 400, 47, 14));
        p3Points = new QLabel(centralWidget);
        p3Points->setObjectName(QString::fromUtf8("p3Points"));
        p3Points->setGeometry(QRect(650, 400, 51, 16));
        p3TextBrowser = new QTextBrowser(centralWidget);
        p3TextBrowser->setObjectName(QString::fromUtf8("p3TextBrowser"));
        p3TextBrowser->setGeometry(QRect(600, 320, 201, 111));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(600, 360, 51, 16));
        p3Sugar = new QLabel(centralWidget);
        p3Sugar->setObjectName(QString::fromUtf8("p3Sugar"));
        p3Sugar->setGeometry(QRect(650, 380, 51, 16));
        endButton = new QPushButton(centralWidget);
        endButton->setObjectName(QString::fromUtf8("endButton"));
        endButton->setGeometry(QRect(900, 540, 91, 91));
        endButton->setCursor(QCursor(Qt::PointingHandCursor));
        currRecord = new QTextBrowser(centralWidget);
        currRecord->setObjectName(QString::fromUtf8("currRecord"));
        currRecord->setGeometry(QRect(600, 540, 291, 91));
        diceButton = new QPushButton(centralWidget);
        diceButton->setObjectName(QString::fromUtf8("diceButton"));
        diceButton->setGeometry(QRect(90, 0, 81, 41));
        diceButton->setCursor(QCursor(Qt::PointingHandCursor));
        diceView = new QGraphicsView(centralWidget);
        diceView->setObjectName(QString::fromUtf8("diceView"));
        diceView->setGeometry(QRect(180, 0, 101, 41));
        diceView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        diceView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(220, 0, 20, 41));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 430, 291, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 0, 141, 16));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 80, 111, 16));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 20, 41, 16));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 40, 41, 16));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 60, 41, 16));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 180, 41, 16));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 160, 41, 16));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 140, 41, 16));
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 70, 291, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_21 = new QLabel(frame);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(70, 100, 51, 16));
        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(57, 130, 241, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(60, 150, 231, 21));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(60, 170, 231, 21));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(frame);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(46, 140, 20, 61));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(frame);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(10, 10, 141, 16));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(frame);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(10, 90, 101, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(frame);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(90, 140, 3, 61));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(frame);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(130, 140, 3, 61));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        p1TotMoney = new QLabel(frame);
        p1TotMoney->setObjectName(QString::fromUtf8("p1TotMoney"));
        p1TotMoney->setGeometry(QRect(60, 140, 21, 16));
        p1TotSugar = new QLabel(frame);
        p1TotSugar->setObjectName(QString::fromUtf8("p1TotSugar"));
        p1TotSugar->setGeometry(QRect(60, 180, 21, 16));
        p1TotWater = new QLabel(frame);
        p1TotWater->setObjectName(QString::fromUtf8("p1TotWater"));
        p1TotWater->setGeometry(QRect(60, 160, 21, 16));
        label_33 = new QLabel(frame);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(60, 120, 31, 16));
        label_34 = new QLabel(frame);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(100, 120, 31, 16));
        line_12 = new QFrame(frame);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(60, 110, 61, 21));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        p1UsedSugar = new QLabel(frame);
        p1UsedSugar->setObjectName(QString::fromUtf8("p1UsedSugar"));
        p1UsedSugar->setGeometry(QRect(100, 180, 21, 16));
        p1UsedWater = new QLabel(frame);
        p1UsedWater->setObjectName(QString::fromUtf8("p1UsedWater"));
        p1UsedWater->setGeometry(QRect(100, 160, 21, 16));
        p1UsedMoney = new QLabel(frame);
        p1UsedMoney->setObjectName(QString::fromUtf8("p1UsedMoney"));
        p1UsedMoney->setGeometry(QRect(100, 140, 21, 16));
        p2UsedMoney = new QLabel(frame);
        p2UsedMoney->setObjectName(QString::fromUtf8("p2UsedMoney"));
        p2UsedMoney->setGeometry(QRect(180, 140, 21, 16));
        p2TotMoney = new QLabel(frame);
        p2TotMoney->setObjectName(QString::fromUtf8("p2TotMoney"));
        p2TotMoney->setGeometry(QRect(140, 140, 21, 16));
        p2UsedWater = new QLabel(frame);
        p2UsedWater->setObjectName(QString::fromUtf8("p2UsedWater"));
        p2UsedWater->setGeometry(QRect(180, 160, 21, 16));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(150, 100, 51, 16));
        line_11 = new QFrame(frame);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(170, 140, 3, 61));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(frame);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(140, 110, 61, 21));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        p2TotSugar = new QLabel(frame);
        p2TotSugar->setObjectName(QString::fromUtf8("p2TotSugar"));
        p2TotSugar->setGeometry(QRect(140, 180, 21, 16));
        label_37 = new QLabel(frame);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(180, 120, 31, 16));
        p2TotWater = new QLabel(frame);
        p2TotWater->setObjectName(QString::fromUtf8("p2TotWater"));
        p2TotWater->setGeometry(QRect(140, 160, 21, 16));
        p2UsedSugar = new QLabel(frame);
        p2UsedSugar->setObjectName(QString::fromUtf8("p2UsedSugar"));
        p2UsedSugar->setGeometry(QRect(180, 180, 21, 16));
        label_36 = new QLabel(frame);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(140, 120, 31, 16));
        line_14 = new QFrame(frame);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(210, 140, 3, 61));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);
        label_47 = new QLabel(frame);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(220, 120, 31, 16));
        label_23 = new QLabel(frame);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(230, 100, 51, 16));
        line_15 = new QFrame(frame);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(250, 140, 3, 61));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        p3TotWater = new QLabel(frame);
        p3TotWater->setObjectName(QString::fromUtf8("p3TotWater"));
        p3TotWater->setGeometry(QRect(220, 160, 21, 16));
        p3TotMoney = new QLabel(frame);
        p3TotMoney->setObjectName(QString::fromUtf8("p3TotMoney"));
        p3TotMoney->setGeometry(QRect(220, 140, 21, 16));
        line_17 = new QFrame(frame);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(290, 140, 3, 61));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);
        p3UsedWater = new QLabel(frame);
        p3UsedWater->setObjectName(QString::fromUtf8("p3UsedWater"));
        p3UsedWater->setGeometry(QRect(260, 160, 21, 16));
        label_44 = new QLabel(frame);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(260, 120, 31, 16));
        p3TotSugar = new QLabel(frame);
        p3TotSugar->setObjectName(QString::fromUtf8("p3TotSugar"));
        p3TotSugar->setGeometry(QRect(220, 180, 21, 16));
        line_16 = new QFrame(frame);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(220, 110, 61, 21));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        p3UsedSugar = new QLabel(frame);
        p3UsedSugar->setObjectName(QString::fromUtf8("p3UsedSugar"));
        p3UsedSugar->setGeometry(QRect(260, 180, 21, 16));
        p3UsedMoney = new QLabel(frame);
        p3UsedMoney->setObjectName(QString::fromUtf8("p3UsedMoney"));
        p3UsedMoney->setGeometry(QRect(260, 140, 21, 16));
        totMoneyLabel = new QLabel(frame);
        totMoneyLabel->setObjectName(QString::fromUtf8("totMoneyLabel"));
        totMoneyLabel->setGeometry(QRect(60, 20, 47, 14));
        totWaterLabel = new QLabel(frame);
        totWaterLabel->setObjectName(QString::fromUtf8("totWaterLabel"));
        totWaterLabel->setGeometry(QRect(60, 40, 47, 14));
        totSugarLabel = new QLabel(frame);
        totSugarLabel->setObjectName(QString::fromUtf8("totSugarLabel"));
        totSugarLabel->setGeometry(QRect(60, 60, 47, 14));
        line_18 = new QFrame(frame);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(0, 190, 291, 21));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);
        roadButton = new QPushButton(centralWidget);
        roadButton->setObjectName(QString::fromUtf8("roadButton"));
        roadButton->setGeometry(QRect(380, 430, 131, 22));
        roadButton->setCursor(QCursor(Qt::PointingHandCursor));
        mansionButton = new QPushButton(centralWidget);
        mansionButton->setObjectName(QString::fromUtf8("mansionButton"));
        mansionButton->setGeometry(QRect(450, 460, 131, 22));
        mansionButton->setCursor(QCursor(Qt::PointingHandCursor));
        houseButton = new QPushButton(centralWidget);
        houseButton->setObjectName(QString::fromUtf8("houseButton"));
        houseButton->setGeometry(QRect(310, 460, 131, 22));
        houseButton->setCursor(QCursor(Qt::PointingHandCursor));
        infoBrowser = new QTextBrowser(centralWidget);
        infoBrowser->setObjectName(QString::fromUtf8("infoBrowser"));
        infoBrowser->setGeometry(QRect(305, 491, 291, 141));
        statusbar = new QTextBrowser(centralWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(290, 0, 301, 41));
        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(300, 10, 281, 16));
        p1Breakdown = new QTextBrowser(centralWidget);
        p1Breakdown->setObjectName(QString::fromUtf8("p1Breakdown"));
        p1Breakdown->setGeometry(QRect(800, 0, 191, 101));
        p1_graph_button = new QPushButton(centralWidget);
        p1_graph_button->setObjectName(QString::fromUtf8("p1_graph_button"));
        p1_graph_button->setGeometry(QRect(600, 100, 391, 23));
        p2_graph_button = new QPushButton(centralWidget);
        p2_graph_button->setObjectName(QString::fromUtf8("p2_graph_button"));
        p2_graph_button->setGeometry(QRect(600, 260, 391, 23));
        p3_graph_button = new QPushButton(centralWidget);
        p3_graph_button->setObjectName(QString::fromUtf8("p3_graph_button"));
        p3_graph_button->setGeometry(QRect(600, 430, 391, 23));
        player1_label = new QLabel(centralWidget);
        player1_label->setObjectName(QString::fromUtf8("player1_label"));
        player1_label->setGeometry(QRect(610, 0, 51, 21));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        player1_label->setFont(font1);
        player2_label = new QLabel(centralWidget);
        player2_label->setObjectName(QString::fromUtf8("player2_label"));
        player2_label->setGeometry(QRect(610, 160, 51, 21));
        player2_label->setFont(font1);
        player3_label = new QLabel(centralWidget);
        player3_label->setObjectName(QString::fromUtf8("player3_label"));
        player3_label->setGeometry(QRect(610, 320, 51, 21));
        player3_label->setFont(font1);
        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(40, 0, 41, 41));
        start_input = new QLineEdit(centralWidget);
        start_input->setObjectName(QString::fromUtf8("start_input"));
        start_input->setGeometry(QRect(10, 0, 31, 41));
        start_input->setFont(font);
        p1_ai = new QLabel(centralWidget);
        p1_ai->setObjectName(QString::fromUtf8("p1_ai"));
        p1_ai->setGeometry(QRect(670, 0, 16, 21));
        p2_ai = new QLabel(centralWidget);
        p2_ai->setObjectName(QString::fromUtf8("p2_ai"));
        p2_ai->setGeometry(QRect(670, 160, 16, 21));
        p3_ai = new QLabel(centralWidget);
        p3_ai->setObjectName(QString::fromUtf8("p3_ai"));
        p3_ai->setGeometry(QRect(670, 320, 16, 21));
        MainWindow->setCentralWidget(centralWidget);
        p3_ai->raise();
        p2_ai->raise();
        p3TextBrowser->raise();
        p2TextBrowser->raise();
        player3_label->raise();
        player2_label->raise();
        gameBoard->raise();
        p1TextBrowser->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        p1Points->raise();
        p1Water->raise();
        p1Sugar->raise();
        p1Money->raise();
        p2Breakdown->raise();
        p3Breakdown->raise();
        label_5->raise();
        p2Water->raise();
        p2Money->raise();
        label_6->raise();
        label_7->raise();
        p2Points->raise();
        label_8->raise();
        p2Sugar->raise();
        label_13->raise();
        label_14->raise();
        p3Water->raise();
        p3Money->raise();
        label_15->raise();
        p3Points->raise();
        label_16->raise();
        p3Sugar->raise();
        endButton->raise();
        currRecord->raise();
        diceButton->raise();
        diceView->raise();
        line->raise();
        frame->raise();
        roadButton->raise();
        mansionButton->raise();
        houseButton->raise();
        infoBrowser->raise();
        statusbar->raise();
        status_label->raise();
        p1Breakdown->raise();
        p1_graph_button->raise();
        p2_graph_button->raise();
        p3_graph_button->raise();
        p2Graph->raise();
        p1Graph->raise();
        p3Graph->raise();
        player1_label->raise();
        start_button->raise();
        start_input->raise();
        p1_ai->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        p1TextBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QApplication::translate("MainWindow", " - Water:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", " - Money:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", " - Sugar:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", " - Points:", nullptr));
        p1Points->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1Water->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1Sugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1Money->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2Breakdown->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Point Breakdown:</span></p></body></html>", nullptr));
        p3Breakdown->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Point Breakdown:</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow", " - Money:", nullptr));
        p2Water->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2Money->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", " - Points:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", " - Water:", nullptr));
        p2Points->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QApplication::translate("MainWindow", " - Sugar:", nullptr));
        p2Sugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2TextBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_13->setText(QApplication::translate("MainWindow", " - Money:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", " - Sugar:", nullptr));
        p3Water->setText(QApplication::translate("MainWindow", "0", nullptr));
        p3Money->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QApplication::translate("MainWindow", " - Points:", nullptr));
        p3Points->setText(QApplication::translate("MainWindow", "0", nullptr));
        p3TextBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_16->setText(QApplication::translate("MainWindow", " - Water:", nullptr));
        p3Sugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        endButton->setText(QApplication::translate("MainWindow", "END TURN", nullptr));
        currRecord->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Current Records:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; text-decoration: underline;\"><br /></p></body></html>", nullptr));
        diceButton->setText(QApplication::translate("MainWindow", "Roll Dice", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Total Resources Distributed:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Resources By Player:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "- Money:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "- Water:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "- Sugar:", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "- Sugar:", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "- Water:", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "- Money:", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Player 1", nullptr));
        p1TotMoney->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1TotSugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1TotWater->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "Total", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "Used", nullptr));
        p1UsedSugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1UsedWater->setText(QApplication::translate("MainWindow", "0", nullptr));
        p1UsedMoney->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2UsedMoney->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2TotMoney->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2UsedWater->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "Player 2", nullptr));
        p2TotSugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "Used", nullptr));
        p2TotWater->setText(QApplication::translate("MainWindow", "0", nullptr));
        p2UsedSugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "Total", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "Total", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Player 3", nullptr));
        p3TotWater->setText(QApplication::translate("MainWindow", "0", nullptr));
        p3TotMoney->setText(QApplication::translate("MainWindow", "0", nullptr));
        p3UsedWater->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "Used", nullptr));
        p3TotSugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        p3UsedSugar->setText(QApplication::translate("MainWindow", "0", nullptr));
        p3UsedMoney->setText(QApplication::translate("MainWindow", "0", nullptr));
        totMoneyLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        totWaterLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        totSugarLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        roadButton->setText(QApplication::translate("MainWindow", "Add Candy Road", nullptr));
        mansionButton->setText(QApplication::translate("MainWindow", "Add Chocolate Mansion", nullptr));
        houseButton->setText(QApplication::translate("MainWindow", "Add Chocolate House", nullptr));
        infoBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Info:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; text-decoration: underline;\"><br /></p></body></html>", nullptr));
        status_label->setText(QString());
        p1Breakdown->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Point Breakdown:</span></p></body></html>", nullptr));
        p1_graph_button->setText(QApplication::translate("MainWindow", "Show Player 1 Graph", nullptr));
        p2_graph_button->setText(QApplication::translate("MainWindow", "Show Player 2 Graph", nullptr));
        p3_graph_button->setText(QApplication::translate("MainWindow", "Shower Player 3 Graph", nullptr));
        player1_label->setText(QApplication::translate("MainWindow", "Player 1:", nullptr));
        player2_label->setText(QApplication::translate("MainWindow", "Player 2:", nullptr));
        player3_label->setText(QApplication::translate("MainWindow", "Player 3:", nullptr));
        start_button->setText(QApplication::translate("MainWindow", "GO!", nullptr));
        start_input->setText(QString());
        p1_ai->setText(QString());
        p2_ai->setText(QString());
        p3_ai->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
