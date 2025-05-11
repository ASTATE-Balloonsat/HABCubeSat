#ifndef MS8607_DEVICE_H
#define MS8607_DEVICE_H

#include <string>
#include <ArduinoJson.h>
#include <Adafruit_MS8607.h>
#include "../../../Interfaces/ReceiverInterface.h"

class Ms8607Receiver : public IReceiver
{
    public:
        Ms8607Receiver(const JsonDocument& config);

        bool begin() override;
        bool connected() override;
        std::string read() override;

    private:
        int deviceId;
        bool status;
        ms8607_humidity_resolution_t humidityResolution = MS8607_HUMIDITY_RESOLUTION_OSR_8b;
        ms8607_pressure_resolution_t pressureResolution = MS8607_PRESSURE_RESOLUTION_OSR_4096;
        Adafruit_MS8607 device;
};

#endif