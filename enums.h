#ifndef ENUMS_H
#define ENUMS_H

enum BidStatus
{
    NEW,
    BUFFERED,
    RUNNED,
    COMPLETED,
    REJECTED
};

enum NextEvent
{
    GENERATE_BID,
    PUT_BID,
    COMPLETE_BID
};

#endif // ENUMS_H
