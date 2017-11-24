#ifndef STEPWINDOW_H
#define STEPWINDOW_H

#include <QMainWindow>
#include <servicemanager.h>

namespace Ui {
class StepWindow;
}

class StepWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StepWindow(ServiceManager *serviceManager, bool flag, QWidget *parent = 0);
    ~StepWindow();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonNextStep_clicked();

private:
    ServiceManager *serviceManager;
    Ui::StepWindow *ui;
};

#endif // STEPWINDOW_H
