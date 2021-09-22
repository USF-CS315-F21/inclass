.global fib_rec_s

@ r0 - n

fib_rec_s:
    sub sp, sp, #16
    str lr, [sp]

    cmp r0, #1
    ble fib_rec_exit   @ Base case n == 0 or n == 1

    str r0, [sp, #4]   @ Store n (r0)

    sub r0, r0, #1     @ n = n - 1
    bl fib_rec_s
    str r0, [sp, #8]   @ Store f1 (r0)
    
    ldr r0, [sp, #4]   @ Restore n (r0)
    sub r0, r0, #2     @ n = n - 2
    bl fib_rec_s

    ldr r1, [sp, #8]   @ Restore f1
    add r0, r0, r1     @ r = r2 + f1
    
fib_rec_exit:
    ldr lr, [sp]
    add sp, sp, #16
    bx lr
