struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

int LeafToLeafMaxSumHelper(TreeNode *root, int &maxSum)
{
    if (root == NULL)
    {
        maxSum = 0;
        return 0;
    }

    if (isLeaf(root))
    {
        maxSum = 0;
        return root->val;
    }

    int lSum = 0, rSum = 0;

    lSum = LeafToLeafMaxSumHelper(root->left, maxSum);
    rSum = LeafToLeafMaxSumHelper(root->right, maxSum);

    if (root->left != NULL && root->right != NULL)
    {
        maxSum = max(maxSum, root->val + lSum + rSum);
        return max(lSum, rSum) + root->val;
    }
    else if (root->left != NULL)
    {
        return root->val + lSum;
    }
    else
    {
        //root->right != NULL
        return root->val + rSum;
    }
}

int LeafToLeafMaxSum(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int maxSum = 0;
    LeafToLeafMaxSumHelper(root, maxSum);

    return maxSum;
}