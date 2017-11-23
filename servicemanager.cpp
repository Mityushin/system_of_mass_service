#include "servicemanager.h"

ServiceManager::ServiceManager(const unsigned int bufferCapacity,
        const unsigned int numberOfSources,
        const unsigned int numberOfDevices,
        const long double alpha,
        const long double beta,
        const long double lambda
        )
    :
      SourceManager(numberOfSources, alpha, beta),
      DeviceManager(numberOfDevices, lambda),
      buffer_(new Buffer(bufferCapacity)),
      watcher_(new Watcher(this)),
      currentTime_(0.0L),
      rejectedBidCount_(0),
      flagShutDown_(false),
      flagLastBidDone_(false)
{} //end ServiceManager constructor

ServiceManager::~ServiceManager()
{
    delete buffer_;
    delete watcher_;
}

void ServiceManager::executeStep()
{
    switch (getNextEvent()) {
    case NextEvent::GENERATE_BID: {
        Bid * bid = generateBid();
        currentTime_ = bid->getTimeGeneration();
        Bid * answer = buffer_->push(bid);
        if (answer != nullptr) {
            //bid rejected
            rejectedBidCount_++;
            if (answer->isRejected()) {
                markRejected(answer);
            } else {
                //throw
                delete bid;
            }
        }
        break;
    }
    case NextEvent::PUT_BID: {
        putBid(buffer_->pop(), currentTime_);
        break;
    }
    case NextEvent::COMPLETE_BID: {
        currentTime_ = getProcessingEndTime(getDeviceIDNextEvent());
        Bid * bid = completeBid();
        if (bid->isCompleted()) {
            delete bid;
        } else {
            //throw
            delete bid;
        }
        break;
    }
    case NextEvent::SHUTDOWN: {
        //the last bid done
        flagLastBidDone_ = true;
    }
    default:
        break; //unreachable statement
    }

    //debug
    std::cout << *this;
    std::cin.get();
}

void ServiceManager::execute(const unsigned int numOfBids)
{
    while (getGeneratedBidCount() < numOfBids)
    {
        executeStep();
    }

    shutDown();

    while (!isLastBidDone())
    {
        executeStep();
    }
    //TODO: FIX IT!!!
}

Watcher * ServiceManager::getCurrentState() const
{
    return watcher_;
}

NextEvent ServiceManager::getNextEvent() const
{
    if (!buffer_->isEmpty()
            && hasEmptyDevice())
    {
        return NextEvent::PUT_BID;
    }

    if (flagShutDown_
            && hasBusyDevice())
    {
        return NextEvent::COMPLETE_BID;
    }

    if (flagShutDown_)
    {
        return NextEvent::SHUTDOWN;
    }

    if (!hasBusyDevice()) {
        return NextEvent::GENERATE_BID;
    } else {
        long double sourceTime = sources[getSourceIDNextEvent()]->getNextGenerateTime();
        long double deviceTime = devices[getDeviceIDNextEvent()]->getProcessingEndTime();

//        std::cout << "SM sourceTime = " << sourceTime << " , deviceTime = " << deviceTime << std::endl;

        if (sourceTime < deviceTime) {
            return NextEvent::GENERATE_BID;
        } else {
            return NextEvent::COMPLETE_BID;
        }
    }
}

void ServiceManager::shutDown()
{
    flagShutDown_ = true;
}

bool ServiceManager::isShuttingDown() const
{
    return flagShutDown_;
}

bool ServiceManager::isLastBidDone() const
{
    return flagLastBidDone_;
}

std::ostream &operator<<(std::ostream &stream, const ServiceManager &serviceManager)
{
    stream << "ServiceManager" << std::endl;
    stream << "rejected: " << serviceManager.rejectedBidCount_ << std::endl;

    stream << "  sources: " << serviceManager.numOfSources_ << " ";
    stream << "generated: " << serviceManager.getGeneratedBidCount() << std::endl;
    for (unsigned int i = 0; i < serviceManager.numOfSources_; i++)
    {
        stream << "    " << *serviceManager.sources[i];
    }
    stream << std::endl;

    stream << *serviceManager.buffer_ << std::endl;

    stream << "  devices: " << serviceManager.numOfDevices_ << " ";
    stream << "completed: " << serviceManager.getCompletedBidCount() << std::endl;
    for (unsigned int i = 0; i < serviceManager.numOfDevices_; i++)
    {
        stream << "    " << *serviceManager.devices[i];
    }
    stream << "time: " << serviceManager.currentTime_;
    return stream;
}
