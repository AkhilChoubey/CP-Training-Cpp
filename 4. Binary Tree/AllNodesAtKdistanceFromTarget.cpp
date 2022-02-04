struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

map<TreeNode *, TreeNode *> parent;

map<TreeNode *, bool> visited;

vector<int> result;

void dfs(TreeNode *target, int curr, int k)
{

    if (curr == k)
    {
        result.push_back(target->val);
    }

    visited[target] = true;

    // moving left
    if (target->left != NULL && !visited[target->left])
    {
        dfs(target->left, curr + 1, k);
    }
    // moving right
    if (target->right != NULL && !visited[target->right])
    {
        dfs(target->right, curr + 1, k);
    }
    // checking for parent and moving up
    if (parent[target] && !visited[parent[target]])
    {
        dfs(parent[target], curr + 1, k);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    if (root == NULL)
    {
        return {};
    }

    queue<TreeNode *> Q;
    Q.push(root);
    parent[root] = NULL;

    // bfs calling to store parent of all node.
    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();

        if (root->left != NULL)
        {
            Q.push(root->left);
            parent[root->left] = root;
        }
        if (root->right != NULL)
        {
            Q.push(root->right);
            parent[Q.right];
        }
    }

    dfs(target, 0, k);

    return result;
}