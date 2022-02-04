
// check if s2 is subsequence of s1
bool isSubsequence(string s2, string s1)
{
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            j++;
        }
        i++;
    }
    if (j == s2.size())
    {
        return true;
    }

    return false;
}