#include <stdio.h>
#include <stdint.h>

uint32_t get_bit(uint32_t v, int n) {
    return (v >> n) & 0b1;
}

void print_bin(uint32_t v, int size) {
    int i;
    int b;

    printf("0b");
    for (i = (size - 1); i >= 0; i--) {
        b = get_bit(v, i);
        printf("%c", b ? '1' : '0');
        /* printf("%c", '0' + b); */
        /* printf("%d", b); */
    }   
    printf("\n");
}
