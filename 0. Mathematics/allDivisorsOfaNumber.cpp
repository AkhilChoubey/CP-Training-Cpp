vector<int> allDivisors(int n) {

    vector<int> result;

    for(int i = 1; i*i < n; i++) {
        if(n%i == 0) {
            result.push_back(i);

            // if i is divisor of n then (n/i) is also divisor of n
            if((n/i) != i) {
                result.push_back(n/i);
            }
        }
    }

    return result;
}

