.global mult_10_s

@ r0 - x
@
@ r1 - i
@ r2 - r 

mult_10_s:
    mov r1, #0
    mov r2, #0

mult_10_loop:
    cmp r1, #10
    bge mult_10_exit
    add r2, r2, r0    @ r = r + x         
    add r1, r1, #1    @ i = i + 1
    b mult_10_loop

mult_10_exit:
    mov r0, r2
    bx lr
