
// lcm(a,b) = (a*b)/gcd(a,b)

int gcd(int a, int b) {
    while(a != b) {
        if(a > b) {
            a = a-b;
        }
        else {
            b = b-a;
        }

        return a;
    }
}

int lcm(int n, int b) {
    return (a*b) / gcd(a,b);
}