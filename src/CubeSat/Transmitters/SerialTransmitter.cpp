#include "SerialTransmitter.h"

SerialTransmitter::SerialTransmitter(const JsonDocument& transmitterConfigurations)
{
    baudRate = transmitterConfigurations["baudRate"].as<int>();
}

bool SerialTransmitter::begin() 
{
    Serial.begin(baudRate);
    return true;
}

bool SerialTransmitter::connected()
{
    return true;
};

void SerialTransmitter::write(std::string data)
{
    Serial.println(data.c_str());
};
