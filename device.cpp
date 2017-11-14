#include "device.h"

Device::Device(const unsigned int serialNum,
               const long double processingTime)
    :
      serialNum_(serialNum),
      processingTime_(processingTime),
      bid_(nullptr)
{} //end Device constructor

void Device::putBid(Bid *bid, long double time)
{
    if (bid_ != nullptr)
    {
        //throw
        return;
    }
    if (bid == nullptr)
    {
        //throw
        return;
    }

    bid_ = bid;
    bid_->makeRunned();
    processingStartTime_ = time;
    processingEndTime_ = time + updateProcessingTime();
}

Bid *Device::completeBid()
{
    if (bid_ == nullptr)
    {
        //throw
        return nullptr;
    }
    bid_->makeCompleted();
    Bid *result = bid_;
    bid_ = nullptr;
    return result;
}

bool Device::isBusy(const long double currentTime) const
{
    return (currentTime > processingStartTime_)
            && (currentTime < processingEndTime_)
            ;
}

bool Device::isBusy() const
{
    return bid_ != nullptr;
}

long double Device::getProcessingStartTime() const
{
    return processingStartTime_;
}

long double Device::getProcessingEndTime() const
{
    return processingEndTime_;
}

std::ostream &operator<<(std::ostream &stream, const Device &device)
{
    stream << "device #" << device.serialNum_ << " ";
    stream << "busy: " << device.isBusy() << " ";
    stream << "start: " << device.processingStartTime_ << " ";
    stream << "process: " << device.processingTime_ << " ";
    stream << "end: " << device.processingEndTime_ << " ";
    return stream;
}

long double Device::updateProcessingTime()
{
    processingTime_ += 1;
    return processingTime_;
}
