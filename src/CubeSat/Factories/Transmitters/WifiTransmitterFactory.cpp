#include "WifiTransmitterFactory.h"
#include "../../Transmitters/WifiTransmitter.h"

std::unique_ptr<ITransmitter> WifiTransmitterFactory::createDevice(const JsonDocument& config)
{
    return std::unique_ptr<ITransmitter>(new WifiTransmitter(config));
};