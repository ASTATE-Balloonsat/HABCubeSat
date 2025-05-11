#include "../Global_Constants.h"
#include "SdCardStorage.h"
#include <SD.h>

SdCardStorage::SdCardStorage()
{
    isMounted = SD.begin();
};

bool SdCardStorage::status()
{
    return isMounted;
};

// Loads configuration file from the SD card
JsonDocument* SdCardStorage::readConfig()
{
    File file = SD.open(CONFIG_FILE);
    String fileContent = file.readString();
    file.close();

    JsonDocument* doc = new JsonDocument;
    DeserializationError error = deserializeJson(*doc, fileContent);

    if (!error)
    {
        return doc;
    }
    
    return nullptr;
};

void SdCardStorage::writeConfig(const JsonDocument& config)
{
    File file = SD.open(CONFIG_FILE, FILE_WRITE);
    file.print(config.as<const char*>());
    file.close();
};

void SdCardStorage::logData(std::string data)
{
    File file = SD.open(LOG_FILE, FILE_APPEND);
    file.println(data.c_str());
    file.close();
};

void SdCardStorage::logError(std::string error)
{
    File file = SD.open(ERROR_LOG_FILE, FILE_APPEND);
    file.println(error.c_str());
    file.close();
};