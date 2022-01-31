struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

void verticalOrderHelper(TreeNode *root, int level, map<int, vector<int>> &levelWiseNodes)
{
    if (root == NULL)
    {
        return;
    }

    levelWiseNodes[level].push_back(root->data);

    verticalOrderHelper(root->left, level - 1, levelWiseNodes);
    verticalOrderHelper(root->right, level + 1, levelWiseNodes);
}

vector<vector<int>> verticalOrder(TreeNode *root)
{

    if (root == NULL)
    {
        return {};
    }

    map<int, vector<int>> levelWiseNodes;

    verticalOrderHelper(root, 0, levelWise);

    vector<vector<int>> result;
    int i = 0;
    auto itr = levelWiseNodes.begin();
    while (itr != levelWiseNodes.end())
    {
        for (int j = 0; j < itr->second.size(); j++)
        {
            result[i].push_back(itr->second[j]);
        }
        itr++;
        i++;
    }

    return result;
}