#ifndef STORAGE_FACTORY_INTERFACE_H
#define STORAGE_FACTORY_INTERFACE_H

#include <memory>
#include "../StorageInterface.h"
#include <ArduinoJson.h>

class IStorageFactory
{
    public:
        virtual std::unique_ptr<IStorage> createStorage() = 0;
        virtual ~IStorageFactory() = default;
};

#endif