#include "./WifiTransmitter.h"

WifiTransmitter::WifiTransmitter(const JsonDocument& transmitterConfigurations)
{
    ssid = transmitterConfigurations["ssid"].as<std::string>();
    password = transmitterConfigurations["password"].as<std::string>();
    host = transmitterConfigurations["host"].as<std::string>();
    port = transmitterConfigurations["port"].as<int>();
};

bool WifiTransmitter::begin()
{
    WiFi.begin(ssid.c_str(), password.c_str());
    client.connect(host.c_str(), port);
    return client.available();
};

bool WifiTransmitter::connected()
{
    return client.connected();
};

void WifiTransmitter::write(std::string data)
{
    if (connected()) 
    {
        client.println(data.c_str());
    }
};