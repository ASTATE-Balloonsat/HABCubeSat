#ifndef RECEIVER_FACTORY_INTERFACE_H
#define RECEIVER_FACTORY_INTERFACE_H

#include "../ReceiverInterface.h"
#include <memory>
#include <ArduinoJson.h>

class IReceiverFactory 
{
    public:
        virtual std::unique_ptr<IReceiver> createDevice(const JsonDocument& config) = 0;
        virtual ~IReceiverFactory() = default;
};

#endif