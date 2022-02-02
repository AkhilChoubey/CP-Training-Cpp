struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

//LCA -- Least Common Ancestor

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == p || root == q)
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL)
    {
        //this condition will be true if the node is LCA
        return root;
    }
    else if (left != NULL)
    {
        return left;
    }
    else
    {
        // right != NULL
        return right;
    }

    return NULL;
}