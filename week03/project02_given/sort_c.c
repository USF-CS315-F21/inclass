int find_max_index_c(int *arr, int start, int len);

void sort_c(int *arr, int len) {
    if (len == 1) {
        return;
    }
       
    for (int i = 0; i < len; i++) {
        int idx = find_max_index_c(arr, i + 1, len);
        if (arr[idx] > arr[i]) {
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}
