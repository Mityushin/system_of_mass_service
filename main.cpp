#include <iostream>
#include "servicemanager.h"

int main()
{
    ServiceManager *serviceManager = new ServiceManager();
    serviceManager->execute();
    std::cout << *serviceManager << std::endl;
//    std::cout << serviceManager->getCurrentState()->test()<< std::endl;
    delete serviceManager;
    return 0;
}
