#include "watcher.h"


Watcher::Watcher(ServiceManager * const serviceManager)
    :
      serviceManager_(serviceManager)
{} //end Watcher constructor


int Watcher::test()
{
    return serviceManager_->numOfDevices_;
}

