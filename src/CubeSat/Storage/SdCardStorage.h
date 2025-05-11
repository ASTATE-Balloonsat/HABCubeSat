// WiFiClientReceiver.h

#ifndef SD_CARD_STORAGE_H
#define SD_CARD_STORAGE_H

#include "../Interfaces/StorageInterface.h"
#include <ArduinoJson.h>

class SdCardStorage: public IStorage
{
    public:
        SdCardStorage();
        JsonDocument* readConfig() override; 
        bool status() override;
        void writeConfig(const JsonDocument& config) override;
        void logData(std::string data) override;
        void logError(std::string error) override;
    private:
        bool isMounted = false;
};

#endif
