#include <stdint.h>
#include <stdio.h>

int32_t addone_c(int32_t x);
int32_t addone_s(int32_t x);

int main(int argc, char *argv[]) {
    int32_t v1, v2;

    v1 = addone_c(3);
    printf("addone_c(3) = %d\n", v1);

    v2 = addone_s(3);
    printf("addone_s(3) = %d\n", v2);
    
    return 0;
}
