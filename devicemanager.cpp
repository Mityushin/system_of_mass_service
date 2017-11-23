#include "devicemanager.h"

DeviceManager::DeviceManager(
        const unsigned int numOfDevices,
        const long double lambda
        )
    :
      numOfDevices_(numOfDevices)
{
    devices = new Device *[numOfDevices_];

    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        devices[i] = new Device(i, lambda);
    }
} //end DeviceManager constructor

DeviceManager::~DeviceManager()
{
    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        delete devices[i];
    }
    delete[] devices;
} //end DeviceManager destructor

void DeviceManager::putBid(Bid *bid, const long double time)
{
    int index = getEmptyDeviceIndex();
    if (index < 0) {
        //throw
    } else {
        devices[index]->putBid(bid, time);
    }
}

Bid *DeviceManager::completeBid()
{
    return devices[getDeviceIDNextEvent()]->completeBid();
}

bool DeviceManager::hasEmptyDevice() const
{
    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        if (!devices[i]->isBusy())
        {
            return true;
        }
    }
    return false;
}

bool DeviceManager::hasBusyDevice() const
{
    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        if (devices[i]->isBusy())
        {
            return true;
        }
    }
    return false;
}

unsigned int DeviceManager::getEmptyDeviceIndex() const
{
    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        if (!devices[i]->isBusy())
        {
            return i;
        }
    }
    //throw
    return -1;
}

unsigned int DeviceManager::getDeviceIDNextEvent() const
{
    unsigned int minIndex = 0;
    while (!devices[minIndex]->isBusy())
    {
        minIndex++;
        if (minIndex >= numOfDevices_)
        {
            //throw
            return -1;
        }
    }
    long double minTime = devices[minIndex]->getProcessingEndTime();
    for (unsigned int i = minIndex + 1; i < numOfDevices_; i++)
    {
        if (devices[i]->isBusy()
                && devices[i]->getProcessingEndTime() < minTime
                )
        {
            minTime = devices[i]->getProcessingEndTime();
            minIndex = i;
        }
    }
    return minIndex;
}

unsigned int DeviceManager::getCompletedBidCount() const
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        sum += devices[i]->getCompletedBidCount();
    }
    return sum;
}

long double DeviceManager::getProcessingEndTime(unsigned int index) const
{
    return devices[index]->getProcessingEndTime();
}

std::ostream &operator<<(std::ostream &stream, const DeviceManager &deviceManager)
{
    stream << "DeviceManager" << std::endl;
    stream << "  devices: " << deviceManager.numOfDevices_ << std::endl;
    for (unsigned int i = 0; i < deviceManager.numOfDevices_; i++)
    {
        stream << "    " << *deviceManager.devices[i];
    }
    return stream;
}
