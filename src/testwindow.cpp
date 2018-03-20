#include "testwindow.h"
#include "ui_testwindow.h"
#include "Four.h"
#include "report.h"



testwindow::testwindow(int Num,int Level,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testwindow)
{
    ui->setupUi(this);
    myTest = new MyFour(Num,Level);

    //1、产生并显示第一行
    count = 0;
    correctNum=0;
    myTest->generate();
    QString tmp=retAnEqu();
    ui->label->setText(tmp);
    ui->label_2->hide();

    //2、事件映射
    connect(ui->submitButton, SIGNAL(clicked()),this, SLOT(myCheck()));
    connect(ui->passButton, SIGNAL(clicked()),this, SLOT(myPass()));
    connect(ui->exitButton,SIGNAL(clicked()),this, SLOT(myExit()));
    connect(this, SIGNAL(myComplete()),this, SLOT(myReport()));

}

testwindow::~testwindow()
{
    delete ui;
    delete myTest;
}

//获取一个算式的字符串
QString testwindow::retAnEqu()
{
    if (count < myTest->FIntNum)
    {
        count++;
        return QString::fromStdString(myTest->FtableInt[count-1].retEqu());
    }
    else if (count == myTest->Fnum)
    {
        count =0;
        return QString::fromStdString("None");
    }

    else
    {
        count++;
        return QString::fromStdString(myTest->FtableFloat[count - myTest->FIntNum-1].retEqu());
    }

}

//提交按钮
void testwindow::myCheck()
{
    //1、比较答案并存储错题
    float userAnswer;
    if((ui->textEdit->toPlainText().length()==0)) return;
    else
        userAnswer=ui->textEdit->toPlainText().toFloat();
    float correctAns;

    if (count <= myTest->FIntNum)
        correctAns=myTest->FtableInt[count-1].retAns();
    else
        correctAns=myTest->FtableFloat[count-myTest->FIntNum-1].retAns();
    //表示算错了
    //BREAK;
    if(userAnswer>correctAns+0.01||userAnswer<correctAns-0.01)
    {
        if (count <= myTest->FIntNum)
        {
            myTest->FtableInt[count-1].errorOccur=true;
            myTest->FtableInt[count-1].userAns=(int)userAnswer;
        }
        else
        {
            myTest->FtableFloat[count-myTest->FIntNum-1].errorOccur=true;
            myTest->FtableFloat[count-myTest->FIntNum-1].userAns=(float)userAnswer;
        }
    }
    else correctNum++;
    //BREAK;
    //2、获取新题目，如果已经完成
    QString tmp=retAnEqu();
    if(tmp=="None")
        emit myComplete();
    //3、没有完成，产生新题目
    else
    {
        ui->label->setText(tmp);
        ui->textEdit->setText("");
    }
}

//跳过按钮
void testwindow::myPass()
{

    //1、直接认为是错题
    if (count <= myTest->FIntNum)
    {
        myTest->FtableInt[count-1].errorOccur=true;
        myTest->FtableInt[count-1].userAns=0xFFFFFFF;
    }
    else
    {
        myTest->FtableFloat[count-myTest->FIntNum-1].errorOccur=true;
        myTest->FtableFloat[count-myTest->FIntNum-1].userAns=0xFFFFFFF;
    }
    //2、获取新题目
    //BREAK;
    QString tmp=retAnEqu();
    if(tmp=="None")
    {
        emit myComplete();
    }
    //3、没有完成，产生新题目
    else
    {
        ui->label->setText(tmp);
        ui->textEdit->setText("");
    }
}


//做完了
void testwindow::myReport()
{
    //1、计算分数
    //BREAK;
    float temp=100.0*(correctNum*1.0/myTest->Fnum);
    QString score = QString::number(temp);

    //2、错题和用户答案
    QString error,userAns;
    for(int i=0;i<myTest->Fnum;i++)
    {

        if (i < myTest->FIntNum)
        {        
            if(myTest->FtableInt[i].errorOccur==true)
            {
            error+=QString::number(i+1)+" . ";
            userAns+=QString::number(i+1)+" . ";
            error+=QString::fromStdString(myTest->FtableInt[i].retEqu());
            error+=" = ";
            error+=QString::number(myTest->FtableInt[i].retAns());
            error+="\n";
            if(myTest->FtableInt[i].userAns==0xFFFFFFF) userAns+="None";
            else userAns+=QString::number(myTest->FtableInt[i].userAns);
            userAns+="\n";
            }
        }
        else
        {
            if(myTest->FtableFloat[i-myTest->FIntNum].errorOccur==true)
            {
            error+=QString::number(i+1)+" . ";
            userAns+=QString::number(i+1)+" . ";
            error+=QString::fromStdString(myTest->FtableFloat[i-myTest->FIntNum].retEqu());
            error+=" = ";
            error+=QString::number(myTest->FtableFloat[i-myTest->FIntNum].retAns());
            error+="\n";
            if(myTest->FtableFloat[i-myTest->FIntNum].userAns<(float)0xFFFFFFF+1.0 &&
               myTest->FtableFloat[i-myTest->FIntNum].userAns>(float)0xFFFFFFF-1.0) userAns+="None";
            else userAns+=QString::number(myTest->FtableFloat[i-myTest->FIntNum].userAns);
            userAns+="\n";
            }
        }
    }
    //3、评价语
    QString comment;
    if(temp<=60)comment="......吾人无话可说";
    else if(temp<=99.9) comment="年轻人还是要进一步提高知识水平啊";
    else comment="你没有错题啊，看来你的智商好歹有两位数以上了";

    //4、生成reporter
    myReporter = new report(score,error,userAns,comment);
    connect(myReporter, SIGNAL(repeatReport()), this, SLOT(myTestRepeat()));
    connect(myReporter, SIGNAL(retReport()), this, SLOT(myTestRet()));
    myReporter->show(); 
    hide();
}

void testwindow::myExit()
{
    ui->label_2->show();
}

void testwindow::myTestRepeat()
{
    emit repeatTest();
}

void testwindow::myTestRet()
{
    emit retTest();
}

