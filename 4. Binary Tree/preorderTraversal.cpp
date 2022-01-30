struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

vector<int> preorder(TreeNode *root, vector<int> &result)
{
    if (root = NULL)
    {
        return {};
    }

    //  Root -> Left -> Right

    result.push_back(root->val);
    inorder(root->left, result);
    inorder(root->right, result);
}