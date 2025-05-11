#include "SerialReceiverFactory.h"
#include "../../Receivers/Serial/SerialReceiver.h"

std::unique_ptr<IReceiver> SerialReceiverFactory::createDevice(const JsonDocument& config)
{
    return std::unique_ptr<SerialReceiver>(new SerialReceiver(config));
};