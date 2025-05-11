#ifndef RECEIVER_FACTORY_MANAGER_H
#define RECEIVER_FACTORY_MANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include "../Interfaces/Factory/ReceiverFactoryInterface.h"

class ReceiverFactoryManager
{
    public:
        ReceiverFactoryManager();
        static std::vector<std::unique_ptr<IReceiver>> buildReceivers(const JsonArray& receiverConfigs);
    
    private:
        static IReceiverFactory* getFactory(const std::string& type);
        static std::unordered_map<std::string, std::unique_ptr<IReceiverFactory>>& getReceiverFactories();
};

#endif