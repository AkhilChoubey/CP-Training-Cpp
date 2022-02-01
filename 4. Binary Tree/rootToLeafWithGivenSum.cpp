struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

//Question an binary tree is given and a targetSum is given ,
//we need to find the root to leaf path sum, which is equal to target sum,
// if any root to leaf sum == targetSum return true else return false.

bool isLeaf(TreeNode *root)
{
    return (root != NULL && root->left == NULL && root->right == NULL);
}

void rootToLeafWithGivenSumHelper(TreeNode *root, int sum, int targetSum, bool &flag)
{
    if (root == NULL)
    {
        return;
    }

    //adding sum of each node untill we reach to leaf.
    sum += root->val;

    if (isLeaf(root))
    {
        if (sum == targetSum)
        {
            flag = true;
            return;
        }
    }
    else
    {
        rootToLeafWithGivenSumHelper(root->left, sum, targetSum, flag);
        rootToLeafWithGivenSumHelper(root->right, sum, targetSum, flag);
    }
}

bool rootToLeafWithGivenSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }

    bool flag = false;

    rootToLeafWithGivenSumHelper(root, sum, targetSum, flag);

    return flag;
}