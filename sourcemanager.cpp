#include "sourcemanager.h"

SourceManager::SourceManager(
        Buffer * const buffer,
        const unsigned int numOfSources
        )
    :
      numOfSources_(numOfSources),
      buffer_(buffer)
{
    sources = new Source *[numOfSources_];

    for (unsigned int i = 0; i < numOfSources_; i++)
    {
        sources[i] = new Source(i);
    }
}

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

std::ostream &operator<<(std::ostream &stream, const SourceManager &sourceManager)
{
    stream << "SourceManager" << std::endl;
    stream << "  sources: " << sourceManager.numOfSources_ << std::endl;
    for (unsigned int i = 0; i < sourceManager.numOfSources_; i++)
    {
        stream << "    " << *sourceManager.sources[i];
    }
    stream << "  buffer: " << sourceManager.buffer_ << std::endl;
    return stream;
} //end SourceManager construstor
