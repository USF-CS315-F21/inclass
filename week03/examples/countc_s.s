.global find_char_index_s

@ r0 - c
@ r1 - *str
@ r2 - start
@ r3 - end
@
@ r4 - i
@ r5 - rv
@ r12 - tmp

find_char_index_s:
    sub sp, sp, #8              @ Allocate 2 words (8 bytes) on stack            
    str r4, [sp]                @ Store r4 at sp + 0
    str r5, [sp, #4]            @ Store r5 at sp + 4
    mov r4, r2                  @ Initialize r4 (i) to r2 (start)
    mov r5, #-1                 @ Set r5 (rv) to -1 (default)

find_char_index_loop:
    cmp r4, r3                  @ Compare r4 (i) to r3 (end)
    bge find_char_index_exit    @ Finish loop if r4 >= r3
    ldrb r12, [r1, r4]          @ r12 = str[r4]
    cmp r12, r0                 @ Compare r12 (tmpc) to r0 (c)
    bne find_char_index_next    @ Continue loop if not equal
    mov r5, r4                  @ Set r5 (rv) to r4 (i)
    b find_char_index_exit      @ Exit loop
find_char_index_next:
    add r4, r4, #1              @ Set r4 (i) = r4 (i) + 1
    b find_char_index_loop      @ Branch to top of loop

find_char_index_exit:
    mov r0, r5                  @ Set r0 (return value) to r4 (i)
    ldr r5, [sp, #4]            @ Restore original r5
    ldr r4, [sp]                @ Restore original r4
    add sp, sp, #8              @ Deallocate stack space
    bx lr                       @ Return to caller


.global count_char_s

@ r0 - c
@ r1 - *str
@ r2 - len
@
@ r4 = start
@ r5 = count
@ r12 = r

count_char_s:
    sub sp, sp, #32       @ Allocate 32/4 = 8 words on the stack
    str lr, [sp]          @ Store lr on stack
    str r4, [sp, #4]      @ Store r4 on stack
    str r5, [sp, #8]      @ Store r5 on stack

    mov r4, #0            @ r4 (start) = 0
    mov r5, #0            @ r5 (count) = 0

count_char_loop:
    str r0, [sp, #12]     @ Store r0 on stack - caller saved
    str r1, [sp, #16]     @ Store r1 on stack - caller saved
    str r2, [sp, #20]     @ store r2 on stack - caller saved

    mov r3, r2            @ r3 (len) = r2 (len)
    mov r2, r4            @ r2 (start) = r4 (start)

    bl find_char_index_s  @ Call find_char_index_s

    mov r12, r0           @ r12 = r0 (return value)

    ldr r2, [sp, #20]     @ Restore r2 (start)
    ldr r1, [sp, #16]     @ Restore r1 (str)
    ldr r0, [sp, #12]     @ Restore r0 (c)

    cmp r12, #-1          @ Compare r12 to -1
    beq count_char_exit   @ Exit loop if equal
    add r5, r5, #1        @ r5 (count) = r5 (count) + 1
    add r4, r12, #1       @ r4 (start) = r12 (r) + 1
    b count_char_loop     @ Branch to top of loop

count_char_exit:
    mov r0, r5            @ Set r0 (return value) to r5 (count)
    ldr r5, [sp, #8]      @ Restore r5
    ldr r4, [sp, #4]      @ Restore r4
    ldr lr, [sp]          @ Restore lr
    add sp, sp, #32       @ Deallocate 8 words from stack
    bx lr                 @ Return
