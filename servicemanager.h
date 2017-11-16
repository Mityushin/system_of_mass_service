#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "buffer.h"
#include "sourcemanager.h"
#include "devicemanager.h"
#include "defaultoptions.h"

class ServiceManager
{
public:
    ServiceManager(
            const unsigned int bufferCapacity = DEFAULT_BUFFER_CAPACITY,
            const unsigned int numberOfSources = DEFAULT_NUMBER_OF_SOURCES,
            const unsigned int numberOfDevices = DEFAULT_NUMBER_OF_DEVICES
            );
    ~ServiceManager();

    friend std::ostream &operator<<(std::ostream &stream, const ServiceManager &serviceManager);

private:
    const unsigned int bufferCapacity_;
    const unsigned int numberOfSources_;
    const unsigned int numberOfDevices_;

    Buffer * const buffer_;
    SourceManager * const sourceManager_;
    DeviceManager * const deviceManager_;
};

#endif // SERVICEMANAGER_H
