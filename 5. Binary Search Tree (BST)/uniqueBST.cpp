struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// we are given with number n , we need to return number of unique BST , formed with number n.
// we can find the solution using catalan's number , catalan(i)  = catalan(i)*catalan(n - i - 1);

// storing catalan value in map , so that we could use it later.

unordered_map<int, int> m;

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.find(i) == m.end())
        {
            m[i] = catalan(i);
        }
        if (m.find(n - i - 1) == m.end())
        {
            m[n - i - 1] = catalan(n - i - 1);
        }
        res += m[i] * m[n - i - 1];
    }
    return res;
}

int uniqueBST(int n)
{
    return catalan(n);
}
