#ifndef DEVICE_FACTORY_INTERFACE_H
#define DEVICE_FACTORY_INTERFACE_H

#include "../DeviceInterface.h"
#include <memory>
#include <ArduinoJson.h>

class IDeviceFactory 
{
    public:
        virtual std::unique_ptr<IDevice> createDevice(const JsonDocument& config) = 0;
        virtual ~IDeviceFactory() = default;
};

#endif