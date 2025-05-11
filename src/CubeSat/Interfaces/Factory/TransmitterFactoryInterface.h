#ifndef TRANSMITTER_FACTORY_INTERFACE_H
#define TRANSMITTER_FACTORY_INTERFACE_H

#include "../TransmitterInterface.h"
#include <memory>
#include <ArduinoJson.h>

class ITransmitterFactory 
{
    public:
        virtual std::unique_ptr<ITransmitter> createDevice(const JsonDocument& config) = 0;
        virtual ~ITransmitterFactory() = default;
};

#endif