int find_max_index_c(int *arr, int start, int len) {
    int i;
    int idx = start;
    for (i = start; i < len; i++) {
        if (arr[i] > arr[idx]) {
            idx = i;
        }
    }
    return idx;
}
