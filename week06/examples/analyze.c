#include <stdio.h>
#include <stdint.h>


int addsub_s(int a0, int a1);


void analyze_iw(uint32_t iw) {
    uint32_t cond, dp_bits, i_bit, opcode, rn, rd, rm, imm;

    printf("iw = %8x\n", iw);

    /* Extract bit fields */
    cond = (iw >> 28) & 0b1111;
    dp_bits = (iw >> 26) & 0b11;
    i_bit = (iw >> 25) & 0b1;
    opcode = (iw >> 21) & 0b1111;
    rn = (iw >> 16) & 0b1111;
    rd = (iw >> 12) & 0b1111;
    rm = iw & 0b1111;
    imm = iw & 0b11111111;

    printf("cond    = %x\n", cond);
    printf("dp_bits = %d\n", dp_bits);
    printf("i_bit   = %d\n", i_bit);
    printf("opcode  = %d\n", opcode);
    printf("rn      = %d\n", rn);
    printf("rd      = %d\n", rd);
    if (i_bit == 0) {
        printf("rm      = %d\n", rm);
    } else {
        printf("imm     = %d\n", imm);
    }
}

int main(int argc, char *argv[]) {
    uint32_t iw;   /* instruction word */
    uint32_t *pc;  /* program counter */

    pc = (uint32_t *) addsub_s;
    printf("pc = %x\n", (uint32_t) pc);
    iw = *pc;
    analyze_iw(iw);
    
    pc = pc + 1;
    printf("pc = %x\n", (uint32_t) pc);
    iw = *pc;
    analyze_iw(iw);
    
    return 0;
}
