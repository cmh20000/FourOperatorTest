#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class testwindow;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void myApply();
    void myRepeat();
    void myRet();

private:
    Ui::MainWindow *ui;
    testwindow *myTestWin;
    void mySet();

};

#endif // MAINWINDOW_H
