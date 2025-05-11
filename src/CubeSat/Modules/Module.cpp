#include "./Module.h"
#include "../Global_Constants.h"

Module::Module(bool isHub, 
    std::vector<std::unique_ptr<IReceiver>> receivers, 
    std::vector<std::unique_ptr<ITransmitter>> transmitters)
{
    isHubVal = isHub;
    this->receivers = std::move(receivers);
    this->transmitters = std::move(transmitters);
    statusVal = true;
}

void Module::initialize()
{
    for (int i = 0; i < receivers.size(); i++)
    {
        receivers[i]->begin();
    }

    for (int i = 0; i < transmitters.size(); i++)
    {
        transmitters[i]->begin();
    }
}

bool Module::isHub()
{
    return isHubVal;
}

bool Module::status()
{
    return statusVal;
}

void Module::refreshDataStream()
{
    dataStream = moduleId;
    
    for (int i = 0; i < receivers.size(); i++)
    {
        dataStream.append((*receivers[i]).read());
        dataStream += DEVICE_DISCRIMINATOR;
    }
    dataStream += MODULE_DISCRIMINATOR;
}

void Module::transmitDataStream()
{
    for (int i = 0; i < transmitters.size(); i++)
    {
        (*transmitters[i]).write(dataStream);
    }
}
