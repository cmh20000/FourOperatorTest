#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Four.h"
#include "testwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1、设置难度选项
    mySet();
    //2、确认事件链接
    connect(ui->beginButton, SIGNAL(clicked()), this, SLOT(myApply()));
    //3、退出事件链接
    connect(ui->exitButton, SIGNAL(clicked()), this , SLOT(close()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete myTestWin;
}

//难度选项
void MainWindow::mySet()
{
    ui->levelChoose->addItem(QStringLiteral("normal"), NORMAL);
    ui->levelChoose->addItem(QStringLiteral("hard"), HARD);
    ui->levelChoose->addItem(QStringLiteral("nightmare"), NIGHTMARE);
    ui->levelChoose->addItem(QStringLiteral("inferno"), INFERNO);
}

//开始建构
void MainWindow::myApply()
{
    //1、提取难度和题量输入
    int tmpL=ui->levelChoose->itemData(ui->levelChoose->currentIndex()).toInt();
    int tmpN=ui->textEdit->toPlainText().toInt();

    //   <最好要添加判断>

    //2、创建题目表
    myTestWin=new testwindow(tmpN,tmpL);
    connect(myTestWin, SIGNAL(repeatTest()), this, SLOT(myRepeat()));
    connect(myTestWin, SIGNAL(retTest()), this, SLOT(myRet()));

    //3、进入答题窗口
    myTestWin->show();
    hide();
}

void MainWindow::myRepeat()
{
    delete myTestWin;
    myApply();
}

void MainWindow::myRet()
{
    delete myTestWin;
    show();
}
















