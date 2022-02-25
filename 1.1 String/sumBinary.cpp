// given two strings , we need to return there sum in string
string sumBinary(string a, string b) {
    int len1 = a.size() - 1;
    int len2 = b.size() - 1;
    int carry = 0;
    string result;

    while(len1 >= 0 || len2 >= 0 || carry) {
        if(len1 >= 0) {
            carry += a[len1] - '0';
            len1--;
        }

        if(len2 >= 0) {
            carry += b[len2] - '0';
            len2--;
        }

        result += carry%2 + '0';
        carry = carry/2;
    }

    return result;
}
