#ifndef SOURCE_H
#define SOURCE_H

#include "bid.h"

class Source
{
public:
    Source(const unsigned int ID);
    Bid *generateBid(long double time);

    unsigned int getBidCount() const;
    unsigned int getRejectedBidCount() const;
    long double getGenerateTime() const;

    void markRejected();

    friend std::ostream &operator<<(std::ostream &stream, const Source &source);

private:
    long double generateTime_;
    const unsigned int ID_;
    unsigned int bidCount_;
    unsigned int rejectedBidCount_;
};

#endif // SOURCE_H
