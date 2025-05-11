#include "./WifiReceiver.h"
#include "../../Global_Constants.h"

WifiReceiver::WifiReceiver(const JsonDocument& receiverConfigurations)
{
    ssid = receiverConfigurations["ssid"].as<std::string>();
    password = receiverConfigurations["password"].as<std::string>();
    port = receiverConfigurations["port"].as<int>();
};

bool WifiReceiver::begin()
{
    if (WiFi.softAP(ssid.c_str(), password.c_str()))
    {
        server.begin(port);
        return true;
    } 
    else 
    {
        return false;
    }
}

bool WifiReceiver::connected()
{
    WiFiClient newClient = server.available();
    if (newClient) 
    {
        clients.push_back(newClient);
    }

    for (auto it = clients.begin(); it != clients.end();) 
    {
        if (!(*it).connected()) 
        {
            it = clients.erase(it);
        } 
        else 
        {
            ++it;
        }
    }
    
    return !clients.empty();
}

std::string WifiReceiver::read()
{
    if (connected()) 
    {
        for (auto& client : clients) 
        {
            if (client.available()) 
            {
                return std::string(client.readStringUntil(DATUM_DISCRIMINATOR).c_str());
            }
        }
    }
    return std::string(1, DATUM_DISCRIMINATOR);
}