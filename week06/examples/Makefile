PROGS = analyze armemu

ANALYZE_OBJS = analyze.o addsub_s.o
ARMEMU_OBJS = armemu.o add_s.o

OBJS = $(ANALYZE_OBJS) $(ARMEMU_OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

analyze: $(ANALYZE_OBJS)
	gcc -g -o $@ $^

armemu: $(ARMEMU_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
