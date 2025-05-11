#ifndef WIFI_RECEIVER_FACTORY
#define WIFI_RECEIVER_FACTORY

#include "../../Interfaces/Factory/ReceiverFactoryInterface.h"

class WifiReceiverFactory : public IReceiverFactory
{
    public:
        std::unique_ptr<IReceiver> createDevice(const JsonDocument& config) override;
};

#endif