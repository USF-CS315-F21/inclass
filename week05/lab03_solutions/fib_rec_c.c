int fib_rec_c_alt(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_rec_c_alt(n - 1) + fib_rec_c_alt(n - 2);
}

int fib_rec_c(int n) {
    int r;
    int f1, f2;
    
    if (n <= 1) {
        r = n;
    } else {
        f1 = fib_rec_c(n - 1);
        f2 = fib_rec_c(n - 2);
        r = f1 + f2;
    }

    return r;
}

