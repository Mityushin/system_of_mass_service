#include "buffer.h"

Buffer::Buffer(const unsigned int capacity = DEFAULT_BUFFER_CAPACITY)
    :
      capacity(capacity),
      size(0)
{
    bids = new Bid *[capacity];
    for (unsigned int i = 0; i < capacity; i++)
    {
        bids[i] = nullptr;
    }
}

void Buffer::push(Bid *bid)
{
    if (size >= capacity) {
        bid->makeRejected();
    } else {
        bid->makeBuffered();
        bids[getPushIndex()] = bid;
        size++;
    }
}

Bid *Buffer::pop()
{
    if (size <= 0) {
//        throw;
        return nullptr;
    } else {
        int index = getPopIndex();
        Bid *result = bids[index];
        bids[index] = nullptr;
        size--;
        return result;
    }
}

int Buffer::getPushIndex() const
{
    for (unsigned int i = 0; i < capacity; i++)
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

    for (; i < capacity; i++)
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
    stream << "capacity:" << buffer.capacity << " ";
    stream << "size:" << buffer.size << " ";
    for (unsigned int i = 0; i < buffer.capacity; i++)
    {
        stream << "{" << i << ", " << buffer.bids[i] << "} ";
    }
    stream << std::endl;
    return stream;
}
