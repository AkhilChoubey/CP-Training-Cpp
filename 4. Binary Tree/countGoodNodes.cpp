struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

// A nodes is a good node if it is greater than all the nodes in the path from root to that node

void countGoodNodesHelper(TreeNode *root, int currMax, int &count)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val >= currMax)
    {
        count += 1;
        currMax = root->val;
    }

    countGoodNodesHelper(root->left, currMax, count);
    countGoodNodesHelper(root->right, currMax, count);
}

int countGoodNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;
    int currMax = root->val;

    countGoodNodesHelper(root, currMax, count);

    return count;
}