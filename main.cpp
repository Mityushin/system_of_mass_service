//#include <iostream>
//#include "servicemanager.h"

#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    ServiceManager *serviceManager = new ServiceManager();
//    serviceManager->execute();
//    std::cout << *serviceManager << std::endl;
//    std::cout << serviceManager->getCurrentState()->test()<< std::endl;
//    delete serviceManager;
    return a.exec();
}
