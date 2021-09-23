.global set_4_7_s

@ r0 - v0
@ r1 - v1

set_4_7_s:
    ldr r2, =#0b111100001111
    and r0, r0, r2
    lsl r1, r1, #4
    orr r0, r0, r1
    bx lr        
