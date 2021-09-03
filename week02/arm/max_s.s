.global max_s

@ Version that matches the C code

@ r0 - x
@ r1 - y

max_s:
    cmp r0, r1
    blt return_y
    mov r0, r0 @ r = x
    b max_exit
return_y:
    mov r0, r1 @ r = y
max_exit:
    bx lr


@ Shorter version

@ r0 - x
@ r1 - y

max_short_s:
    cmp r0, r1
    bgt return_x
    mov r0, r1
return_x:
    bx lr

