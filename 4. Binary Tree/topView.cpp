struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

void topViewHeper(TreeNode *root, int horizontalLevel, int verticalLevel, map<int, pair<int, int>> &levelNodes)
{
    if (root == NULL)
    {
        return;
    }

    if (levelNodes[horizontalLevel] != NULL)
    {
        if (levelNodes[horizontalLevel].first > verticalLevel)
        {
            levelNodes[horizontalLevel] = {verticalLevel, root->val};
        }
    }
    else
    {
        levelNodes[horizontalLevel] = {verticalLevel, root->val};
    }
    //levelNodes[verticalLevel] = topViewPair(verticalLevel, )

    topViewHeper(root->left, horizontalLevel - 1, verticalLevel + 1, levelNodes);
    topViewHeper(root->right, horizontalLevel + 1, verticalLevel + 1, levelNodes);
}

vector<int> topView(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    map<int, pair<int, int>> levelNodes;

    topViewHelper(root, 0, 0, levelNodes);

    vector<int> result(levelNodes.size());
    int i = 0;

    for (auto itr = levelNodes.begin(); itr != levelNodes.end(); itr++)
    {
        result[i] = itr->second;
        i++;
    }

    return result;
}