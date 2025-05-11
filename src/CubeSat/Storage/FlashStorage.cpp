#include "../Global_Constants.h"
#include "FlashStorage.h"
#include <SD.h>
#include "SPIFFS.h"

FlashStorage::FlashStorage()
{
    isMounted = SPIFFS.begin();
};

bool FlashStorage::status()
{
    return isMounted;
};

// Loads configuration file from SPIFFS
JsonDocument* FlashStorage::readConfig()
{
    if (!SPIFFS.begin(true))
    {
        return nullptr;
    }

    File file = SPIFFS.open(CONFIG_FILE, "r");
    if (!file)
    {
        return nullptr;
    }

    String configs = file.readString();
    file.close();

    JsonDocument *doc;

    DeserializationError error = deserializeJson(*doc, configs);
    if (error)
    {
        return nullptr;
    }

    return doc;
};

void FlashStorage::writeConfig(const JsonDocument& config)
{
    File file = SPIFFS.open(CONFIG_FILE, "w");
    serializeJson(config, file);
    file.close();
};

void FlashStorage::logData(std::string data)
{
    File file = SPIFFS.open(LOG_FILE, "a");
    file.println(data.c_str());
    file.close();
};

void FlashStorage::logError(std::string error)
{
    File file = SPIFFS.open(ERROR_LOG_FILE, "a");
    file.println(error.c_str());
    file.close();
};