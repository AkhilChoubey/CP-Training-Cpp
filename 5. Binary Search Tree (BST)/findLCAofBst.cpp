struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestorsBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == p || root == q)
    {
        return root;
    }

    TreeNode *left = NULL;
    TreeNode *right = NULL;

    //we will traverse on left side only if p->val or q->val is less than root->val.
    if (p->val < root->val || q->val < root->val)
    {
        left = lowestCommonAncestorsBST(root->left, p, q);
    }
    //we will traverse on right side only if p->val or q->val is greater than root->val.
    if (p->val > root->val || q->val > root->val)
    {
        right = lowestCommonAncestorsBST(root->right, p, q);
    }

    if (left != NULL && right != NULL)
    {
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