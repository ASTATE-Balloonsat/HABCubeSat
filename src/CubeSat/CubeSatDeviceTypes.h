// CubeSatDeviceTypes.h

/******************************************************************************
    Class Wrapper for Device Type Constants

    Purpose: 
        Stores device types as constants which can be referenced in a
        device initialization. Primarily used to determine the data
        structure expected to be received by a give sensor.
******************************************************************************/

#ifndef CUBE_SAT_DEVICE_TYPES_H
#define CUBE_SAT_DEVICE_TYPES_H

class CubeSatDeviceTypes
{
    public:
        static constexpr const char* MS8607 = "MS8607";
};

#endif