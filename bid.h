#ifndef BID_H
#define BID_H

#include <iostream>
#include "enums.h"

class Bid
{
public:
    Bid(
            const long double timeGeneration,
            const unsigned int serialNum,
            const unsigned int sourceID
            );

    long double getTimeGeneration() const;
    unsigned int getSerialNum() const;
    unsigned int getSourceID() const;

    BidStatus getStatus() const;

    bool isNew() const;
    bool isBuffered() const;
    bool isRunned() const;
    bool isCompleted() const;
    bool isRejected() const;

    void makeBuffered();
    void makeRunned();
    void makeCompleted();
    void makeRejected();

    friend std::ostream &operator<<(std::ostream &stream, const Bid &bid);

private:
    BidStatus status_;
    const long double timeGeneration_;
    const unsigned int serialNum_;
    const unsigned int sourceID_;
};

#endif // BID_H
