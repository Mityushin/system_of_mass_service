#include "source.h"
#include "bid.h"

Source::Source(const unsigned int ID)
    :
      ID_(ID),
      bidCount_(0)
{} //end Source constructor

Bid *Source::getBid(long double time)
{
    return new Bid(time, ++bidCount_, ID_);
}

std::ostream &operator<<(std::ostream &stream, const Source &source)
{
    stream << "source #" << source.ID_ << " ";
    stream << "bidCount " << source.bidCount_ << std::endl;
    return stream;
}
