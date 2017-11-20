#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "buffer.h"
#include "device.h"

class DeviceManager
{
public:
    DeviceManager(
            const unsigned int numOfDevices
            );
    ~DeviceManager();

    void putBid(Bid *bid);
    Bid *completeBid();

    friend std::ostream &operator<<(std::ostream &stream, const DeviceManager &deviceManager);

protected:
    bool hasEmptyDevice() const;
    unsigned int getEmptyDeviceIndex();
    unsigned int getDeviceIDNextEvent() const;

    const unsigned int numOfDevices_;
    Device ** devices;
};

#endif // DEVICEMANAGER_H
