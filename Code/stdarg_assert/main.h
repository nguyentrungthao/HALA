#ifndef MAIN_H
#define MAIN_H

// #define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdarg.h>
#include <assert.h>

typedef enum {
    LIGHT = 0x10,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
} DeviceType_t;

typedef enum {
    ON = 0x10,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    COOL_MODE,
    FAN_MODE,
    UNLOCK,
    LOCK,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    CHANGE_TRACK
} CommandType_t;

void controlDevice(DeviceType_t Device, ...);

#endif