.global fact_rec_s

@ r0 - n

fact_rec_s:

    
fact_rec_step:

    bl fact_rec_s    @ r0 = fact_rec_s(n - 1)

    
fact_rec_exit:


    bx lr
