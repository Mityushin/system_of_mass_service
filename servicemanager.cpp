#include "servicemanager.h"

ServiceManager::ServiceManager(
        const unsigned int bufferCapacity,
        const unsigned int numberOfSources,
        const unsigned int numberOfDevices
        )
    :
      bufferCapacity_(bufferCapacity),
      numberOfSources_(numberOfSources),
      numberOfDevices_(numberOfDevices),
      buffer_(new Buffer(bufferCapacity_)),
      sourceManager_(new SourceManager(buffer_, numberOfSources_)),
      deviceManager_(new DeviceManager(buffer_, numberOfDevices_))
{} //end ServiceManager constructor

ServiceManager::~ServiceManager()
{
    if (deviceManager_ != nullptr)
    {
        delete deviceManager_;
    }
    if (sourceManager_ != nullptr)
    {
        delete sourceManager_;
    }
    if (buffer_ != nullptr)
    {
        delete buffer_;
    }
}

std::ostream &operator<<(std::ostream &stream, const ServiceManager &serviceManager)
{
    stream << "ServiceManager" << std::endl;
    stream << "  " << *serviceManager.buffer_ << std::endl;
    stream << "  " << *serviceManager.sourceManager_ << std::endl;
    stream << "  " << *serviceManager.deviceManager_ << std::endl;
    return stream;
}
