PROG = lab04
OBJS = quadratic_c.o quadratic_s.o armemu.o max3_c.o max3_s.o\
       get_bitseq_c.o get_bitseq_s.o midpoint_c.o midpoint_s.o
HEADERS = armemu.h

CFLAGS = -g -Wall

%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.s $(HEADERS)
	as -g -o $@ $<

all : $(PROG)

$(PROG) : $(PROG).c $(OBJS)
	gcc $(CFLAGS) -o $@ $< $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
