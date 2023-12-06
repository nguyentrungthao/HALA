#ifndef _LIB_1_
#define _LIB_1_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define add(...) do {\
                        int sum = 0;\
                        int a[] = { __VAR_ARGS__ };\
                        uint8_t n = sizeof(a) / sizeof(a[0]);\
                        for (uint8_t i = 0; i < n; i++) {\
                            sum += a[i];\
                        }\
                    } while (0)

#define ADD(a, b) ({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a + _b; \
})

int sum(int a, int b) {
    return a + b;
}

#endif
