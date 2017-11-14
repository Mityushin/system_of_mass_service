#include "buffer.h"

Buffer::Buffer(const unsigned int capacity)
    :
      capacity_(capacity),
      size_(0)
{
    bids = new Bid *[capacity_];
    for (unsigned int i = 0; i < capacity_; i++)
    {
        bids[i] = nullptr;
    }
}

void Buffer::push(Bid *bid)
{
    if (size_ >= capacity_) {
        bid->makeRejected();
    } else {
        bid->makeBuffered();
        bids[getPushIndex()] = bid;
        size_++;
    }
}

Bid *Buffer::pop()
{
    if (size_ <= 0) {
//        throw;
        return nullptr;
    } else {
        int index = getPopIndex();
        Bid *result = bids[index];
        bids[index] = nullptr;
        size_--;
        return result;
    }
}

int Buffer::getPushIndex() const
{
    for (unsigned int i = 0; i < capacity_; i++)
    {
        if (bids[i] == nullptr)
        {
            return i;
        }
    }
    return -1;
}

int Buffer::getPopIndex() const
{
    unsigned int i = 0;
    for (; bids[i] == nullptr; i++) {}

    int priorityIndex = i;

    for (; i < capacity_; i++)
    {
        if (bids[i] == nullptr)
        {
            continue;
        }

        if (bids[i]->getSourceID() < bids[priorityIndex]->getSourceID())
        {
            priorityIndex = i;
        }
    }
    return priorityIndex;
}

std::ostream &operator<<(std::ostream &stream, const Buffer &buffer)
{
    stream << "buffer ";
    stream << "capacity:" << buffer.capacity_ << " ";
    stream << "size:" << buffer.size_ << " ";
    for (unsigned int i = 0; i < buffer.capacity_; i++)
    {
        stream << "{" << i << ", " << buffer.bids[i] << "} ";
    }
    stream << std::endl;
    return stream;
}
