// WiFiClientReceiver.h

#ifndef SERIAL_RECEIVER_H
#define SERIAL_RECEIVER_H

#include "../../Interfaces/ReceiverInterface.h"
#include <ArduinoJson.h>

class SerialReceiver: public IReceiver
{
    public:
        SerialReceiver(const JsonDocument& receiverConfigurations);
        bool begin() override;
        bool connected() override;
        std::string read() override;
    
    private:
        int baudRate;
};

#endif
