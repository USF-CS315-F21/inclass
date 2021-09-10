.global sumarr_ptr_s

@ r0 - *arr
@ r1 - len
@ r2 - i
@ r3 - sum
@
@ r12 - tmp

sumarr_ptr_s:
    mov r2, #0
    mov r3, #0

sumarr_ptr_loop:
    cmp r2, r1
    bge sumarr_ptr_exit
    ldr r12, [r0]
    add r3, r3, r12
    add r2, r2, #1
    add r0, r0, #4
    b sumarr_ptr_loop

sumarr_ptr_exit:
    mov r0, r3
    bx lr

.global sumarr_index_s

@ r0 - *arr
@ r1 - len
@ r2 - i
@ r3 - sum
@
@ r12 - tmp

sumarr_index_s:
    mov r2, #0
    mov r3, #0

sumarr_index_loop:
    cmp r2, r1
    bge sumarr_index_exit
    ldr r12, [r0, r2, LSL #2]
    add r3, r3, r12
    add r2, r2, #1
    b sumarr_index_loop

sumarr_index_exit:
    mov r0, r3
    bx lr
    
