#include "report.h"
#include "ui_report.h"

report::report(QString score,QString error,QString userAns,QString comment,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);

    //1、评测显示
    ui->score->setText("your score:"+score);
    ui->textBrowser->setText(error);
    ui->textBrowser_2->setText(userAns);
    ui->comment->setText(comment);

    //2、事件映射
    connect(ui->repeatButton, SIGNAL(clicked()), this, SLOT(repeatPush()));
    connect(ui->returnButton, SIGNAL(clicked()), this, SLOT(retPush()));
}

report::~report()
{
    delete ui;
}

void report::repeatPush()
{
    hide();
    emit repeatReport();
}

void report::retPush()
{
    hide();
    emit retReport();
}
