#include <stdio.h>


int intstr_to_int(char *s) {
    int i = 0;
    int v = 0;
    int cvalue;

    while (s[i] != '\0') {
        v = v * 10;
        cvalue = s[i] - '0';
        v = v + cvalue;
        i += 1;
    }

    return v;
}

int main(int argc, char *argv[]) {
    int v;

    v = intstr_to_int(argv[1]);
    printf("%d\n", v);

    return 0;
}
