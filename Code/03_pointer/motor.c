#include "motor.h"

static void startMotor(void* ptr) {
    motor_t* pObj = (motor_t*)ptr;
    printf("dong co chay pin %d và %d\r\n", pObj->pinA, pObj->PinB);
}
static void stopMotor(void* ptr) {
    printf("dong co dung");
}

void init(motor_t* obj) {
    obj->start = startMotor;
    obj->stop = stopMotor;
}