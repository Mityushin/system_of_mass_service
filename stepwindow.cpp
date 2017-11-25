#include "stepwindow.h"
#include "ui_stepwindow.h"
#include "watcher.h"
#include <sstream>
#include <QString>

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
    Watcher *watcher = serviceManager->getCurrentState();
    QStringList labels;

    ui->tableBuffer->setRowCount(4);
    ui->tableBuffer->setColumnCount(watcher->getBufferCapacity());
    ui->tableBuffer->setRowHeight(0, 0);
    ui->tableBuffer->setRowHeight(1, 30);
    ui->tableBuffer->setRowHeight(2, 30);
    ui->tableSources->setRowHeight(3, 30);
    labels << "#" << "Bid" << "Time gen" << "Status";
    ui->tableBuffer->setVerticalHeaderLabels(labels);
    labels.clear();

    ui->tableSources->setRowCount(watcher->getNumOfSources());
    //310
    ui->tableSources->setColumnWidth(0, 0);
    ui->tableSources->setColumnWidth(1, 100);
    ui->tableSources->setColumnWidth(2, 100);
    ui->tableSources->setColumnWidth(3, 100);
    labels << "#" << "Generated" << "Rejected" << "Time gen";
    ui->tableSources->setHorizontalHeaderLabels(labels);
    labels.clear();

    ui->tableDevices->setRowCount(watcher->getNumOfDevices());
    ui->tableDevices->setColumnWidth(0, 0);
    ui->tableDevices->setColumnWidth(1, 100);
    ui->tableDevices->setColumnWidth(2, 100);
    ui->tableDevices->setColumnWidth(3, 100);
    labels << "#" << "Work time" << "Completed" << "End time";
    ui->tableDevices->setHorizontalHeaderLabels(labels);
    labels.clear();

    delete watcher;
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
    Watcher *watcher = serviceManager->getCurrentState();
    for (unsigned int i = 0; i < serviceManager->getNumOfSources(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        unsigned int k = 0;

        serviceManager->getCurrentState()->test();

        watcher->test();
        k = watcher->getSource(i)->getGeneratedBidCount();
        item->setText(QString::number(k));
        ui->tableSources->setItem(i + 1, 1, item);

        k = watcher->getSource(i)->getRejectedBidCount();
        item->setText(QString::number(k));
        ui->tableSources->setItem(i + 1, 2, item);

        std::stringstream ss;
        ss << watcher->getSource(i)->getNextGenerateTime();
        item->setText(QString::fromStdString(ss.str()));
        ui->tableSources->setItem(i + 1, 3, item);
    }
}

void StepWindow::on_pushButtonClose_clicked()
{
    ((QMainWindow *) parent())->show();
    this->close();
}
