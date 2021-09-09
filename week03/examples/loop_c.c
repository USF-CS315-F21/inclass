int mult_10_c(int x) {
    int i;
    int r = 0;

    for (i = 0; i < 10; i++) {
        r = r + x;
    }

    return r;
}
