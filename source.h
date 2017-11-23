#ifndef SOURCE_H
#define SOURCE_H

#include "bid.h"

class Source
{
public:
    Source(
            const unsigned int ID,
            const long double alpha,
            const long double beta
            );
    Bid *generateBid();

    unsigned int getGeneratedBidCount() const;
    unsigned int getRejectedBidCount() const;
    long double getNextGenerateTime() const;

    void markRejected();

    friend std::ostream &operator<<(std::ostream &stream, const Source &source);

private:
    void updateGenerateTime();

    const unsigned int ID_;
    const long double alpha_;
    const long double beta_;

    unsigned int generatedBidCount_;
    unsigned int rejectedBidCount_;

    long double generateTime_;
};

#endif // SOURCE_H
