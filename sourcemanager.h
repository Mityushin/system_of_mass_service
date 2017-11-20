#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include "buffer.h"
#include "source.h"

class SourceManager
{
public:
    SourceManager(
            const unsigned int numOfSources
            );
    ~SourceManager();

    Bid * generateBid(long double time);
    void markRejected(Bid *bid);

    friend std::ostream &operator<<(std::ostream &stream, const SourceManager &sourceManager);

protected:
    unsigned int getSourceIDNextEvent() const;

    const unsigned int numOfSources_;

    Source **sources;
};

#endif // SOURCEMANAGER_H
