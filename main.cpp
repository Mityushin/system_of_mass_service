#include <iostream>
#include "simpleapplication.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    SimpleApplication app(0.0, 1, 1);
    std::cout << app << app << std::endl;
    return 0;
}
