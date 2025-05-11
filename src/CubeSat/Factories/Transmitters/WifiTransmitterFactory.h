#ifndef WIFI_TRANSMITTER_FACTORY
#define WIFI_TRANSMITTER_FACTORY

#include "../../Interfaces/Factory/TransmitterFactoryInterface.h"

class WifiTransmitterFactory : public ITransmitterFactory
{
    public:
        std::unique_ptr<ITransmitter> createDevice(const JsonDocument& config) override;
};

#endif