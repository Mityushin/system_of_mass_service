#include "watcher.h"


Watcher::Watcher(ServiceManager * const serviceManager)
    :
      serviceManager_(serviceManager)
{} //end Watcher constructor


int Watcher::test()
{
    return serviceManager_->numOfDevices_;
}

Source *Watcher::getSource(unsigned int i) const
{
    if (i >= serviceManager_->numOfSources_)
    {
        return nullptr;
    }
    return serviceManager_->sources[i];
}

Device *Watcher::getDevice(unsigned int i) const
{
    if (i >= serviceManager_->numOfDevices_)
    {
        return nullptr;
    }
    return serviceManager_->devices[i];
}

const Bid *Watcher::getBidFromDevice(unsigned int i) const
{
    if (i >= serviceManager_->numOfDevices_)
    {
        return nullptr;
    }
    if (!serviceManager_->devices[i]->isBusy())
    {
        return nullptr;
    }
    return serviceManager_->devices[i]->shareBid();
}

Bid *Watcher::getBidFromBuffer(unsigned int i) const
{
    if (i >= serviceManager_->bufferCapacity_)
    {
        return nullptr;
    }
    return serviceManager_->buffer_->bids[i];
}

