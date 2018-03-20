#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QDialog>
#define BREAK system("pause")

namespace Ui {
class testwindow;
}

class MyFour;
class report;

class testwindow : public QDialog
{
    Q_OBJECT

public:
    explicit testwindow(int Num,int Level,QWidget *parent = 0);
    ~testwindow();

    QString retAnEqu();

signals:
    void myComplete();
    void repeatTest();
    void retTest();


private slots:
    void myCheck();
    void myPass();
    void myExit();
    void myReport();
    void myTestRepeat();
    void myTestRet();

private:
    Ui::testwindow *ui;
    MyFour * myTest;
    report * myReporter;
    int count;
    int correctNum;

};

#endif // TESTWINDOW_H
