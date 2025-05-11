#include "../../Global_Constants.h"
#include "./SerialReceiver.h"

SerialReceiver::SerialReceiver(const JsonDocument& receiverConfigurations)
{
    baudRate = receiverConfigurations["baudRate"].as<int>();
}

bool SerialReceiver::begin()
{
    Serial.begin(baudRate);

    if (!Serial)
    {
        return true;
    } 
    
    return false;
}

bool SerialReceiver::connected()
{
    return Serial;
}

std::string SerialReceiver::read()
{
    if (connected()) 
    {
        std::string stream = Serial.readStringUntil(MODULE_DISCRIMINATOR).c_str();
        stream += DEVICE_DISCRIMINATOR;
        return stream;
    }
    return std::string(1, DEVICE_DISCRIMINATOR);
}