#include <iostream>
#include "servicemanager.h"

int main()
{
    ServiceManager *serviceManager = new ServiceManager(1, 2, 3);
    std::cout << *serviceManager << std::endl;
    delete serviceManager;
    return 0;
}
