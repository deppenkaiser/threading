#include "string.h"

#ifdef LINUX
int strcpy_s(char* pDestination, size_t nDestinantionSizeBytes, const char* pSource)
{
    int nCopied = -1;

    if (nDestinantionSizeBytes >= strlen(pSource))
    {
        strcpy(pDestination, pSource);
        nCopied = 0;
    }

    return nCopied;
}

int strcat_s(char* pDestination, size_t nDestinantionSizeBytes, const char* pSource)
{
    int nDone = -1;

    if ((strlen(pDestination) + strlen(pSource)) < nDestinantionSizeBytes)
    {
        strcat(pDestination, pSource);
        nDone = 0;
    }

    return nDone;
}
#endif
