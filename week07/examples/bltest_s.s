.global bltest_s

bltest_s:
    mov r4, lr
    bl foo
    mov lr, r4
    bx lr

foo:
    mov r0, #99
    bx lr
