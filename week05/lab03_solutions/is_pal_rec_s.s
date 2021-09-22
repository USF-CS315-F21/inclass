.global pal_rec_s


@ r0 - *str
@ r1 - start
@ r2 - end


pal_rec_s:
    sub sp, sp, #8
    str lr, [sp]

    cmp r1, r2
    blt pal_rec_next
    mov r0, #1
    b pal_rec_exit

pal_rec_next:
    ldrb r3, [r0, r1]
    ldrb r12, [r0, r2]
    cmp r3, r12
    beq pal_rec_step
    mov r0, #0
    b pal_rec_exit

pal_rec_step:

    add r1, r1, #1
    sub r2, r2, #1
    bl pal_rec_s

pal_rec_exit:
    ldr lr, [sp]
    add sp, sp, #8
    bx lr
