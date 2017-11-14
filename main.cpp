#include <iostream>
#include "bid.h"
#include "buffer.h"

int main()
{
    Bid bid = Bid(0.0, 1, 1);
    std::cout << bid << std::endl;

    Buffer buffer = Buffer(5);
    std::cout << buffer << std::endl;

    for (int i = 0; i < 3; i++)
    {
        buffer.push(&bid);
        std::cout << buffer;
        std::cout << bid << std::endl;

    }

    for (int i = 0; i < 3; i++)
    {
        Bid *currBid = buffer.pop();
        std::cout << *currBid << std::endl;
        std::cout << buffer;
    }
    return 0;
}
