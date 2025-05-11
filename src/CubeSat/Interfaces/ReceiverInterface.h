#ifndef RECEIVER_INTERFACE_H
#define RECEIVER_INTERFACE_H

#include "./DeviceInterface.h"

class IReceiver : public IDevice
{
    public:
        virtual std::string read() = 0;
};

#endif