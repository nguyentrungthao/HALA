#include "stdio.h"
#include "motor.h"

int main() {

    motor_t quat;
    quat.pinA = 1;
    quat.PinB = 2;

    init(&quat);

    // quat.start(&quat);

    return 0;
}