# Makefile

PROGS = loop strlen sumarr addtwo countc

LOOP_OBJS = loop.o loop_c.o loop_s.o
STRLEN_OBJS = strlen.o strlen_c.o strlen_s.o
SUMARR_OBJS = sumarr.o sumarr_c.o sumarr_s.o
ADDTWO_OBJS = addtwo.o addtwo_c.o addtwo_s.o
COUNTC_OBJS = countc.o countc_c.o countc_s.o

%.o : %.c
	gcc -c -g -o $@ $<

%.o : %.s
	as -g -o $@ $<

all : $(PROGS)

loop : $(LOOP_OBJS)
	gcc -g -o $@ $^

strlen : $(STRLEN_OBJS)
	gcc -g -o $@ $^

sumarr : $(SUMARR_OBJS)
	gcc -g -o $@ $^

addtwo : $(ADDTWO_OBJS)
	gcc -g -o $@ $^

countc : $(COUNTC_OBJS)
	gcc -g -o $@ $^



clean :
	rm -rf $(PROGS) $(LOOP_OBJS) $(STRLEN_OBJS) \
	       $(SUMARR_OBJS) $(ADDTWO_OBJS) $(COUNTC_OBJS)

