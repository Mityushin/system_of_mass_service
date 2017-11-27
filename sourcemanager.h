#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include "source.h"

class SourceManager
{
public:
    SourceManager(
            const unsigned int numOfSources,
            const long double alpha,
            const long double beta
            );
    ~SourceManager();

    Bid * generateBid();
    void markRejected(Bid *bid);

    friend std::ostream &operator<<(std::ostream &stream, const SourceManager &sourceManager);

protected:
    unsigned int getSourceIDNextEvent() const;
    unsigned int getGeneratedBidCount() const;
    unsigned int getRejectedBidCount() const;

    const unsigned int numOfSources_;

    Source **sources;
};

#endif // SOURCEMANAGER_H
