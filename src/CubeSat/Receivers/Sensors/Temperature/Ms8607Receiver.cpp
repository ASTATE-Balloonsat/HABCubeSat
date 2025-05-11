#include "Ms8607Receiver.h"
#include <Adafruit_MS8607.h>
#include "../../../Global_Constants.h"

Ms8607Receiver::Ms8607Receiver(const JsonDocument& config)
{
    if (config["humidityResolution"].is<int>())
    {
        humidityResolution = static_cast<ms8607_humidity_resolution_t>(config["humidityResolution"]);
    }
    if (config["pressureResolution"].is<int>())
    {
        pressureResolution = static_cast<ms8607_pressure_resolution_t>(config["pressureResolution"]);
    }
    Serial.println("In Receiver");
    status = true;
};

bool Ms8607Receiver::begin()
{
    device.setHumidityResolution(humidityResolution);
    device.setPressureResolution(pressureResolution);
    status = device.begin();
    return status;
};

bool Ms8607Receiver::connected()
{
    return status;
}

std::string Ms8607Receiver::read()
{
    sensors_event_t temp, pressure, humidity;
    if (device.getEvent(&pressure, &temp, &humidity))
    {
        double temperatureVal = temp.temperature;
        double pressureVal = pressure.pressure;
        double humidityVal = humidity.relative_humidity;

        return (
            std::to_string(temperatureVal) +
            DATUM_DISCRIMINATOR +
            std::to_string(pressureVal) +
            DATUM_DISCRIMINATOR +
            std::to_string(humidityVal)
        );
    }
    else
    {
        status = false;
        return std::string(1, DATUM_DISCRIMINATOR);
    }
};