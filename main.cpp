#include <iostream>
#include "bid.h"
#include "buffer.h"
#include "device.h"
#include "source.h"

int main()
{
    Source source = Source(1);
    std::cout << source << std::endl;

    Bid *bid = source.getBid(0.5);
    std::cout << *bid << std::endl;

    Buffer buffer = Buffer(5);
    std::cout << buffer << std::endl;

    buffer.push(bid);
    std::cout << buffer << std::endl;

    bid = source.getBid(0.6);
    std::cout << *bid << std::endl;
    std::cout << source << std::endl;
    buffer.push(bid);
    std::cout << buffer << std::endl;

    Device device = Device(1);
    std::cout << device << std::endl;

    bid = buffer.pop();
    device.putBid(bid, bid->getTimeGeneration());
    std::cout << buffer << std::endl;
    std::cout << device << std::endl;

    device.completeBid();
    bid = buffer.pop();
    device.putBid(bid, bid->getTimeGeneration());
    std::cout << buffer << std::endl;
    std::cout << device << std::endl;

    return 0;
}
