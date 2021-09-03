#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LEN 128


void check_valid_binstr(char *str, int len) {
    bool valid = true;

    for (int i = 0; i < len; i++) {
        if (!(str[i] == '0' || str[i] == '1')) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        printf("Invalid binary string input: %s\n", str);
        exit(-1);
    }
}

void check_valid_decstr(char *str, int len) {
    bool valid = true;

    for (int i = 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        printf("Invalid decimal string input: %s\n", str);
        exit(-1);
    }
}

void check_valid_hexstr(char *str, int len) {
    bool valid = true;
    bool decval = false;
    bool hexval = false;

    for (int i = 0; i < len; i++) {
        decval = str[i] >= '0' && str[i] <= '9';
        hexval = str[i] >= 'A' && str[i] <= 'F';
        if (!(decval || hexval)) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        printf("Invalid hexadecimal string input: %s\n", str);
        exit(-1);
    }
}

void check_valid_base(int base) {
    if (!(base == 2 || base == 10 || base == 16)) {
        printf("Invalid base: %d\n", base);
        exit(-1);
    }
}

uint32_t string_to_uint32(char *str) {
/* Convert a string number to a uint32_t value
 * Valid strings include decimal, binary, and hexadecimal values
 */
    int base = 10;
    uint32_t value = 0;
    int cvalue = 0;
    int i = 0;
    int len;

    len = strlen(str);

    if (len >= 3) {
        if (str[i] == '0' && str[i+1] == 'b') {
            base = 2;
            i = 2;
            check_valid_binstr(&str[2], len-2);
        } else if (str[i] == '0' && str[i+1] == 'x') {
            base = 16;
            i = 2;
            check_valid_hexstr(&str[2], len-2);
        }
    }

    if (base == 10) {
        check_valid_decstr(str, len);
    }
    

    while(str[i] != '\0') {
        value *= base;

        if (str[i] >= '0' && str[i] <= '9') {
            cvalue = str[i] - '0';
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            cvalue = (str[i] - 'A') + 10;            
        }

        value += cvalue;
        i += 1;        
    }

    return value;
}

void uint32_to_string(uint32_t value, char *str, int base) {
/* Convert a uint32_t value into a string representation in the given base.
 * Bases supported: 2, 10, and 16.
 */
    str[0] = '\0';
    char buf[STR_MAX_LEN];
    int len = 0;
    uint32_t div, rem;
    int i = 0, j = 0;

    if (value == 0) {
        buf[len] = '0';
        len += 1;
    } else {
        while (value != 0) {
            div = value / base;
            rem = value % base;
            if (rem <= 9) {
                buf[len] = '0' + rem;
            } else if (rem >= 10 && rem <= 15) {
                buf[len] = 'A' + (rem - 10);                
            }
            len += 1;
            value = div;
        }        
    }

    if (base == 2) {
        str[j] = '0';
        str[j+1] = 'b';
        j = 2;
    } else if (base == 16) {
        str[j] = '0';
        str[j+1] = 'x';
        j = 2;        
    }

    for (i = (len - 1); i >= 0; i--, j++) {
        str[j] = buf[i];
    }

    str[j] = '\0';
}


void test(void) {
    uint32_t value;
    char str[STR_MAX_LEN];
    
    value = string_to_uint32("17");
    printf("string_to_uint32(\"17\") = %u\n", value);
    value = string_to_uint32("0b10001");
    printf("string_to_uint32(\"0b10001\") = %u\n", value);
    value = string_to_uint32("0x11");
    printf("string_to_uint32(\"0x11\") = %u\n", value);
    value = string_to_uint32("0xAB");
    printf("string_to_uint32(\"0xAB\") = %u\n", value);

    uint32_to_string(17, str, 10);
    printf("uint32_to_string(17, str, 10) str = %s\n", str);
    uint32_to_string(17, str, 2);
    printf("uint32_to_string(17, str, 10) str = %s\n", str);
    uint32_to_string(17, str, 16);
    printf("uint32_to_string(17, str, 10) str = %s\n", str);
    uint32_to_string(171, str, 10);
    printf("uint32_to_string(171, str, 16) str = %s\n", str);
}

int main(int argc, char *argv[]) {
    uint32_t value;
    char str[STR_MAX_LEN];
    char *s;
    int base = 10;
    int i = 0;

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'o'
              && argv[i][2] == '\0') {
            if ((i + 1) >= argc) {
                    printf("No base provided to -o\n");
                    exit(-1);
            }
            base = string_to_uint32(argv[i + 1]);
            check_valid_base(base);
            i += 2;
        } else {
            s = argv[i];
            i += 1;
        }
    }

    value = string_to_uint32(s);
    uint32_to_string(value, str, base);
    printf("%s\n", str);

    return 0;
}
