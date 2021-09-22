#include <stdbool.h>

int pal_rec_c_org(char *str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return pal_rec_c_org(str, start + 1, end - 1);
}

int pal_rec_c(char *str, int start, int end) {
    bool r;
    
    if (start >= end) {
        r = true;
    } else if (str[start] != str[end]) {
        r = false;
    } else {
       r = pal_rec_c(str, start + 1, end - 1);
    }

    return r;
}
