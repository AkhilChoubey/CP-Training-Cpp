
// we are given with a string, we have to find and return leftnost repeating character.
// Ex - "abbcdde" output : 1 (leftmost index of b)

// O(n) Logic -> we use the ASCII value of characters, we increase the count[s[i]] for each character,
//               and first character in count with value is more than one is our answer.

const int CHAR = 256;
int leftmostRepeatingCharacter(string s)
{
    if (s.size() == 0)
    {
        return 0;
    }

    vector < int count(CHAR, 0);

    // incrementing value of count for each character
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
    }
    // checking character with value more than 1 in count
    for (int i = 0; i < s.size(); i++)
    {
        if (count[s[i]] > 1)
        {
            return i;
        }
    }
    return -1;
}