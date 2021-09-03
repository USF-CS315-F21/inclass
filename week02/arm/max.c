#include <stdint.h>
#include <stdio.h>

int32_t max_c(int32_t x, int32_t y);
int32_t max_s(int32_t x, int32_t y);

int main(int argc, char *argv[]) {
    int32_t v1, v2;

    v1 = max_c(3, 7);
    printf("max_c(3, 7) = %d\n", v1);

    v2 = max_s(3, 7);
    printf("max_s(3, 7) = %d\n", v2);
    
    return 0;
}
