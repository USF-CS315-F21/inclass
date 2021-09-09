#include <stdio.h>

int mult_10_c(int x);
int mult_10_s(int x);

int main(int argc, char *argv[]) {
    int r;

    r = mult_10_c(3);
    printf("r = mult_10_c(3) = %d\n", r);
    r = mult_10_s(3);
    printf("r = mult_10_s(3) = %d\n", r);


    return 0;
}
