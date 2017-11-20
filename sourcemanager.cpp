#include "sourcemanager.h"

SourceManager::SourceManager(
        const unsigned int numOfSources
        )
    :
      numOfSources_(numOfSources)
{
    sources = new Source *[numOfSources_];

    for (unsigned int i = 0; i < numOfSources_; i++)
    {
        sources[i] = new Source(i);
    }
} //end SourceManager construstor

SourceManager::~SourceManager()
{
    if (sources == nullptr)
    {
        return;
    }
    for (unsigned int i = 0; i < numOfSources_; i++)
    {
        if (sources[i] != nullptr)
        {
            delete sources[i];
        }
    }
    delete[] sources;
}

Bid * SourceManager::generateBid(long double time)
{
    return sources[getSourceIDNextEvent()]->generateBid(time);
}

void SourceManager::markRejected(Bid *bid)
{
    sources[bid->getSourceID()]->markRejected();
    bid->makeRejected();
}

unsigned int SourceManager::getSourceIDNextEvent() const
{
    unsigned int minIndex = 0;
    long double minTime = sources[0]->getGenerateTime();
    for (unsigned int i = 1; i < numOfSources_; i++)
    {
        if (sources[i]->getGenerateTime() < minTime)
        {
            minTime = sources[i]->getGenerateTime();
            minIndex = i;
        }
    }
    return minIndex;
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
