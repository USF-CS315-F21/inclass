int addone_c(int x) {
    int r;

    r = x + 1;

    return r;
}

int addtwo_c(int x) {
    int r;

    r = addone_c(x);

    r = addone_c(r);

    return r;
}
