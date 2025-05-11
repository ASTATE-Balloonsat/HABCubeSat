#ifndef MODULE_FACTORY_INTERFACE_H
#define MODULE_FACTORY_INTERFACE_H

#include <memory>
#include "../ModuleInterface.h"
#include <ArduinoJson.h>

class IModuleFactory
{
    public:
        virtual std::unique_ptr<IModule> createModule() = 0;
        virtual ~IModuleFactory() = default;
};

#endif