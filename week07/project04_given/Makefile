PROG = project04
OBJS = project04.o armemu.o cache.o verbose.o\
	   fib_rec_c.o fib_rec_s.o\
	   find_max_index_c.o find_max_index_s.o\
       get_bitseq_c.o get_bitseq_s.o\
       is_pal_rec_c.o is_pal_rec_s.o\
	   max3_c.o max3_s.o\
	   merge_c.o merge_s.o\
	   merge_sort_c.o merge_sort_s.o\
       midpoint_c.o midpoint_s.o\
	   quadratic_c.o quadratic_s.o\
	   sort_c.o sort_s.o\
	   to_upper_c.o to_upper_s.o
HEADERS = armemu.h

CFLAGS = -g -Wall

%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.s $(HEADERS)
	as -g -o $@ $<

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $@ $^

clean :
	rm -rf $(PROG) $(OBJS)
