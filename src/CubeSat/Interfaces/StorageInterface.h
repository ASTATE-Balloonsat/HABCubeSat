#ifndef STORAGE_INTERFACE_H
#define STORAGE_INTERFACE_H

#include <string>
#include <ArduinoJson.h>

class IStorage
{
    public:
        virtual JsonDocument* readConfig() = 0; 
        virtual void writeConfig(const JsonDocument& config) = 0;
        virtual bool status() = 0;
        virtual void logData(std::string data) = 0;
        virtual void logError(std::string error) = 0;
        virtual ~IStorage() = default;
};

#endif