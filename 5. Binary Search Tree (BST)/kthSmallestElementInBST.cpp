struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

int kthSmallestElementInBST(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }

    vector<int> result;

    inorder(root, vector);

    return result[k - 1];
}