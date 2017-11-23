#include "sourcemanager.h"

SourceManager::SourceManager(
        const unsigned int numOfSources,
        const long double alpha,
        const long double beta
        )
    :
      numOfSources_(numOfSources)
{
    sources = new Source *[numOfSources_];

    for (unsigned int i = 0; i < numOfSources_; i++)
    {
        sources[i] = new Source(i, alpha, beta);
    }
} //end SourceManager constructor

SourceManager::~SourceManager()
{
    for (unsigned int i = 0; i < numOfSources_; i++)
    {
        delete sources[i];
    }
    delete[] sources;
} //end SourceManager destructor

Bid * SourceManager::generateBid()
{
    return sources[getSourceIDNextEvent()]->generateBid();
}

void SourceManager::markRejected(Bid *bid)
{
    sources[bid->getSourceID()]->markRejected();
    bid->makeRejected();
    delete bid;
}

unsigned int SourceManager::getSourceIDNextEvent() const
{
    unsigned int minIndex = 0;
    long double minTime = sources[0]->getNextGenerateTime();
    for (unsigned int i = 1; i < numOfSources_; i++)
    {
        if (sources[i]->getNextGenerateTime() < minTime)
        {
            minTime = sources[i]->getNextGenerateTime();
            minIndex = i;
        }
    }
    return minIndex;
}

unsigned int SourceManager::getGeneratedBidCount() const
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < numOfSources_; i++)
    {
        sum += sources[i]->getGeneratedBidCount();
    }
    return sum;
}

std::ostream &operator<<(std::ostream &stream, const SourceManager &sourceManager)
{
    stream << "SourceManager" << std::endl;
    stream << "  sources: " << sourceManager.numOfSources_ << std::endl;
    for (unsigned int i = 0; i < sourceManager.numOfSources_; i++)
    {
        stream << "    " << *sourceManager.sources[i];
    }
    return stream;
}
