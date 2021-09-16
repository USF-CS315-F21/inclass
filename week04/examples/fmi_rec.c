#include <stdio.h>
#include <stdlib.h>

int fmi_iter_c(int *arr, int start, int len);
int fmi_rec_c(int *arr, int len, int i, int max_i);
int fmi_rec_s(int *arr, int len, int i, int max_i);

int main(int argc, char **argv) {
    const int ARR_MAX = 32;
    int arr[ARR_MAX];

    if (argc == 1) {
        printf("usage: find_max_index number ...\n");
        exit(-1);
    }

    for (int i = 0; i < argc - 1; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    int len = argc - 1;

    int ci_result = fmi_iter_c(arr, 0, len);
    printf("C: %d\n", ci_result);

    int c_result = fmi_rec_c(arr, len, 1, 0);
    printf("C: %d\n", c_result);

    int s_result = fmi_rec_s(arr, len, 1, 0);
    printf("ASM: %d\n", s_result);

    return 0;
}
