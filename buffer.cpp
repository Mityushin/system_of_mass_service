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
} //end Buffer constructor

Buffer::~Buffer()
{
    if (bids == nullptr)
    {
        return;
    }
    for (unsigned int i = 0; i < capacity_; i++)
    {
        if (bids[i] != nullptr)
        {
            delete bids[i];
        }
    }
    delete[] bids;
} //end Buffer destructor

Bid *Buffer::push(Bid *bid)
{
    if (isFull()) {
        bid->makeRejected();
        return bid;
    } else {
        bid->makeBuffered();
        bids[getPushIndex()] = bid;
        size_++;
        return nullptr;
    }
}

Bid *Buffer::pop()
{
    if (isEmpty()) {
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

bool Buffer::isEmpty() const
{
    return size_ == 0;
}

bool Buffer::isFull() const
{
    return size_ == capacity_;
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

        if (bids[i]->getSourceID() == bids[priorityIndex]->getSourceID())
        {
            if (bids[i]->getTimeGeneration() < bids[priorityIndex]->getTimeGeneration())
            {
                priorityIndex = i;
            }
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
    stream << "Buffer" << std::endl;
    stream << "  capacity:" << buffer.capacity_ << std::endl;
    stream << "  size:" << buffer.size_ << std::endl;
    stream << "    ";
    for (unsigned int i = 0; i < buffer.capacity_; i++)
    {
        stream << "{" << i << ", ";
        if (buffer.bids[i] != nullptr) {
            stream << *buffer.bids[i];
        } else {
            stream << "-";
        }
        stream << "} ";
    }
    stream << std::endl;
    return stream;
}
