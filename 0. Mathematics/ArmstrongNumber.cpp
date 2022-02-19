
bool isArmstrong(int n) {
    int countDigit = 0;
    int temp = n;
    // counting the number of digits in the number
    while(temp != 0) {
        temp = temp/10;
        countDigit += 1;
    }
    // adding digit^digitCount of all digits
    int res = 0;
    int temp2 = n;
    while(temp2 != 0) {
        res += pow(temp2%10, countDigit);
        //alternative
        // int res1 = 1;
        // for(int i = 0; i < countDigit; i++) {
        //     res1 = res1*temp%10;
        // }
        // res += res1;
        temp2 = temp2/10;
    }

    return res == n;
}