struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

bool isLeaf(TreeNode *root)
{
    return (root != NULL && root->left == NULL && root->right == NULL);
}

void maxPathSumHelper(TreeNode *root, int sum, imt &maxSum)
{
    if (root == NULL)
    {
        return;
    }

    sum += root->val;

    if (isLeaf(root))
    {
        maxSum = max(maxSum, sum);
    }
    else
    {
        maxPathSumHelper(root->left, sum, maxSum);
        maxPathSumHelper(root->right, sum, maxSum);
    }
}

int maxPathSum(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int maxSum = 0;

    maxPathSumHelper(root, 0, maxSum);

    return maxSum;
}