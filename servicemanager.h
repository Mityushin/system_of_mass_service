#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "buffer.h"
#include "sourcemanager.h"
#include "devicemanager.h"
#include "defaultoptions.h"
#include "enums.h"
#include "watcher.h"

class Watcher;

class ServiceManager
        :
        private SourceManager,
        private DeviceManager
{
public:
    ServiceManager(
            const unsigned int bufferCapacity = DEFAULT_BUFFER_CAPACITY,
            const unsigned int numberOfSources = DEFAULT_NUMBER_OF_SOURCES,
            const unsigned int numberOfDevices = DEFAULT_NUMBER_OF_DEVICES,
            const long double alpha = DEFAULT_ALPHA,
            const long double beta = DEFAULT_BETA,
            const long double lambda = DEFAULT_LAMBDA
            );
    ~ServiceManager();

    void executeStep();
    void execute(
            const unsigned int numOfBids = DEFAULT_NUMBER_OF_BIDS
            );
    Watcher *getCurrentState() const;

    friend std::ostream &operator<<(std::ostream &stream, const ServiceManager &serviceManager);

private:
    NextEvent getNextEvent() const;
    void shutDown();
    bool isShuttingDown() const;
    bool isLastBidDone() const;

    Buffer * const buffer_;
    Watcher * const watcher_;

    long double currentTime_;
    unsigned int rejectedBidCount_;

    bool flagShutDown_;
    bool flagLastBidDone_;

    friend class Watcher;
};

#endif // SERVICEMANAGER_H
