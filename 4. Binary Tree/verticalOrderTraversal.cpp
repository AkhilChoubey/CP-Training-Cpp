struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

//Simple vertical order traversal
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

//vertical order traversal with level wise sorting

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return false;
    }
}

void verticalOrderHelper(TreeNode *root, int verticalLevel, int horizontalLevel, map<int, vector<pair<int, int>>> &levelNodes)
{
    // verticalLevel -- level starting from leftmost node to rightmost node
    //horizontalLevel -- normal tree level if root(0) -- then root->left(1), root->right(1).

    if (root == NULL)
    {
        return;
    }
    levelNodes[verticalLevel].push_back({horizontalLevel, root->val});

    verticalOrderHelper(root->left, verticalLevel - 1, horizontalLevel + 1, levelNodes);
    verticalOrderHelper(root->right, verticalLevel + 1, horizontalLevel + 1, levelNodes);
}

vector<vector<int>> verticalOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    map<int, vector<pair<int, int>>> levelNodes;

    verticalOrderHelper(root, 0, 0, levelNodes);

    auto itr = levelNodes.begin();
    while (itr != levelNodes.end())
    {
        sort(itr->second.begin(), itr.second.end(), comparator);
        itr++;
    }

    vector<vector<int>> result(levelNodes.size());

    auto itr2 = levelNodes.begin();
    int i = 0;
    while (itr2 != levelNodes.end())
    {
        for (int j = 0; j < itr2->second.size(); j++)
        {
            result[i].push_back(itr2->second[j].second);
        }
        i++;
        itr2++;
    }
    return result;
}
