#ifndef DEVICE_H
#define DEVICE_H

#include "bid.h"

class Device
{
public:
    Device(
            const unsigned int ID,
            const long double lambda
            );

    ~Device();

    void putBid(Bid *bid, const long double time);
    Bid *completeBid();
    const Bid *shareBid() const;

    bool isBusy() const;

    long double getWorkTime() const;
    long double getProcessingEndTime() const;
    unsigned int getCompletedBidCount() const;

    friend std::ostream &operator<<(std::ostream &stream, const Device &device);

private:
    void updateProcessingTime(const long double time);

    const unsigned int ID_;
    const long double lambda_;

    unsigned int completedBidCount_;
    long double workTime_;
    long double processingEndTime_;

    Bid *bid_;
};

#endif // DEVICE_H
