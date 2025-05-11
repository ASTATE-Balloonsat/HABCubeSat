#ifndef TRANSMITTER_FACTORY_MANAGER_H
#define TRANSMITTER_FACTORY_MANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include "../Interfaces/Factory/TransmitterFactoryInterface.h"

class TransmitterFactoryManager
{
    public:
        TransmitterFactoryManager();
        static std::vector<std::unique_ptr<ITransmitter>> buildTransmitters(const JsonArray& transmitterConfigs);
    
    private:
        static ITransmitterFactory* getFactory(const std::string& type);
        static std::unordered_map<std::string, std::unique_ptr<ITransmitterFactory>>& getTransmitterFactories();
};

#endif