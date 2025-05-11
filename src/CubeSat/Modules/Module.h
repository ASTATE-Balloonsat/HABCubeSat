#ifndef MODULE_H
#define MODULE_H

#include "../Interfaces/ModuleInterface.h"
#include "../Interfaces/ReceiverInterface.h"
#include "../Interfaces/TransmitterInterface.h"
#include <ArduinoJson.h>
#include <memory>
#include <vector>

class Module : public IModule
{
    public:
        Module(bool isHub, 
            std::vector<std::unique_ptr<IReceiver>> receivers, 
            std::vector<std::unique_ptr<ITransmitter>> transmitters);
        void initialize() override;
        bool isHub() override;
        bool status() override;
        void refreshDataStream() override;
        void transmitDataStream() override;
    
    private:
        int moduleId;
        bool isHubVal = false;
        bool statusVal = false;
        std::string dataStream = "";
        std::vector<std::unique_ptr<IReceiver>> receivers;
        std::vector<std::unique_ptr<ITransmitter>> transmitters;
};

#endif