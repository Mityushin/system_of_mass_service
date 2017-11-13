#ifndef SIMPLEAPPLICATION_H
#define SIMPLEAPPLICATION_H

#include <iostream>

class SimpleApplication
{
public:
    SimpleApplication(
            const long double timeGeneration_,
            const unsigned int numSerial_,
            const unsigned int numSource_)
        :
          timeGeneration_(timeGeneration_),
          numSerial_(numSerial_),
          numSource_(numSource_)
    {}

    friend std::ostream &operator<<(std::ostream &stream, const SimpleApplication &app);

    const long double timeGeneration_;
    const unsigned int numSerial_;
    const unsigned int numSource_;

    unsigned int getTimeGeneration() const;
    unsigned int getSerialNum() const;
    unsigned int getSourceNum() const;
};

#endif // SIMPLEAPPLICATION_H
