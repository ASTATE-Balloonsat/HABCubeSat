// WiFiClientReceiver.h

#ifndef WIFI_RECEIVER_H
#define WIFI_RECEIVER_H

#include "../../Interfaces/ReceiverInterface.h"
#include <WiFi.h>
#include <ArduinoJson.h>
#include <vector>

class WifiReceiver: public IReceiver
{
    public:
        WifiReceiver(const JsonDocument& receiverConfigurations);
        bool begin() override;
        bool connected() override;
        std::string read() override;
    
    private:
        std::string ssid;
        std::string password;
        int port;
        WiFiServer  server;
        std::vector<WiFiClient> clients;
};

#endif
