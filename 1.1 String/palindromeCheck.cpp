bool isPalindrome(string s)
{

    if (s.size() == 0)
    {
        return true;
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < s.size(); i++)
    {
        // if(s[i] < 'a' || s[i] > 'z' || s[i] < '0' || s[i] > '9') {
        if (!isalnum(s[i]))
        {
            s.erase(i, 1);
            i--;
        }
    }

    // normal palindrome check
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}