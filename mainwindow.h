#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stepwindow.h>
#include "servicemanager.h"
#include "defaultoptions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonByStep_clicked();

    void on_pushButtonAuto_clicked();

private:
    ServiceManager *setupSystem();

    StepWindow *stepWindow;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
