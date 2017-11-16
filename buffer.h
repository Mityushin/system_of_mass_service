#ifndef BUFFER_H
#define BUFFER_H

#include "bid.h"

class Buffer
{
public:
    Buffer(const unsigned int capacity);
    ~Buffer();
    void push(Bid *bid);
    Bid *pop();

    friend std::ostream &operator<<(std::ostream &stream, const Buffer &buffer);

private:
    bool isFull() const;
    int getPushIndex() const;
    int getPopIndex() const;

    const unsigned int capacity_;
    unsigned int size_;
    Bid **bids;
};

#endif // BUFFER_H
