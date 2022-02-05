
// Given two strings s1 = "ABCD" s2 = "DABC" check if we can obtain s1 from s2

// Solution : if s2 is rotaion of s1 than we can find s2 in s1+s1 
// s1 + s1 = "ABCDABCD" we can easily find "DABC" (s2) in this.

bool checkForRotation(string &s1, string &s2) {
    if(s1.size() != s2.size()) {
        return false;
    }

    return (s1 + s1).find(s2) != string::npos;
}

// str1.find(str2) return string::npos , if str2 is not present in str1