// we are given with a string, we have to find and return leftnost non-repeating character.
// Ex - "abbcdde" output : 0 (leftmost index of a)

// O(n) Logic -> we use the ASCII value of characters, we increase the count[s[i]] for each character,
//               and first character in count with value is equal to one is our answer.

const int CHAR = 256;
int leftmostNonRepeatingCharacter(string s)
{
    if (s.size() == 0)
    {
        return 0;
    }

    vector<int> count(CHAR, 0);

    // incrementing value of count for each character.
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
    }

    // checking and returing 1st charecter with count value 1.
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 1)
        {
            return i;
        }
    }
    return -1;
}