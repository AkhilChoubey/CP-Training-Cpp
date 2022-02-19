
// mekhod 1 : find reverse of the number and compare it with original number
bool isPalindrome(int n) {
    int rev = 0;
    int temp = n;

    while(temp != 0) {
        rev = rev*10 + temp%10;
        temp = temp/10;
    }

    return rev == n;
}

//method 2 : reverse second half of the number and compare it with 1st half
bool isPalindrome(int n) {
    int rev = 0;
    while(n > rev) {
        rev = rev*10 + n%10;
        n = n/10;
    }

    return rev == n;
}