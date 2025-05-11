#ifndef SD_CARD_STORAGE_FACTORY_H
#define SD_CARD_STORAGE_FACTORY_H

#include "../Interfaces/Factory/StorageFactoryInterface.h"

class SdCardStorageFactory : public IStorageFactory
{
    public:
        std::unique_ptr<IStorage> createStorage() override;
};

#endif