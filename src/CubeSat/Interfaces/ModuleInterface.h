#ifndef MODULE_INTERFACE_H
#define MODULE_INTERFACE_H

#include <string>

class IModule 
{
    public:
        virtual bool isHub() = 0; 
        virtual bool status() = 0;
        virtual void initialize() = 0;
        virtual void refreshDataStream() = 0;
        virtual void transmitDataStream() = 0;
        virtual ~IModule() = default;
};

#endif