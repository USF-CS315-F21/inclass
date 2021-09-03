#include <stdint.h>

int32_t max_c(int32_t x, int32_t y) {
    int32_t r;

    if (x > y) {
        r = x;
    } else {
        r = y;
    }

    return r;
}
