PROGS = max3 fact_rec fmi_rec
MAX3_OBJS = max3.o max3_c.o max3_s.o
FACTREC_OBJS = fact_rec.o fact_rec_c.o fact_rec_s.o
FMIREC_OBJS = fmi_rec.o fmi_iter_c.o fmi_rec_c.o fmi_rec_s.o

%.o: %.c
	gcc -g -c -o $@ $<

all: $(PROGS)

max3: $(MAX3_OBJS)
	gcc -g -o $@ $^

fact_rec : $(FACTREC_OBJS)
	gcc -g -o $@ $^

fmi_rec : $(FMIREC_OBJS)

clean:
	rm -rf $(PROGS) $(MAX3_OBJS) $(FACTREC_OBJS) $(FMIREC_OBJS)
