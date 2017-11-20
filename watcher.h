#ifndef WATCHER_H
#define WATCHER_H

#include "servicemanager.h"

class ServiceManager;

class Watcher
{
public:
    Watcher(ServiceManager * const serviceManager);

    int test();

private:
    ServiceManager * const serviceManager_;
};

#endif // WATCHER_H
