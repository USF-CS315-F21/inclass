int fact_rec_c(int n) {
    if (n == 0) {
        return 1;
    } else {
        return fact_rec_c(n - 1) * n;
    }
}

int fact_rec_c_alt(int n) {
    int r;
    
    if (n == 0) {
        r = 1;
    } else {
        r = fact_rec_c(n - 1) * n;
    }

    return r;
}
