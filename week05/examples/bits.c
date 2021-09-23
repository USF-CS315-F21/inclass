#include <stdio.h>
#include <stdint.h>

void print_bin(uint32_t v, int size);
uint32_t set_4_7_s(uint32_t v0, uint32_t v1);


int main(int argc, char *argv[]) {
    uint32_t v1 = 0b11001001;

    printf("The first 8 bits of v1\n");
    print_bin(v1, 8);
    printf("\n");

    uint32_t v2 = 0b11111111111111111111111111111111;
    printf("Parts of v2\n");
    print_bin(v2, 32);
    print_bin(v2, 24);
    print_bin(v2, 16);
    print_bin(v2, 8);
    printf("\n");

    uint32_t v3 = 0b1011;
    printf("Testing bits: v3 = ");
    print_bin(v3, 4);
    printf("is bit 2 set? %d\n", (v3 & 0b0100) ? 1 : 0);
    printf("is bit 3 set? %d\n", (v3 & 0b1000) ? 1 : 0);
    printf("\n");

    uint32_t v4 = 0b10011011;
    printf("Masking bits: v4 = ");
    print_bin(v4, 8);
    printf("Value of bits 1 0 = %d\n", v4 & 0b11);
    printf("Value of bits 3 2 1 0 = %d\n", v4 & 0b1111);

    printf("Shifting\n");
    uint32_t v5 = 0b00000000010011011;
    printf("v5 = ");
    print_bin(v5, 16);
    printf("v5 >> 4 = ");
    print_bin(v5 >> 4, 16);
    printf("v5 << 4 = ");
    print_bin(v5 << 4, 16);
    printf("\n");

    printf("Setting specific bits\n");
    uint32_t v6 = 0b110000111001;
    printf("v6 = ");
    print_bin(v6, 32);
    uint32_t v7 = 0b1101;
    printf("v7 = ");
    print_bin(v7, 32);
    uint32_t v8 = (v6 & 0b111100001111) | (v7 << 4);
    printf("v8 = ");
    print_bin(v8, 32);
    uint32_t v9;
    v9 = set_4_7_s(v6, v7);
    printf("v9 = ");
    print_bin(v9, 32);
    printf("\n");

    printf("Signed values\n");
    int32_t v10 = -1;
    printf("v10 = %d\n", v10);
    printf("v10 = ");
    print_bin(v10, 32);
    int32_t v11 = -94117;
    printf("v11 = %d\n", v11);
    printf("v11 = ");
    print_bin(v11, 32);

    printf("Singed overflow\n");    
    int32_t v12 = 2000000000;
    int32_t v13 = 2000000100;
    printf("v12 = %d\n", v12);
    printf("v12 = ");
    print_bin(v12, 32);
    printf("v13 = %d\n", v13);
    printf("v13 = ");
    print_bin(v13, 32);
    int32_t v14 = v12 + v12;
    printf("v14 = %d\n", v14);
    printf("v14 = ");
    print_bin(v14, 32);
    printf("\n");

    printf("Singed shifting\n");
    int32_t v15 = -64;
    printf("v15 = %d\n", v15);
    printf("v15 = ");
    print_bin(v15, 32);    
    int32_t v16 = v15 >> 2;
    printf("v16 = %d\n", v16);
    printf("v16 = ");
    print_bin(v16, 32);    
    int32_t v17 = ((uint32_t) v15) >> 1;
    printf("v17 = %d\n", v17);
    printf("v17 = ");
    print_bin(v17, 32);    

    


    return 0;
}
