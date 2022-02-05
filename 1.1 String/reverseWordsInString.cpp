
// input : "I love coding"
// output : "coding love I"

// Naive approach - push all character of string into a stack one by one , pop words from stack and append to output.

// Efficient : we reverse each word first , then after reversing individial words , we reverse 
//    the whole string . "abc ef" --> "cba fe" --> "ef abc"

void reverse(string &s, int start, int end) {
    while(start <= end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseWords(string s) {
    int n = s.size();
    int start = 0;
    //reversing individual string
    for(int end = 0; end < n; end++) {
        if(s[end] == ' ') {
            reverse(s, start, end-1);
            start = end + 1;
        }
    }

    //reversing last string
    reverse(s, start, n-1);

    //reversing whole string to get our output
    reverse(s, 0, n-1);

    return s;
}