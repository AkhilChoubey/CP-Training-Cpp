struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

//Question -- we have to return all possible the root to leaf path.

bool isLeaf(TreeNode *root)
{
    return (root != NULL && root->left == NULL && root->right == NULL);
}

void rootToLeafHelper(TreeNode *root, vector<vector<int>> &result, vector<int> &pathSoFar)
{
    if (root == NULL)
    {
        return;
    }

    pathSoFar.push_back(root->data);
    if (isLeaf(root))
    {
        result.push_back(pathSoFar);
    }
    else
    {
        rootToLeafHelper(root->left, result, pathSoFar);
        rootToLeafHelper(root->right, result, pathSoFar);
    }
    pathSoFar.pop_back();
}

vector<vector<int>> rootToLeafPath(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<vector<int>> result;
    vector<int> pathSoFar;

    rootToLeafPathHelper(root, result, pathSoFar);

    return result;
}