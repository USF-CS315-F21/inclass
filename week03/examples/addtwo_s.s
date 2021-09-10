.global addone_s


@ r0 - x

addone_s:
    add r0, r0, #1
    bx lr

.global addtwo_s

@ r0 - x

addtwo_s:
    sub sp, sp, #8
    str lr, [sp]

    bl addone_s

    bl addone_s

    ldr lr, [sp]
    add sp, sp, #8
    
    bx lr
