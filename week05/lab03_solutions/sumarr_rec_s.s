.global sumarr_rec_s

@ r0 - arr
@ r1 - start
@ r2 - end


sumarr_rec_s:
    sub sp, sp, #16
    str lr, [sp]

    cmp r1, r2
    bne sumarr_rec_step        @ Base case start == end
    ldr r0, [r0, r1, LSL #2]   @ r0 = arr[start]
    b sumarr_rec_exit
    
sumarr_rec_step:

    str r0, [sp, #4]           @ Store arr
    str r1, [sp, #8]           @ Store start
    
    add r1, r1, #1             @ start = start + 1

    bl sumarr_rec_s
                               @ r0 = sumarr_rec_s(arr, start + 1, end)
    ldr r1, [sp, #8]           @ Restore start
    ldr r2, [sp, #4]           @ Restore arr into r2
    ldr r2, [r2, r1, LSL #2]   @ r (r2) = arr[start]

    add r0, r2, r0             @ r0 = arr[start] + r (r2)

sumarr_rec_exit:
    ldr lr, [sp]
    add sp, sp, #16
    bx lr
