int sumarr_rec_c_org(int *arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }
    return arr[start] + sumarr_rec_c_org(arr, start + 1, end);
}

int sumarr_rec_c(int *arr, int start, int end) {
    int r;
    
    if (start == end) {
        r = arr[start];
    } else {
        r = sumarr_rec_c(arr, start + 1, end);
        r = arr[start] + r;
    }

    return r;
}
