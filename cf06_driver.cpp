/**
 * cf06_driver.cpp — CWClockfaceDriver adapter for cw-cf-0x06 (Pokedex)
 * v3 bridge: wraps the v2 CF06::Clockface class in the function-pointer API.
 */

#include "Clockface06.h"        // v2 class, namespace CF06
#include <CWClockfaceDriver.h>     // v3 driver API

static CF06::Clockface* s_face = nullptr;

static void cf06_setup(Adafruit_GFX* display, CWDateTime* dateTime) {
    if (!s_face) s_face = new CF06::Clockface(display);
    s_face->setup(dateTime);
}

static void cf06_update() {
    if (s_face) s_face->update();
}

static void cf06_teardown() {
    // Instance kept alive for fast re-activation.
}

CWClockfaceDriver cf_pokedex = {
    .name     = "Pokedex",
    .index    = 5,
    .setup    = cf06_setup,
    .update   = cf06_update,
    .teardown = cf06_teardown,
};
