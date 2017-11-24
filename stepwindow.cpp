#include "stepwindow.h"
#include "ui_stepwindow.h"

StepWindow::StepWindow(ServiceManager *serviceManager, bool flag, QWidget *parent) :
    QMainWindow(parent),
    serviceManager(serviceManager),
    ui(new Ui::StepWindow)
{
    ui->setupUi(this);
    if (!flag)
    {
        ui->pushButtonNextStep->setDisabled(true);
    }
}

StepWindow::~StepWindow()
{
    delete serviceManager;
    delete ui;
}

void StepWindow::on_pushButtonNextStep_clicked()
{
    serviceManager->executeStep();
    //TODO: update tables
}

void StepWindow::on_pushButtonClose_clicked()
{
    ((QMainWindow *) parent())->show();
    this->close();
}
