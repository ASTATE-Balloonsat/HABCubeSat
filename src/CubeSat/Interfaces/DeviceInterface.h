#ifndef DEVICE_INTERFACE_H
#define DEVICE_INTERFACE_H

#include <string>

class IDevice
{
    public:
        virtual bool begin() = 0; // Initialize the receiver
        virtual bool connected() = 0; // Check if data is available
        virtual ~IDevice() = default;
};

#endif 