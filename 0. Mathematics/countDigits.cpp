int countDigits(int n) {
    int res = 0;
    while(n != 0) {
        n = n/10;
        res += 1;
    }

    return res;
}