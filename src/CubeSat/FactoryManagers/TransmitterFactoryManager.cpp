#include "TransmitterFactoryManager.h"
#include "../Factories/Transmitters/WifiTransmitterFactory.h"
#include "../Factories/Transmitters/SerialTransmitterFactory.h"

std::unordered_map<std::string, std::unique_ptr<ITransmitterFactory>>& TransmitterFactoryManager::getTransmitterFactories() {
    static std::unordered_map<std::string, std::unique_ptr<ITransmitterFactory>> transmitterFactories;
    
    if (transmitterFactories.empty()) {  // Only initialize once
        transmitterFactories["wifi"] = std::unique_ptr<ITransmitterFactory>(new WifiTransmitterFactory());
        transmitterFactories["serial"] = std::unique_ptr<ITransmitterFactory>(new SerialTransmitterFactory());
    }

    return transmitterFactories;
}

ITransmitterFactory* TransmitterFactoryManager::getFactory(const std::string& type) {

    auto& factories = getTransmitterFactories();

    auto it = factories.find(type);
    if (it != factories.end()) {
        return it->second.get();
    }

    return nullptr;
}


std::vector<std::unique_ptr<ITransmitter>> TransmitterFactoryManager::buildTransmitters(const JsonArray& transmitterConfigs)
{
    std::vector<std::unique_ptr<ITransmitter>> transmitters;

    for (JsonVariant transmitterConfig : transmitterConfigs)
    {
        JsonDocument doc;
        doc.set(transmitterConfig["config"]);

        ITransmitterFactory* factory = getFactory(transmitterConfig["type"]);

        std::unique_ptr<ITransmitter> transmitter = factory->createDevice(doc);
        transmitters.push_back(std::move(transmitter));
    }

    return transmitters;
};