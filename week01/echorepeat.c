#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *s;
    int count = 0;
    int i = 0;

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'r' 
              && argv[i][2] == '\0') {
            if ((i + 1) >= argc) {
                    printf("No count provided to -r\n");
                    exit(-1);
            }  
            count = atoi(argv[i + 1]);
            i += 2;
        } else {
            s = argv[i];
            i += 1;
        }
    }

    for (i = 0; i < count; i++) {
        printf("%s\n", s);
    }    

    return 0;
}
