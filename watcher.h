#ifndef WATCHER_H
#define WATCHER_H

#include "servicemanager.h"
#include "source.h"
#include "device.h"
#include "bid.h"

class ServiceManager;
class Device;

class Watcher
{
public:
    Watcher(ServiceManager * const serviceManager);

    int test();
    Source *getSource(unsigned int i) const;
    Device *getDevice(unsigned int i) const;
    Bid *getBidFromBuffer(unsigned int i) const;
    const Bid *getBidFromDevice(unsigned int i) const;

private:
    ServiceManager * const serviceManager_;
};

#endif // WATCHER_H
