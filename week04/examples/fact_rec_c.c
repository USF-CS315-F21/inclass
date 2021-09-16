int fact_rec_c(int n) {
    if (n == 0) {
        return 1;
    } else {
        return fact_rec_c(n - 1) * n;
    }
}
