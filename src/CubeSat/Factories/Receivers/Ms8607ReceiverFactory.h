#ifndef Ms8607_RECEIVER_FACTORY
#define Ms8607_RECEIVER_FACTORY

#include "../../Interfaces/Factory/ReceiverFactoryInterface.h"
#include "../../Receivers/Sensors/Temperature/MS8607Receiver.h"

class Ms8607ReceiverFactory : public IReceiverFactory
{
    public:
        std::unique_ptr<IReceiver> createDevice(const JsonDocument& config) override;
};

#endif