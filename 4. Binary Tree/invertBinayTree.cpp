struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

TreeNode *invertBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left != NULL && root->right != NULL)
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    else if (root->left != NULL)
    {
        root->right = root->left;
        root->left = NULL;
    }
    else if (root->right != NULL)
    {
        root->left = root->right;
        root->right = NULL;
    }

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

    return root;
}