PROGS = args echorepeat intstr_to_int

all : ${PROGS}

args : args.c
	gcc -o args args.c

echorepeat : echorepeat.c
	gcc -o echorepeat echorepeat.c

intstr_to_int: intstr_to_int.c
	gcc -o intstr_to_int intstr_to_int.c

clean:
	rm ${PROGS}
