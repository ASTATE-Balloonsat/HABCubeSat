#ifndef MODULE_FACTORY_H
#define MODULE_FACTORY_H

#include "../Interfaces/Factory/ModuleFactoryInterface.h"
#include "../Interfaces/ReceiverInterface.h"
#include "../Interfaces/TransmitterInterface.h"
#include "../Modules/Module.h"
#include <vector>

class ModuleFactory : public IModuleFactory
{
    public:
        std::unique_ptr<IModule> createModule() override {return nullptr;};
        
        static std::unique_ptr<Module> createModule(bool isHub, 
            std::vector<std::unique_ptr<IReceiver>> receivers, 
            std::vector<std::unique_ptr<ITransmitter>> transmitters);
};

#endif