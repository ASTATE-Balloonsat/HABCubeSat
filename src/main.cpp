#include <Arduino.h>
#include "CubeSat/Factories/SdCardStorageFactory.h"
#include "CubeSat/Storage/SdCardStorage.h"
#include "CubeSat/Global_Constants.h"
#include "CubeSat/FactoryManagers/TransmitterFactoryManager.h"
#include "CubeSat/FactoryManagers/ReceiverFactoryManager.h"
#include "CubeSat/Factories/ModuleFactory.h"

// put function declarations here:
int myFunction(int, int);

std::unique_ptr<Module> module;

void setup() 
{
  auto SdCard = SdCardStorageFactory().createStorage();
  JsonDocument* config = SdCard->readConfig();

  if (config == nullptr) 
  {
    return;
  }

  JsonArray transmitterConfigurations = (*config)["transmitters"].as<JsonArray>();

  auto transmitters = std::move(TransmitterFactoryManager::buildTransmitters(transmitterConfigurations));

  JsonArray receiverConfigurations = (*config)["receivers"].as<JsonArray>();

  auto receivers = std::move(ReceiverFactoryManager::buildReceivers(receiverConfigurations));


  bool isHub = (*config)["isHub"];

  module = ModuleFactory::createModule(isHub, std::move(receivers), std::move(transmitters));

  module->initialize();
  
  
}

void loop() {
  module->refreshDataStream();
  module->transmitDataStream();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}