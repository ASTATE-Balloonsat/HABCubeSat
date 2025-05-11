#ifndef SERIAL_TRANSMITTER_FACTORY
#define SERIAL_TRANSMITTER_FACTORY

#include "../../Interfaces/Factory/TransmitterFactoryInterface.h"

class SerialTransmitterFactory : public ITransmitterFactory
{
    public:
        std::unique_ptr<ITransmitter> createDevice(const JsonDocument& config) override;
};

#endif