.global foo
@.global bar

foo:
    b foo_2
    add r0, r0, #0
    add r0, r0, #0
    add r0, r0, #0
foo_2:    
    bl bar
    bx lr

bar:
    bx lr
    
