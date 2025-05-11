#include "ReceiverFactoryManager.h"
#include "../Factories/Receivers/WifiReceiverFactory.h"
#include "../Factories/Receivers/SerialReceiverFactory.h"
#include "../Factories/Receivers/Ms8607ReceiverFactory.h"

std::unordered_map<std::string, std::unique_ptr<IReceiverFactory>>& ReceiverFactoryManager::getReceiverFactories() {
    static std::unordered_map<std::string, std::unique_ptr<IReceiverFactory>> receiverFactories;
    
    if (receiverFactories.empty()) {  // Only initialize once
        receiverFactories["wifi"] = std::unique_ptr<IReceiverFactory>(new WifiReceiverFactory());
        receiverFactories["serial"] = std::unique_ptr<IReceiverFactory>(new SerialReceiverFactory());
        receiverFactories["ms8607"] = std::unique_ptr<IReceiverFactory>(new Ms8607ReceiverFactory());
    }

    return receiverFactories;
}

IReceiverFactory* ReceiverFactoryManager::getFactory(const std::string& type) {
    auto& factories = getReceiverFactories();
    
    auto it = factories.find(type);
    if (it != factories.end()) {
        return it->second.get();
    }

    return nullptr;
}

std::vector<std::unique_ptr<IReceiver>> ReceiverFactoryManager::buildReceivers(const JsonArray& receiverConfigs)
{
    std::vector<std::unique_ptr<IReceiver>> receivers;

    for (JsonVariant receiverConfig : receiverConfigs)
    {
        IReceiverFactory* factory = getFactory(receiverConfig["type"]);

        JsonDocument doc;
        doc.set(receiverConfig["config"]);

        std::unique_ptr<IReceiver> receiver = factory->createDevice(doc);

        receivers.push_back(std::move(receiver));
    }

    return receivers;
};