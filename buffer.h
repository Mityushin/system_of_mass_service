#ifndef BUFFER_H
#define BUFFER_H

#include "bid.h"
#include "smooptions.h"

class Buffer
{
public:
    Buffer(const unsigned int capacity);
    void push(Bid *bid);
    Bid *pop();

    friend std::ostream &operator<<(std::ostream &stream, const Buffer &buffer);

private:
    const unsigned int capacity;
    unsigned int size;

    bool isFull() const;
    int getPushIndex() const;
    int getPopIndex() const;

    Bid **bids;
};

#endif // BUFFER_H
