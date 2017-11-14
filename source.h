#ifndef SOURCE_H
#define SOURCE_H

#include "bid.h"

class Source
{
public:
    Source(const unsigned int ID);
    Bid *getBid(long double time);

    friend std::ostream &operator<<(std::ostream &stream, const Source &source);

private:
    const unsigned int ID_;
    unsigned int bidCount_;
};

#endif // SOURCE_H
