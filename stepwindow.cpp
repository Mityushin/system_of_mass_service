#include "stepwindow.h"
#include "ui_stepwindow.h"
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
    QStringList labels;

    ui->tableBuffer->setRowCount(4);
    ui->tableBuffer->setColumnCount(serviceManager->getBufferCapacity());
    ui->tableBuffer->setRowHeight(0, 0);
    ui->tableBuffer->setRowHeight(1, 30);
    ui->tableBuffer->setRowHeight(2, 30);
    ui->tableSources->setRowHeight(3, 30);
    labels << "#" << "Bid" << "Time gen" << "Status";
    ui->tableBuffer->setVerticalHeaderLabels(labels);
    labels.clear();

    ui->tableSources->setRowCount(serviceManager->getNumOfSources());
    //310
    ui->tableSources->setColumnWidth(0, 0);
    ui->tableSources->setColumnWidth(1, 75);
    ui->tableSources->setColumnWidth(2, 70);
    ui->tableSources->setColumnWidth(3, 75);
    ui->tableSources->setColumnWidth(4, 80);
    labels << "#" << "Generated" << "Rejected" << "Next" << "Time gen";
    ui->tableSources->setHorizontalHeaderLabels(labels);
    labels.clear();

    ui->tableDevices->setRowCount(serviceManager->getNumOfDevices());
    ui->tableDevices->setColumnWidth(0, 0);
    ui->tableDevices->setColumnWidth(1, 80);
    ui->tableDevices->setColumnWidth(2, 75);
    ui->tableDevices->setColumnWidth(3, 45);
    ui->tableDevices->setColumnWidth(4, 100);
    labels << "#" << "Work time" << "Completed" << "Bid" << "End time";
    ui->tableDevices->setHorizontalHeaderLabels(labels);
    labels.clear();

    updateTables();
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
    updateTables();
}

void StepWindow::updateTables()
{
    Watcher *watcher = serviceManager->getCurrentState();

    for (unsigned int i = 0; i < serviceManager->getBufferCapacity(); i++)
    {
        if (watcher->getBidFromBuffer(i) == nullptr)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText("-");
            ui->tableBuffer->setItem(1, i, item);
            ui->tableBuffer->setItem(2, i, nullptr);
            ui->tableBuffer->setItem(3, i, nullptr);
            continue;
        }
        QTableWidgetItem *item = new QTableWidgetItem();
        std::stringstream ss1;
        ss1 << "#" << watcher->getBidFromBuffer(i)->getSourceID();
        ss1 << "." << watcher->getBidFromBuffer(i)->getSerialNum();
        item->setText(QString::fromStdString(ss1.str()));
        ui->tableBuffer->setItem(1, i, item);

        item = new QTableWidgetItem();
        std::stringstream ss2;
        ss2 << watcher->getBidFromBuffer(i)->getTimeGeneration();
        item->setText(QString::fromStdString(ss2.str()));
        ui->tableBuffer->setItem(2, i, item);

        item = new QTableWidgetItem();
        std::stringstream ss3;
        BidStatus status = watcher->getBidFromBuffer(i)->getStatus();
        ss3 << status;
        item->setText(QString::fromStdString(ss3.str()));
        ui->tableBuffer->setItem(3, i, item);
    }
    for (unsigned int i = 0; i < serviceManager->getNumOfSources(); i++)
    {
        unsigned int k = 0;

        QTableWidgetItem *item = new QTableWidgetItem();
        k = watcher->getSource(i)->getGeneratedBidCount();
        item->setText(QString::number(k));
        ui->tableSources->setItem(i, 1, item);

        item = new QTableWidgetItem();
        k = watcher->getSource(i)->getRejectedBidCount();
        item->setText(QString::number(k));
        ui->tableSources->setItem(i, 2, item);

        item = new QTableWidgetItem();
        std::stringstream ss1;
        ss1 << "#" << i + 1 << '.';
        ss1 << watcher->getSource(i)->getGeneratedBidCount() + 1;
        item->setText(QString::fromStdString(ss1.str()));
        ui->tableSources->setItem(i, 3, item);

        item = new QTableWidgetItem();
        std::stringstream ss2;
        ss2 << watcher->getSource(i)->getNextGenerateTime();
        item->setText(QString::fromStdString(ss2.str()));
        ui->tableSources->setItem(i, 4, item);
    }
    for (unsigned int i = 0; i < serviceManager->getNumOfDevices(); i++)
    {

        QTableWidgetItem *item = new QTableWidgetItem();
        std::stringstream ss1;
        ss1 << watcher->getDevice(i)->getWorkTime();
        item->setText(QString::fromStdString(ss1.str()));
        ui->tableDevices->setItem(i, 1, item);

        item = new QTableWidgetItem();
        unsigned int k = watcher->getDevice(i)->getCompletedBidCount();
        item->setText(QString::number(k));
        ui->tableDevices->setItem(i, 2, item);

        item = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        std::stringstream ss2;
        std::stringstream ss3;
        if (watcher->getDevice(i)->isBusy()) {
            ss2 << "#" << watcher->getBidFromDevice(i)->getSourceID();
            ss2 << "." << watcher->getBidFromDevice(i)->getSerialNum();
            ss3 << watcher->getDevice(i)->getProcessingEndTime();
        } else {
            ss2 << "-";
        }
        item->setText(QString::fromStdString(ss2.str()));
        item2->setText(QString::fromStdString(ss3.str()));
        ui->tableDevices->setItem(i, 3, item);
        ui->tableDevices->setItem(i, 4, item2);
    }
}

void StepWindow::on_pushButtonClose_clicked()
{
    ((QMainWindow *) parent())->show();
    this->close();
}
