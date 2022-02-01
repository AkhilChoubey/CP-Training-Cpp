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

TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &curr)
{
    if (start > end)
    {
        return NULL;
    }

    TreeNode *newNode = new TreeNode(preorder[curr]);
    curr++;

    int index = find(inorder, start, end, newNode->val);
    newNode->left = buildTreeHelper(preorder, inorder, start, index - 1, curr);
    newNode->right = buildTreeHelper(preorder, inorder, index + 1, end, curr + index, curr);

    return newNode;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{

    int curr = 0;
    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, curr);
}