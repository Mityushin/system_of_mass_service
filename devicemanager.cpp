#include "devicemanager.h"

DeviceManager::DeviceManager(
        const unsigned int numOfDevices
        )
    :
      numOfDevices_(numOfDevices)
{
    devices = new Device *[numOfDevices_];

    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        devices[i] = new Device(i);
    }
} //end DeviceManager constructor

DeviceManager::~DeviceManager()
{
    if (devices == nullptr)
    {
        return;
    }
    for (unsigned int i = 0; i < numOfDevices_; i++)
    {
        if (devices[i] != nullptr)
        {
            delete devices[i];
        }
    }
    delete[] devices;
}

void DeviceManager::putBid(Bid *bid)
{
    int index = getEmptyDeviceIndex();
    if (index < 0) {
        //throw
    } else {
        devices[index]->putBid(bid);
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
} //end DeviceManager destructor

unsigned int DeviceManager::getEmptyDeviceIndex()
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
