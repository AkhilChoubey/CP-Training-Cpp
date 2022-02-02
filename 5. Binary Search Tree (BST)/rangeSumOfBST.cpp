struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void rangeSumBSTHelper(TreeNode *root, int &low, int &high, int &sum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
        rangeSumBSTHelper(root->left, low, high, sum);
        rangeSumBSTHelper(root->right, low, high, sum);
    }
    if (root->val < low)
    {
        rangeSumBSTHelper(root->right, low, high, sum);
    }
    else if (root->val > high)
    {
        rangeSumBSTHelper(root->left, low, high, sum);
    }
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    rangeSumBSTHelper(root, low, high, sum);

    return sum;
}