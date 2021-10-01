.global branches_s

branches_s:
    add r0, r0, #1
    b branches_exit
    add r0, r0, #2
    add r0, r0, #3
    add r0, r0, #4
    add r0, r0, #5
branches_exit:
    add r0, r0, #6
    add r0, r0, #7
    add r0, r0, #8
    add r0, r0, #9
    add r0, r0, #10
    add r0, r0, #11
    b branches_exit
    add r0, r0, #12
    add r0, r0, #13
    add r0, r0, #14
    cmp r0, r1
    bgt branches_exit
    bx lr
