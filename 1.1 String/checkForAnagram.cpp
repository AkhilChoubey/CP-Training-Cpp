
// Anagram -> Every characters of s1 must be present in s2 , also there frequencies will be same.
//  (we can say , there permutation should be same) Ex - listen & silent

// naive approach - we sort both the string and if resultant strings are same , they are anagram

// O(n) Logic -> we will use ASCII value of characters , we maintain an count array, for every characters
// for s1 we increment the ASCII value in the array and for s2 we will decrement the value .
// if all the value cancel out each other , we will return true else false.

const int CHAR = 256;
bool anagramCheck(string &s1, string &s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    vector<int> count(CHAR, 0);
    // for s1 increment value of that character in array and for s2 decrementing
    for (int i = 0; i < s1.size(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    // checking if all count array value is 0 or not , if 0 return true else false.
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }

    return true;
}