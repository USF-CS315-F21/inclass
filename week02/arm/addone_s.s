@ comment
.global addone_s

@ r0 - x
addone_s:
    add r0, r0, #1  @ r0 = r0 + 1
    bx lr
