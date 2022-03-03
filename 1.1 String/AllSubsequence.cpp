
//subsequence -- a subsequence is a string between 2 diffrence indices of string , but they can or cannot be continous,
//               i.e , there cound be 0 or more characters removed bettween two indexes,
//               but the subsequence will be in same order as the string.

void AllSubseqence(string &s, string curr= "", int i = 0) { 
    if(i == s.size()-1) {
        cout<<curr<<" ";
        return;
    }

    AllSubsequence(s, curr, i+1);
    AllSubseqence(s, curr + s[i], i+1);
}
    
