#pragma once

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Tile.h>
#include <Locator.h>
#include <Game.h>
#include <Object.h>
#include <ImageUtils.h>
#include <WiFi.h>

// Commons
#include "widgets/clockface/IClockface.h"
#include "assets.h"
#include "display/Icons.h"
#include "PKMN_RBYGSC4pt7b.h"

namespace CF06 {




class Clockface: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
    char minutes[3] = {0};

  public:
    Clockface(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
    void refreshDate(uint8_t weekday, uint16_t color);
    void refreshTime();
    void updatePokemon();
    void updateLoadingBar(uint8_t seconds);
};

} // namespace CF06
