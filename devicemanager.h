#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "buffer.h"
#include "device.h"

class DeviceManager
{
public:
    DeviceManager(
            const unsigned int numOfDevices,
            const long double lambda
            );
    ~DeviceManager();

    void putBid(Bid *bid, const long double time);
    Bid *completeBid();

    friend std::ostream &operator<<(std::ostream &stream, const DeviceManager &deviceManager);

protected:
    bool hasEmptyDevice() const;
    bool hasBusyDevice() const;
    unsigned int getEmptyDeviceIndex() const;
    unsigned int getDeviceIDNextEvent() const;
    unsigned int getCompletedBidCount() const;
    long double getProcessingEndTime(unsigned int index) const;

    const unsigned int numOfDevices_;
    Device ** devices;
};

#endif // DEVICEMANAGER_H
