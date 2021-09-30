.global add_s

add_s:
    add r0, r0, r1
    add r0, r0, #100
    sub r0, r0, #99
    bx lr
