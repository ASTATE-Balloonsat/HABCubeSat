// CubeSatHub.h

/******************************************************************************
    CubeSatHub Class Header

    Purpose: 
        CubeSat subclass. Represents a CubeSat device acting as the hub. 
        A CubeSat hub should receive data from other CubeSat devices and 
        send data, including its own, to the ground-station transmission medium.
******************************************************************************/

#ifndef CUBESAT_HUB_H
#define CUBESAT_HUB_H

#include "CubeSatModule.h"
#include <memory>
#include <vector>

class CubeSatHub : public CubeSatModule
{
    public:
        CubeSatHub(int id, std::vector<CubeSatDevice*> devices)
        : CubeSatModule(true, id, devices) {}
};

#endif