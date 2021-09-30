#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int add_s(int a0, int a1);

#define NREGS 16
#define STACK_SIZE 1024
#define SP 13
#define LR 14
#define PC 15

struct arm_state {
    uint32_t regs[NREGS];
    uint32_t cpsr;
    uint8_t stack[STACK_SIZE];
};

void armemu_init(struct arm_state *asp, uint32_t *func,
                 uint32_t a0, uint32_t a1,
                 uint32_t a2, uint32_t a3) {
    int i;

    /* Zero out registers */
    for (i = 0; i < NREGS; i++) {
        asp->regs[i] = 0;
    }

    /* Zero out CPSR */
    asp->cpsr = 0;

    /* Zero out the stack */
    for (i = 0; i < STACK_SIZE; i++) {
        asp->stack[i] = 0;
    }

    /* Set PC to point to address of function to emulate */
    asp->regs[PC] = (uint32_t) func;

    /* Set LR to 0 to know when we are done emulating */
    asp->regs[LR] = 0;

    /* Set SP to ??? */
    asp->regs[SP] = (uint32_t) &asp->stack[STACK_SIZE];

    /* Initialize the first 4 arguments */
    asp->regs[0] = a0;
    asp->regs[1] = a1;
    asp->regs[2] = a2;
    asp->regs[3] = a3;         
}

void arm_state_print(struct arm_state *asp) {
    int i;

    for (i = 0; i < NREGS; i++) {
        printf("regs[%2d] = %8X (%d)\n", i, asp->regs[i],
               asp->regs[i]);
    }
    printf("cpsr = %8X\n", asp->cpsr);
}

bool armemu_is_bx(uint32_t iw) {
    uint32_t bxcode = 0b000100101111111111110001;
    return ((iw >> 4) & 0xFFFFFF) == bxcode;
}

void armemu_bx(struct arm_state *asp, uint32_t iw) {
    uint32_t rn = iw & 0b1111;

    asp->regs[PC] = asp->regs[rn];
}

bool armemu_is_add(uint32_t iw) {
    uint32_t dp_bits = (iw >> 26) & 0b11;
    uint32_t opcode = (iw >> 21) & 0b1111;

    return (dp_bits == 0) && (opcode == 0b0100);
}

void armemu_add(struct arm_state *asp, uint32_t iw) {
    uint32_t i_bit, rn, rd, rm, imm;

    i_bit = (iw >> 25) & 0b1;
    rn = (iw >> 16) & 0b1111;
    rd = (iw >> 12) & 0b1111;
    rm = iw & 0b1111;
    imm = iw & 0b11111111;
    
    uint32_t oper2;

    if (i_bit == 0) {
        oper2 = asp->regs[rm];
    } else {
        oper2 = imm;
    }

    asp->regs[rd] = asp->regs[rn] + oper2;

    asp->regs[PC] = asp->regs[PC] + 4;
}

void armemu_one(struct arm_state *asp) {
    uint32_t iw;
    uint32_t *pc;
    pc = (uint32_t *) asp->regs[PC];
    iw = *pc;

    if (armemu_is_bx(iw)) {
        armemu_bx(asp, iw);
    } else if (armemu_is_add(iw)) {
        armemu_add(asp, iw);
    } else {
        printf("armemu_one() invalid instruction\n");
        exit(-1);
    }
}

int armemu(struct arm_state *asp) {

    while (asp->regs[PC] != 0) {
        armemu_one(asp);
    }

    return (int) asp->regs[0];
}

int main(int argc, char *argv[]) {
    struct arm_state state;
    uint32_t r;

    r = add_s(1, 2);
    printf("Asm = %d\n", r);

    armemu_init(&state, (uint32_t *) add_s, 1, 2, 0, 0);
    arm_state_print(&state);
    r = armemu(&state);
    printf("Emu = %d\n", r);

    return 0;
}
