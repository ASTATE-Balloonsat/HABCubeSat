#include "SdCardStorageFactory.h"
#include "../Storage/SdCardStorage.h"

std::unique_ptr<IStorage> SdCardStorageFactory::createStorage()
{
    return std::unique_ptr<IStorage>(new SdCardStorage());
};