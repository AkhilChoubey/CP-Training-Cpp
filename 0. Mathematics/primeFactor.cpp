
// Prime Factors : the prime numbers whose multiplication will give us original number are known as prime factors.

vector<int> primeFactors(int n) {

    if(n <= 1) {
        return {};
    }

    vector<int> result;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            result.push_back(i);
            n = n/i;
        }
    }

    return result;
}