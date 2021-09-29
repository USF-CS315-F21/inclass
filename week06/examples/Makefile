PROGS = analyze

ANALYZE_OBJS = analyze.o addsub_s.o

OBJS = $(ANALYZE_OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

analyze: $(ANALYZE_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
