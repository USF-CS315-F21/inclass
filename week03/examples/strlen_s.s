.global strlen_ptr_s


@ r0 - *str
@
@ r1 - len
strlen_ptr_s:
    mov r1, #0

strlen_ptr_loop:
    ldrb r2, [r0]
    cmp r2, #0
    beq strlen_ptr_exit
    add r1, r1, #1
    add r0, r0, #1
    b strlen_ptr_loop
strlen_ptr_exit:
    mov r0, r1
    bx lr


.global strlen_index_s

@ r0 - *str
@
@ r1 - len
strlen_index_s:
    mov r1, #0

strlen_index_loop:
    ldrb r2, [r0, r1]   @ addr = r0 + r1
    cmp r2, #0
    beq strlen_index_exit
    add r1, r1, #1
    b strlen_index_loop
strlen_index_exit:
    mov r0, r1
    bx lr

