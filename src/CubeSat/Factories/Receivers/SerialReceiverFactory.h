#ifndef SERIAL_RECEIVER_FACTORY
#define SERIAL_RECEIVER_FACTORY

#include "../../Interfaces/Factory/ReceiverFactoryInterface.h"

class SerialReceiverFactory : public IReceiverFactory
{
    public:
        std::unique_ptr<IReceiver> createDevice(const JsonDocument& config) override;
};

#endif