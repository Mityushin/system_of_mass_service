#include "bid.h"

Bid::Bid(const long double timeGeneration_,
         const unsigned int serialNum_,
         const unsigned int sourceID_)
    :
      status_(BidStatus::NEW),
      timeGeneration_(timeGeneration_),
      serialNum_(serialNum_),
      sourceID_(sourceID_)
{} //end Bid constructor

unsigned int Bid::getTimeGeneration() const
{
    return timeGeneration_;
}

unsigned int Bid::getSerialNum() const
{
    return serialNum_;
}

unsigned int Bid::getSourceID() const
{
    return sourceID_;
}

BidStatus Bid::getStatus() const
{
    return status_;
}

bool Bid::isNew() const
{
    return status_ == BidStatus::NEW;
}

bool Bid::isBuffered() const
{
    return status_ == BidStatus::BUFFERED;
}

bool Bid::isRunned() const
{
    return status_ == BidStatus::RUNNED;
}

bool Bid::isCompleted() const
{
    return status_ == BidStatus::COMPLETED;
}

bool Bid::isRejected() const
{
    return status_ == BidStatus::REJECTED;
}

void Bid::makeBuffered()
{
    status_ = BidStatus::BUFFERED;
}

void Bid::makeRunned()
{
    status_ = BidStatus::RUNNED;
}

void Bid::makeCompleted()
{
    status_ = BidStatus::COMPLETED;
}

void Bid::makeRejected()
{
    status_ = BidStatus::REJECTED;
}


std::ostream &operator<<(std::ostream &stream, const Bid &bid)
{
    stream << "bid #" << bid.serialNum_<< " ";
    stream << "from source #" << bid.sourceID_ << " ";
    stream << "at " << bid.timeGeneration_ << " ";
    stream << "status: " << bid.status_ << std::endl;
    return stream;
}
