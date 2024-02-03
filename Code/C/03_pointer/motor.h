#ifndef MOTOR_H
#define MOTOR_H
#include "stdio.h"
#include "stdint.h"
#include "assert.h" 
#include "setjmp.h"

typedef uint8_t PIN_t;
typedef void (*pFunc_t)(void*);

typedef struct {
    PIN_t pinA;
    PIN_t PinB;

    pFunc_t start;
    pFunc_t stop;

} motor_t;

void init(motor_t *obj);

#endif
