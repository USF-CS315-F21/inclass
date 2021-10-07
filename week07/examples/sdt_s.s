.global sdt_s.s

@ r0 - int *arr
@ r1 - int i

sdt_s.s:
    sub sp, sp, #16
    ldr r12, [r0]   @ r12 = arr[0]
    str r12, [r0]   @ arr[0] = r12
    ldr r12, [r1, r2, LSL #2]
    bx lr
