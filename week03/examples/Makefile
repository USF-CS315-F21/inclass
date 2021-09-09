# Makefile

PROGS = loop strlen

LOOP_OBJS = loop.o loop_c.o loop_s.o
STRLEN_OBJS = strlen.o strlen_c.o strlen_s.o

%.o : %.c
	gcc -c -g -o $@ $<

%.o : %.s
	as -g -o $@ $<

all : $(PROGS)

loop : $(LOOP_OBJS)
	gcc -g -o $@ $^

strlen : $(STRLEN_OBJS)
	gcc -g -o $@ $^

clean :
	rm -rf $(PROGS) $(LOOP_OBJS) $(STRLEN_OBJS)
