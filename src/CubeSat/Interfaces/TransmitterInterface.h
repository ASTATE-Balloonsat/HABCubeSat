#ifndef TRANSMITTER_INTERFACE_H
#define TRANSMITTER_INTERFACE_H

#include "./DeviceInterface.h"

class ITransmitter : public IDevice
{
    public:
        virtual void write(std::string data) = 0;
};

#endif