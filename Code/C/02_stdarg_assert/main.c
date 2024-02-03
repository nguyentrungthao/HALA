/*
https://docs.google.com/document/d/12lmmSJiRA9i2y9HqExIGrHih4RxUOakloIKhXuoMEk4/edit#heading=h.8d3x2idqgw3
*/

#include "main.h"

int main() {

    controlDevice(LIGHT, ON);
    controlDevice(LIGHT, OFF);

    controlDevice(AIR_CONDITIONER, 1, SET_TEMPERATURE, 24.2);
    controlDevice(AIR_CONDITIONER, 1, SET_MODE, FAN_MODE);
    controlDevice(AIR_CONDITIONER, 2, SET_TEMPERATURE, 23.2, SET_MODE, FAN_MODE);
    controlDevice(AIR_CONDITIONER, 2, SET_MODE, FAN_MODE, SET_TEMPERATURE, 23.2);

    controlDevice(FINGERPRINT_LOCK, LOCK);
    controlDevice(FINGERPRINT_LOCK, UNLOCK);

    controlDevice(MUSIC_PLAYER, 2, INCREASE_VOLUME, CHANGE_TRACK);

    printf("End Main\r\n");
    return 0;
}

void controlDevice(DeviceType_t Device, ...) {
    va_list arg;
    va_start(arg, Device);
    CommandType_t cmd;
    uint8_t NumOfcmd;
    switch (Device) {
    case LIGHT:
        cmd = va_arg(arg, CommandType_t);
        assert(cmd == ON || cmd == OFF && "ERROR: Wrong parameter for light");
        printf("light turn %s\r\n", cmd == ON ? "ON" : "OFF");
        break;

    case AIR_CONDITIONER:
        NumOfcmd = (uint8_t)va_arg(arg, int);
        for (uint8_t i = 0; i < NumOfcmd; i++) {
            cmd = va_arg(arg, CommandType_t);
            switch (cmd) {
            case SET_TEMPERATURE:
                printf("Air Conditioner temperature set to %0.1lf degrees\r\n", va_arg(arg, double));
                break;
            case SET_MODE:
                cmd = va_arg(arg, CommandType_t);
                assert(cmd == COOL_MODE || cmd == FAN_MODE && "ERROR: Wrong parameter mode for Air Conditioner");
                printf("Air Conditioner mode set to %s\r\n", cmd == COOL_MODE ? "cool mode" : "fan mode");
                break;
            }
        }
        break;

    case FINGERPRINT_LOCK:
        cmd = va_arg(arg, CommandType_t);
        assert(cmd == UNLOCK || cmd == LOCK && "ERROR: Wrong parameter for fingerprint lock");
        printf("fingerprint lock %s\r\n", cmd == UNLOCK ? "unlock" : "lock");
        break;

    case MUSIC_PLAYER:
        NumOfcmd = (uint8_t)va_arg(arg, int);
        assert(NumOfcmd <= 2 && "ERROR: Wrong parameter for fingerprint lock");
        for (uint8_t i = 0; i < NumOfcmd; i++) {
            cmd = va_arg(arg, CommandType_t);
            switch (cmd) {
            case INCREASE_VOLUME:
                printf("music play increase volume \r\n");
                break;
            case DECREASE_VOLUME:
                printf("music play decrease volume \r\n");
                break;
            case CHANGE_TRACK:
                printf("music play CHANGE_TRACK \r\n");
                break;
            }
        }
        break;
        break;
    }
    va_end(arg);
}

