#ifndef ENUMS_H
#define ENUMS_H

#include <iostream>

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
    COMPLETE_BID,
    SHUTDOWN
};

//std::ostream &operator<<(std::ostream &stream, const BidStatus &status)
//{
//    switch (status) {
//    case NEW:
//        return stream << "NEW";
//    case BUFFERED:
//        return stream << "BUFFERED";
//    case RUNNED:
//        return stream << "RUNNED";
//    case COMPLETED:
//        return stream << "COMPLETED";
//    case REJECTED:
//        return stream << "REJECTED";
//    default:
//        return stream;
//    }
//}

//std::ostream &operator<<(std::ostream &stream, const NextEvent &event)
//{
//    switch (event) {
//    case GENERATE_BID:
//        return stream << "GENERATE_BID";
//    case PUT_BID:
//        return stream << "PUT_BID";
//    case COMPLETE_BID:
//        return stream << "COMPLETE_BID";
//    case SHUTDOWN:
//        return stream << "SHUTDOWN";
//    default:
//        return stream;
//    }
//}

#endif // ENUMS_H
