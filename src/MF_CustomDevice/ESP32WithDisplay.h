#pragma once

#include "Arduino.h"

class ESP32WithDisplay
{
public:
    ESP32WithDisplay(int width, int height);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool         _initialised;
    Arduino_GFX *gfx;
    uint8_t      _pin1, _pin2, _pin3;
};