.global fact_rec_s

@ r0 - n

fact_rec_s:
    sub sp, sp, #8
    str lr, [sp]

    cmp r0, #0
    bne fact_rec_step
    mov r0, #1
    b fact_rec_exit
    
fact_rec_step:

    str r0, [sp, #4]
    sub r0, r0, #1
    
    bl fact_rec_s    @ r0 = fact_rec_s(n - 1)

    ldr r1, [sp, #4]
    mul r0, r0, r1
    
fact_rec_exit:

    ldr lr, [sp]
    add sp, sp, #8
    bx lr
