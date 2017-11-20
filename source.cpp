#include "source.h"

Source::Source(const unsigned int ID)
    :
      ID_(ID),
      bidCount_(0)
{} //end Source constructor

Bid *Source::generateBid(long double time)
{
    return new Bid(time, ++bidCount_, ID_);
}

unsigned int Source::getBidCount() const
{
    return bidCount_;
}

unsigned int Source::getRejectedBidCount() const
{
    return rejectedBidCount_;
}

long double Source::getGenerateTime() const
{
    return generateTime_;
}

void Source::markRejected()
{
    rejectedBidCount_++;
}

std::ostream &operator<<(std::ostream &stream, const Source &source)
{
    stream << "source #" << source.ID_ << " ";
    stream << "bidCount " << source.bidCount_ << std::endl;
    return stream;
}
