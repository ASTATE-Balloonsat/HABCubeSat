#ifndef SERIAL_TRANSMITTER_H
#define SERIAL_TRANSMITTER_H

#include "../Interfaces/TransmitterInterface.h"
#include <ArduinoJson.h>

class SerialTransmitter : public ITransmitter
{
    public:
        SerialTransmitter(const JsonDocument& transmitterConfigurations);
        bool begin() override;
        bool connected() override;
        void write(std::string data) override;
    private:
        int baudRate;
};

#endif