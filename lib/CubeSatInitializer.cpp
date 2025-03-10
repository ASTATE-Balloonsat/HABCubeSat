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
        initializeSDCard:
            Ensures SD card is connected and prepares it for read/write
        loadConfig:
            Loads an object from the configuration file stored on the SD card.
        errorBlink:
            Causes the primary LED to blink, indicating an unrecoverable
            error.
******************************************************************************/

#include <CubeSat.h>
#include <SD.h>

String CONFIG_FILE="./CubeSatConfig.json";

// Constructor
CubeSatInitializer::CubeSatInitializer(){};

// Instantiates a new CubeSat Module using data from the SD card
CubeSatModule* initializeCubeSat()
{
    initializeSdCard();
    const JsonDocument config = loadConfig();
    const int cubeSatModuleId = static_cast<int>(config["id"]);
    const bool isHub = config["isHub"];
    
    if (!isHub)
    {
        return new CubeSatModule(false, cubeSatModuleId);
    }

    return new CubeSatHub(cubeSatModuleId);
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
}

// Loads configuration file from the SD card
JsonDocument loadConfig()
{
    // Load the file into a file handler
    File file = SD.open(CONFIG_FILE);
    
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

