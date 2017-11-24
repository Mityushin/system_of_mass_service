#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defaultoptions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBoxBids->setValue(DEFAULT_NUMBER_OF_BIDS);
    ui->spinBoxBuffer->setValue(DEFAULT_BUFFER_CAPACITY);
    ui->spinBoxSources->setValue(DEFAULT_NUMBER_OF_SOURCES);
    ui->spinBoxDevices->setValue(DEFAULT_NUMBER_OF_DEVICES);
    ui->doubleSpinBoxAlpha->setValue(DEFAULT_ALPHA);
    ui->doubleSpinBoxBeta->setValue(DEFAULT_BETA);
    ui->doubleSpinBoxLambda->setValue(DEFAULT_LAMBDA);
}

MainWindow::~MainWindow()
{
    delete stepWindow;
    delete ui;
}

void MainWindow::on_pushButtonAuto_clicked()
{
    ServiceManager *serviceManager = setupSystem();
//    ServiceManager *serviceManager = new ServiceManager();
    //init
    serviceManager->execute(ui->spinBoxBids->value());
    stepWindow = new StepWindow(serviceManager, false, this);
    serviceManager = nullptr;

    this->hide();
    //show()
    stepWindow->show();
}

ServiceManager *MainWindow::setupSystem()
{
    unsigned int buffer = ui->spinBoxBuffer->value();
    unsigned int sources = ui->spinBoxSources->value();
    unsigned int devices = ui->spinBoxDevices->value();
    long double alpha = ui->doubleSpinBoxAlpha->value();
    long double beta = ui->doubleSpinBoxBeta->value();
    long double lambda = ui->doubleSpinBoxLambda->value();
    return new ServiceManager(buffer,sources, devices,
                              alpha, beta, lambda);
}

void MainWindow::on_pushButtonByStep_clicked()
{
    ServiceManager *serviceManager = setupSystem();
//    ServiceManager *serviceManager = new ServiceManager();
    stepWindow = new StepWindow(serviceManager, true, this);
    serviceManager = nullptr;

    this->hide();
    stepWindow->show();
}
