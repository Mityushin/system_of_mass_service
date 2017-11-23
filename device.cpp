#include "device.h"
#include <cstdlib>
#include <cmath>

Device::Device(const unsigned int ID,
               const long double lambda)
    :
      ID_(ID),
      lambda_(lambda),
      completedBidCount_(0),
      workTime_(0.0L),
      processingEndTime_(0.0L),
      bid_(nullptr)
{}

Device::~Device()
{
    delete bid_;
} //end Device constructor

void Device::putBid(Bid *bid, const long double time)
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

    updateProcessingTime(time);
    bid_ = bid;
    bid_->makeRunned();
}

Bid *Device::completeBid()
{
    if (bid_ == nullptr)
    {
        //throw
        return nullptr;
    }
    completedBidCount_++;
    bid_->makeCompleted();
    Bid *result = bid_;
    bid_ = nullptr;
    return result;
}

bool Device::isBusy() const
{
    return bid_ != nullptr;
}

long double Device::getWorkTime() const
{
    return workTime_;
}

long double Device::getProcessingEndTime() const
{
    return processingEndTime_;
}

unsigned int Device::getCompletedBidCount() const
{
    return completedBidCount_;
}

void Device::updateProcessingTime(const long double time)
{
    long double var = (log(rand() + 1) - log(RAND_MAX)) / (-lambda_);
    workTime_ += var;
    processingEndTime_ = time + var;

}

std::ostream &operator<<(std::ostream &stream, const Device &device)
{
    stream << "device #" << device.ID_ << " "
           << "(l:" << device.lambda_ << ") "
           << "total:" << device.completedBidCount_ << "("
           << device.workTime_ << ")";
    stream << "end:";
    if (device.isBusy()) {
        stream << device.processingEndTime_;
    } else {
        stream << "-";
    }
    stream << std::endl;
    return stream;
}
