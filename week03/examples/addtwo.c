#include <stdio.h>

int addtwo_c(int x);
int addtwo_s(int x);

int main(int argc, char *argv[]) {
    int r;

    r = addtwo_c(7);
    printf("addtwo_c(7) = %d\n", r);

    r = addtwo_s(7);
    printf("addtwo_s(7) = %d\n", r);


    return 0;
}
