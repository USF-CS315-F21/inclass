PROGS = get_bitseq get_bitseq_signed merge merge_sort

GET_BITSEQ_OBJS = get_bitseq.o get_bitseq_s.o
GET_BITSEQ_SIGNED_OBJS = get_bitseq_signed.o  \
                         get_bitseq_signed_s.o get_bitseq_s.o
MERGE_OBJS = merge.o merge_c.o merge_util.o
MERGE_SORT_OBJS = merge_sort.o merge_sort_c.o merge_c.o merge_util.o

OBJS = $(GET_BITSEQ_OBJS) $(GET_BITSEQ_SIGNED_OBJS) \
       $(MERGE_OBJS) $(MERGE_SORT_OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

get_bitseq: $(GET_BITSEQ_OBJS)
	gcc -g -o $@ $^

get_bitseq_signed: $(GET_BITSEQ_SIGNED_OBJS)
	gcc -g -o $@ $^

merge: $(MERGE_OBJS) merge_util.h
	gcc -g -o $@ $^

merge_sort: $(MERGE_SORT_OBJS) merge_util.h
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
