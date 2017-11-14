#ifndef BUFFER_H
#define BUFFER_H

#include "bid.h"
#include "defaultoptions.h"

class Buffer
{
public:
    Buffer(const unsigned int capacity = DEFAULT_BUFFER_CAPACITY);
    void push(Bid *bid);
    Bid *pop();

    friend std::ostream &operator<<(std::ostream &stream, const Buffer &buffer);

private:
    const unsigned int capacity_;
    unsigned int size_;

    bool isFull() const;
    int getPushIndex() const;
    int getPopIndex() const;

    Bid **bids;
};

#endif // BUFFER_H
