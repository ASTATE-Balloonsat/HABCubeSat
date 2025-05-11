#include "Ms8607ReceiverFactory.h"
#include "../../Receivers/Sensors/Temperature/Ms8607Receiver.h"

std::unique_ptr<IReceiver> Ms8607ReceiverFactory::createDevice(const JsonDocument& config)
{
    return std::unique_ptr<Ms8607Receiver>(new Ms8607Receiver(config));
};