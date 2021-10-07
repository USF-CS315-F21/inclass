.global b_bl_s

b_bl_s:
    b b_bl_exit
    beq b_bl_exit
    bl b_bl_exit

b_bl_exit:
    bx lr
