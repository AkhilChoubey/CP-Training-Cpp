struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

void getAllAncestorsHelper(TreeNode *root, vector<int> &result, vector<int> &temp, int target)
{
    if (root == NULL)
    {
        return;
    }

    //inserting all vals of path to temp
    temp.push_back(root->val);

    if (root->val == target)
    {
        //removing the node val whose ansestors need's to be found.
        temp.pop_back();
        result = temp;
        return;
    }
    else
    {
        getAllAncestorsHelper(root->left, result, temp, target);
        getAllAncestorsHelper(root->right, result, temp, target);
        temp.pop_back();
    }
}

vector<int> getAllAncestors(TreeNode *root, int target)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> temp;
    vector<int> result;

    getAllAncestorsHelper(root, result, temp, target);

    //If order of ansestors specified.
    reverse(result.begin(), result.end());

    return result;
}