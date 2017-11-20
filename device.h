#ifndef DEVICE_H
#define DEVICE_H

#include "bid.h"

class Device
{
public:
    Device(
            const unsigned int ID,
            const long double processingTime = 0 //TODO: FIX IT!!!
            );

    ~Device();

    void putBid(Bid *bid);
    Bid *completeBid();

    bool isBusy() const;
    bool isBusy(const long double currentTime) const;

    long double getProcessingStartTime() const;
    long double getProcessingEndTime() const;

    friend std::ostream &operator<<(std::ostream &stream, const Device &device);

private:
    long double updateProcessingTime();

    const unsigned int ID_;

    long double processingTime_;
    long double processingStartTime_;
    long double processingEndTime_;

    Bid *bid_;
};

#endif // DEVICE_H
