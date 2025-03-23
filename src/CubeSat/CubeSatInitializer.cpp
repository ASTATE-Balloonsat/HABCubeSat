// CubeSatInitializer.cpp

/******************************************************************************
    CubeSatInitializer Class Implementation

    Purpose: 
        Contains methods for initializing a CubeSat module. This allows us to
        read data from the SD card and properly initialize the module as
        either a regular CubeSat module or a hub, or handle pre-flight
        configuration errors.
    Methods:
        initializeCubeSat:
            Creates a new CubeSat module object using data stored
            on the SD card.
    Helper Functions:
        initializeSDCard:
            Ensures SD card is connected and prepares it for read/write
        loadConfig:
            Loads an object from the configuration file stored on the SD card.
        errorBlink:
            Causes the primary LED to blink, indicating an unrecoverable
            error.
        buildDevice:
            Builds an individual device based on configurations.
        generateDeviceVector:
            Generates a vector of devices created by buildDevice.
******************************************************************************/

#include <SD.h>
#include <memory>
#include <cstring>
#include <ArduinoJson.h>
#include "CubeSatDevice.h"
#include "CubeSatModule.h"
#include "CubeSatInitializer.h"
#include "CubeSatHub.h"
#include "./Devices/Temperature/CubeSatMS8607.h"

// Constants
std::string CONFIG_FILE="/CubeSatConfig.json";

// Prototypes
void errorBlink();
JsonDocument loadConfig();
bool initializeSdCard();
CubeSatDevice* buildDevice(const char* deviceType, int deviceId);
std::vector<CubeSatDevice*> generateDeviceVector(JsonArray deviceConfigurations);

// Constructor
CubeSatInitializer::CubeSatInitializer(){}

// Instantiates a new CubeSat Module using data from the SD card
CubeSatModule* CubeSatInitializer::initializeCubeSat()
{
    bool sdIsInit = initializeSdCard();
    JsonDocument config = loadConfig();

    const int cubeSatModuleId = static_cast<int>(config["id"]);

    const bool isHub = config["isHub"];

    JsonArray deviceConfigurations = config["devices"];

    std::vector<CubeSatDevice*> devices = generateDeviceVector(deviceConfigurations);
    if (!isHub)
    {
        return new CubeSatModule(false, cubeSatModuleId, devices);
    }

    return new CubeSatHub(cubeSatModuleId, devices);
};

// Ensures SD card is connected and ready for read/write
bool initializeSdCard()
{
    if (!SD.begin()) 
    {
        // Blink continuously.
        // The module can't proceed without being initialized 
        // and there's no SD card to write errors to.
        errorBlink();
    }
    return true;
}

// Loads configuration file from the SD card
JsonDocument loadConfig()
{
    // Load the file into a file handler
    File file = SD.open(CONFIG_FILE.c_str());
    
    // Blink continuously.
    // The module can't proceed without being initialized 
    // and there's no SD card to write errors to.
    if (!file) 
    {
        errorBlink();
    }

    // Read the file content into a String
    String fileContent = file.readString();

    // Close the file
    file.close();

    // Create a JSON document
    JsonDocument doc;
  
    // Deserialize the JSON content
    DeserializationError error = deserializeJson(doc, fileContent);
    
    // Check for errors in deserialization
    if (error) 
    {
        errorBlink();
    }

    return doc;
}

// Light blinks, indicating an unrecoverable error
void errorBlink()
{
    pinMode(LED_BUILTIN, OUTPUT);
    while (true)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
    }
};

CubeSatDevice* buildDevice(const char* deviceType, int deviceId)
{
    if (std::strcmp(deviceType, "MS8607") == 0)
    {
        return new CubeSatMS8607(deviceId);
    }
    return nullptr;
}

std::vector<CubeSatDevice*> generateDeviceVector(JsonArray deviceConfigurations)
{   
    std::vector<CubeSatDevice*> devices;  // Vector should hold pointers to CubeSatDevice
    for (JsonObject deviceConfiguration : deviceConfigurations) 
    {
        devices.push_back(buildDevice(deviceConfiguration["deviceType"], deviceConfiguration["id"]));
    }

    return devices;
}