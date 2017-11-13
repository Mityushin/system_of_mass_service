#include "simpleapplication.h"

unsigned int SimpleApplication::getTimeGeneration() const
{
    return timeGeneration_;
}

unsigned int SimpleApplication::getSerialNum() const
{
    return numSerial_;
}

unsigned int SimpleApplication::getSourceNum() const
{
    return numSource_;
}



std::ostream &operator<<(std::ostream &stream, const SimpleApplication &app)
{
    stream << "app #" << app.numSerial_<< " ";
    stream << "from #" << app.numSource_ << " ";
    stream << "at " << app.timeGeneration_ << std::endl;
    return stream;
}
