#include "ESP32WithDisplay.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include <Wire.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <Arduino_GFX_Library.h>

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

/* **********************************************************************************
    This is just the basic code to set up your custom device.
    Change/add your code as needed.
********************************************************************************** */

ESP32WithDisplay::ESP32WithDisplay(int width, int height)
{
}

void ESP32WithDisplay::begin()
{

    Arduino_DataBus *bus = new Arduino_ESP32SPI(2 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, GFX_NOT_DEFINED /* MISO */);
    gfx                  = new Arduino_ST7789(bus, -1 /* RST */, 1 /* rotation */, true /* IPS */);
    _initialised         = true;
}

void ESP32WithDisplay::attach(uint16_t Pin3, char *init)
{
}

void ESP32WithDisplay::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void ESP32WithDisplay::set(int16_t messageID, char *setPoint)
{
    /* **********************************************************************************
        Each messageID has it's own value
        check for the messageID and define what to do.
        Important Remark!
        MessageID == -2 will be send from the board when PowerSavingMode is set
            Message will be "0" for leaving and "1" for entering PowerSavingMode
        MessageID == -1 will be send from the connector when Connector stops running
        Put in your code to enter this mode (e.g. clear a display)

    ********************************************************************************** */
    int32_t  data = atoi(setPoint);
    uint16_t output;

    // do something according your messageID
    switch (messageID) {
    case -1:
        // tbd., get's called when Mobiflight shuts down
    case -2:
        // tbd., get's called when PowerSavingMode is entered
    case 0:
        output = (uint16_t)data;
        data   = output;
        gfx->setCursor(10, 10);
        gfx->setTextColor(RED);
        gfx->println("MF Test");
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
}

void ESP32WithDisplay::update()
{
    // Do something which is required regulary
}
