// CubeSatDataDiscriminators.h

/******************************************************************************
    Class Wrapper for Data Discriminator Constants

    Purpose: 
        Stores the discriminators between various pieces of data for
        convenient modification.
******************************************************************************/

#ifndef CUBE_SAT_DATA_DISCRIMINATORS_H
#define CUBE_SAT_DATA_DISCRIMINATORS_H

class CubeSatDataDiscriminators
{
    public:
        static constexpr char MODULE_DISCRIMINATOR = ';';
        static constexpr char DEVICE_DISCRIMINATOR = ':';
        static constexpr char DATUM_DISCRIMINATOR = ',';
};

#endif