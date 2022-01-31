struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

vector<int> rightView(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> result;
    vector<int> currentLevel;

    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();

        if (root == NULL)
        {
            result.push_back(current[current.size() - 1]);
            current.clear();
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            current.push_back(root->val);
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