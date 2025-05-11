#ifndef FLASH_STORAGE_FACTORY_H
#define FLASH_STORAGE_FACTORY_H

#include "../Interfaces/Factory/StorageFactoryInterface.h"

class FlashStorageFactory : public IStorageFactory
{
    public:
        std::unique_ptr<IStorage> createStorage() override;
};

#endif