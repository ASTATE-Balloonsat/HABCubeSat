#include "SerialTransmitterFactory.h"
#include "../../Transmitters/SerialTransmitter.h"

std::unique_ptr<ITransmitter> SerialTransmitterFactory::createDevice(const JsonDocument& config)
{
    return std::unique_ptr<ITransmitter>(new SerialTransmitter(config));
};