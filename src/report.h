#ifndef REPORT_H
#define REPORT_H

#include <QDialog>

namespace Ui {
class report;
}

class report : public QDialog
{
    Q_OBJECT

public:
    explicit report(QString score,QString error,QString userAns,QString comment,QWidget *parent = 0);
    ~report();

signals:
    void repeatReport();
    void retReport();

private slots:
    void repeatPush();
    void retPush();

private:
    Ui::report *ui;
};

#endif // REPORT_H
