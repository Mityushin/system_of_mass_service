#include "devicemanager.h"

DeviceManager::DeviceManager(
        Buffer * const buffer,
        const unsigned int numOfDevices
        )
    :
      buffer_(buffer),
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
} //end DeviceManager destructor

std::ostream &operator<<(std::ostream &stream, const DeviceManager &deviceManager)
{
    stream << "DeviceManager" << std::endl;
    stream << "  devices: " << deviceManager.numOfDevices_ << std::endl;
    for (unsigned int i = 0; i < deviceManager.numOfDevices_; i++)
    {
        stream << "    " << *deviceManager.devices[i];
    }
    stream << "  buffer: " << deviceManager.buffer_ << std::endl;
    deviceManager.devices[0] = nullptr;
    return stream;
}
