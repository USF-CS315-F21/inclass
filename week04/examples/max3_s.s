.global max2_s

@ r0 - x
@ r1 - y

max2_s:
    cmp r0, r1        @ compare x to y
    bge max2_return_x @ branch if x >= y
    mov r0, r1
max2_return_x:
    bx lr

@ r0 - x
@ r1 - y
@ r2 - z

.global max3_s

max3_s:
    sub sp, sp, #8
    str lr, [sp]
    
    str r2, [sp, #4]
    bl max2_s
    @ r0 = max2_s(r0, r1)
    ldr r2, [sp, #4]

    mov r1, r2      @ put z into r1

    bl max2_s
    @ r0 = max2_s(r0, r1)
    
    ldr lr, [sp]
    add sp, sp, #8
    bx lr
