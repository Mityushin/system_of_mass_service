#ifndef DEVICE_H
#define DEVICE_H

#include "bid.h"
#include "defaultoptions.h"

class Device
{
public:
    Device(
            const unsigned int serialNum,
            const long double processingTime = DEFAULT_PROCESSING_TIME
            );

    void putBid(Bid *bid, long double time);
    Bid *completeBid();

    bool isBusy() const;
    bool isBusy(const long double currentTime) const;

    long double getProcessingStartTime() const;
    long double getProcessingEndTime() const;

    friend std::ostream &operator<<(std::ostream &stream, const Device &device);

private:
    long double updateProcessingTime();

    const unsigned int serialNum_;

    long double processingTime_;
    long double processingStartTime_;
    long double processingEndTime_;

    Bid *bid_;
};

#endif // DEVICE_H
