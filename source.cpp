#include "source.h"
#include <cstdlib>

Source::Source(
        const unsigned int ID,
        const long double alpha,
        const long double beta
        )
    :
      ID_(ID),
      alpha_(alpha),
      beta_(beta),
      generatedBidCount_(0),
      rejectedBidCount_(0),
      generateTime_(alpha + (beta - alpha) * ((double) rand() / RAND_MAX))
{} //end Source constructor

Bid *Source::generateBid()
{
    Bid *bid = new Bid(generateTime_, ++generatedBidCount_, ID_);
    updateGenerateTime();
    return bid;
}

unsigned int Source::getGeneratedBidCount() const
{
    return generatedBidCount_;
}

unsigned int Source::getRejectedBidCount() const
{
    return rejectedBidCount_;
}

long double Source::getNextGenerateTime() const
{
    return generateTime_;
}

void Source::markRejected()
{
    rejectedBidCount_++;
}

void Source::updateGenerateTime()
{
    generateTime_ += alpha_ + (beta_ - alpha_) * ((double) rand() / RAND_MAX);
}

std::ostream &operator<<(std::ostream &stream, const Source &source)
{
    stream << "source #" << source.ID_ << " ";
    stream << "(a:" << source.alpha_ << " ";
    stream << "b:" << source.beta_ << ") ";
    stream << "total: " << source.generatedBidCount_ << "(";
    stream << "r:" << source.rejectedBidCount_ << ") ";
    stream << "next: " << source.generateTime_ << std::endl;
    return stream;
}
