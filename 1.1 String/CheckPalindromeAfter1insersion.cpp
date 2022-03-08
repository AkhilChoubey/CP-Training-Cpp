
// We are given with a string , we have to check if we will be able to convert the string
// into palindrome , after 1 insertion.
// E.g - "abca" --> we can make this a palingdrome after inserting b at second last position.

// logic : we will maintain a flag , we will initialize it with true, if we find an 
//         unmatched (in two pointer approach), we will set flag to flase and continue , 
//         if we find another unmatched character we will return false.

bool checkPalingromeAfter1insertion(string s) {
    int n = s.size();

    bool flag = true;

    int start = 0;
    int end = n-1;

    while(start <= end) {
        if(s[start] != s[end]) {
            if(flag) {
                if(s[start+1] == s[end]) {
                    start++;
                    continue;
                }
                else if(s[end-1] == s[start]) {
                    end--;
                    continue;
                }
                flag = false;
            }
            else {
                return false;
            }
        }

        start++;
        end--;
    }
}