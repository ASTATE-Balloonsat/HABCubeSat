#include "WifiReceiverFactory.h"
#include "../../Receivers/Wifi/WifiReceiver.h"

std::unique_ptr<IReceiver> WifiReceiverFactory::createDevice(const JsonDocument& config)
{
    return std::unique_ptr<WifiReceiver>(new WifiReceiver(config));
};