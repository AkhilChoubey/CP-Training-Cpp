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

    // if(root->left != NULL && root->val <= root->left->val) {
    //     flag = false;
    //     return;
    // }
    // if(root->right != NULL && root->val >= root->right->val) {
    //     flag = false;
    //     return;
    // }
    // inorder(root->left, flag);
    // inorder(root->right, flag);
}

bool isValidBST(TreeNode *root)
{
    bool flag = true;
    vector<int> result;
    inorder(root, result);

    for (int i = 1; i < result.size(); i++)
    {
        if (result[i] <= result[i - 1])
        {
            flag = false;
            break;
        }
    }

    return flag;
}