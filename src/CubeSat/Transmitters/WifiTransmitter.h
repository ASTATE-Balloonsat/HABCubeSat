// WiFiClientReceiver.h

#ifndef WIFI_TRANSMITTER_H
#define WIFI_TRANSMITTER_H

#include "../Interfaces/TransmitterInterface.h"
#include <WiFi.h>
#include <ArduinoJson.h>
#include <vector>

class WifiTransmitter: public ITransmitter
{
    public:
        WifiTransmitter(const JsonDocument& transmitterConfigurations);
        bool begin() override;
        bool connected() override;
        void write(std::string data) override;
    
    private:
        std::string ssid;
        std::string password;
        std::string host;
        int port;
        WiFiClient  client;
};

#endif
