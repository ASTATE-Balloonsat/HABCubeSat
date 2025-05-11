#include "ModuleFactory.h"
#include "../Modules/Module.h"

std::unique_ptr<Module> ModuleFactory::createModule(bool isHub, 
    std::vector<std::unique_ptr<IReceiver>> receivers, 
    std::vector<std::unique_ptr<ITransmitter>> transmitters)
{
    return std::unique_ptr<Module>(new Module(isHub, std::move(receivers), std::move(transmitters)));
};