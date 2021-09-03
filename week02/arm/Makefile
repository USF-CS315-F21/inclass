# Makefile

PROGS = addone max

ADDONE_OBJS = addone.o addone_c.o addone_s.o
MAX_OBJS = max.o max_c.o max_s.o


%.o : %.c
	gcc -c -g -o $@ $<

%.o : %.s
	as -g -o $@ $<

all : $(PROGS)

addone : $(ADDONE_OBJS)
	gcc -g -o $@ $^

max : $(MAX_OBJS)
	gcc -g -o $@ $^


clean :
	rm -rf $(PROGS) $(ADDONE_OBJS) $(MAX_OBJS)
