#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include "buffer.h"
#include "source.h"

class SourceManager
{
public:
    SourceManager(
            Buffer * const buffer,
            const unsigned int numOfSources
            );
    ~SourceManager();
    void generateBid();

    friend std::ostream &operator<<(std::ostream &stream, const SourceManager &sourceManager);

private:
    const unsigned int numOfSources_;

    Buffer * const buffer_;
    Source **sources;
};

#endif // SOURCEMANAGER_H
