#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "buffer.h"
#include "device.h"

class DeviceManager
{
public:
    DeviceManager(
            Buffer * const buffer,
            const unsigned int numOfDevices
            );
    ~DeviceManager();

    void putBid();
    void completeBid();

    friend std::ostream &operator<<(std::ostream &stream, const DeviceManager &deviceManager);

private:
    int getEmptyDeviceIndex();

    Buffer * const buffer_;
    const unsigned int numOfDevices_;
    Device ** devices;
};

#endif // DEVICEMANAGER_H
