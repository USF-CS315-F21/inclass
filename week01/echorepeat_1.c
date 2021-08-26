#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int count = 0;

    if (argc != 4) {
        printf("usage: echorepeat <string> -r <count>\n");
        exit(-1);
    }

    if (!(argv[2][0] == '-' && argv[2][1] == 'r' 
          && argv[2][2] == '\0')) {
        printf("usage: echorepeat <string> -r <count>\n");
        exit(-1);        
    }

    count = atoi(argv[3]);

    for (int i; i < count; i++) {
        printf("%s\n", s);
    }    

    return 0;
}
