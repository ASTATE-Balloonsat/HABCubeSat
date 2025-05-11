#include "FlashStorageFactory.h"
#include "../Storage/FlashStorage.h"

std::unique_ptr<IStorage> FlashStorageFactory::createStorage()
{
    return std::unique_ptr<IStorage>(new FlashStorage());
};