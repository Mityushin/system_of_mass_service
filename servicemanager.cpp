#include "servicemanager.h"

ServiceManager::ServiceManager(
        const unsigned int bufferCapacity,
        const unsigned int numberOfSources,
        const unsigned int numberOfDevices
        )
    :
      SourceManager(numberOfSources),
      DeviceManager(numberOfDevices),
      buffer_(new Buffer(bufferCapacity)),
      watcher_(new Watcher(this))
{} //end ServiceManager constructor

ServiceManager::~ServiceManager()
{
    if (buffer_ != nullptr)
    {
        delete buffer_;
    }
    if (watcher_ != nullptr)
    {
        delete watcher_;
    }
}

void ServiceManager::executeStep()
{
    switch (getNextEvent()) {
    case NextEvent::GENERATE_BID: {
        Bid * bid = generateBid(currentTime_);
        Bid * answer = buffer_->push(bid);
        if (bid != answer) {
            //generated bid rejected
            markRejected(bid);
        } else if (answer != nullptr) {
            //bid from the buffer rejected
            markRejected(answer);
        } else {
            //bid buffered
        }
        break;
    }
    case NextEvent::PUT_BID: {
        putBid(buffer_->pop());
        break;
    }
    case NextEvent::COMPLETE_BID: {
        Bid * bid = completeBid();
        break;
    }
    default:
        break; //unreachable statement
    }
}

Watcher * ServiceManager::getCurrentState() const
{
    return watcher_;
}

NextEvent ServiceManager::getNextEvent() const
{
    if (!buffer_->isEmpty() && hasEmptyDevice())
    {
        return NextEvent::PUT_BID;
    }

    long double sourceTime = sources[getSourceIDNextEvent()]->getGenerateTime();
    long double deviceTime = devices[getDeviceIDNextEvent()]->getProcessingEndTime();

    if (sourceTime < deviceTime) {
        return NextEvent::GENERATE_BID;
    } else {
        return NextEvent::COMPLETE_BID;
    }
}

std::ostream &operator<<(std::ostream &stream, const ServiceManager &serviceManager)
{
    stream << "ServiceManager" << std::endl;
    stream << "  " << *serviceManager.buffer_ << std::endl;

//    stream << "  " << *serviceManager.sourceManager_ << std::endl;
    stream << "  parent SourceManager" << std::endl;
    stream << "  sources: " << serviceManager.numOfSources_ << std::endl;
    for (unsigned int i = 0; i < serviceManager.numOfSources_; i++)
    {
        stream << "    " << *serviceManager.sources[i];
    }
    stream << std::endl;

//    stream << "  " << *serviceManager.deviceManager_ << std::endl;
    stream << "  parent DeviceManager" << std::endl;
    stream << "  devices: " << serviceManager.numOfDevices_ << std::endl;
    for (unsigned int i = 0; i < serviceManager.numOfDevices_; i++)
    {
        stream << "    " << *serviceManager.devices[i];
    }
    return stream;
}
