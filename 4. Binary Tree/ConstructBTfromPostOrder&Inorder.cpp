struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

int find(vector<int> &inorder, int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == x)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *buildTreeHelper(vector<int> &postorder, vector<int> &inorder, int start, int end, int &curr)
{
    if (start > end)
    {
        return NULL;
    }

    TreeNode *newNode = new TreeNode(postorder[curr]);
    curr--;

    int index = find(inorder, start, end, newNode->val);

    newNode->right = buildTreeHelper(postorderm inorder, index + 1, end, curr);
    newNode->left = buildTreeHelper(postorder, inorder, start, index - 1, curr);

    return newNode;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int curr = postorder.size() - 1;

    buildTreeHelper(postorder, inorder, 0, postorder.size() - 1, curr);
}