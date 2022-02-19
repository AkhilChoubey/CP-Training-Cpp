//reccursive 
int fact(int n) {
    if(n == 0) {
        return 1;
    }

    return n*fact(n-1);
}

//iterative
int fact(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }

    return res;
}