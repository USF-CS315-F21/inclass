.global fmi_rec_s

@ r0 - *arr
@ r1 - len
@ r2 - i
@ r3 - max_i

@ r4 - max_new

fmi_rec_s:
    sub sp, sp, #16
    str lr, [sp]
    str r4, [sp, #4]
    str r5, [sp, #8]
    str r6, [sp, #12]

    mov r4, r3                 @ max_new = max_i

    cmp r2, r1
    blt fmi_rec_step
    mov r0, r4                 @ r0 - max_new    
    b fmi_rec_exit

fmi_rec_step:

    ldr r5, [r0, r2, LSL #2]
    ldr r6, [r0, r3, LSL #2]
    cmp r5, r6
    ble fmi_rec_next
    mov r4, r2                 @ max_new = i

fmi_rec_next:

    add r2, r2, #1             @ i = i + 1
    mov r3, r4                 @ max_i = max_new

    bl fmi_rec_s

fmi_rec_exit:

    ldr r6, [sp, #12]
    ldr r5, [sp, #8]
    ldr r4, [sp, #4]
    ldr lr, [sp]
    add sp, sp, #16
    bx lr
