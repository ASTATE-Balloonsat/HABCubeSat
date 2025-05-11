// WiFiClientReceiver.h

#ifndef Flash_STORAGE_H
#define Flash_STORAGE_H

#include "../Interfaces/StorageInterface.h"
#include <ArduinoJson.h>

class FlashStorage : public IStorage
{
    public:
        FlashStorage();
        JsonDocument* readConfig() override; 
        void writeConfig(const JsonDocument& config) override;
        bool status() override;
        void logData(std::string data) override;
        void logError(std::string error) override;
    private:
        bool isMounted = false;
};

#endif
