struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

vector<int> leftView(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> result;
    int flag = false;
    result.push_back(root->val);

    queue<TreeNode *> Q;
    queue.push(root);
    queue.push(NULL);

    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();

        if (flag)
        {
            result.push_back(root->val);
            flag = false;
        }

        if (root == NULL)
        {
            flag = true;
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
    }
    return result;
}