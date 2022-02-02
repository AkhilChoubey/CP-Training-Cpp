struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find(vector<int> &preorder, int start, int end, int x)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (preorder[i] > x)
        {
            break;
        }
    }
    return i;
}

TreeNode *buildBSTfromPreorderHelper(vector<int> &preorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    TreeNode *newNode = new TreeNode(preorder[start]);

    // Index of element which is just greater than newNode->val
    int index = find(preorder, start + 1, end, newNode->val);
    newNode->left = buildBSTfromPreorderHelper(preorder, start + 1, index - 1);
    newNode->right = buildBSTfromPreorderHelper(preorder, index, end);

    return newNode;
}

TreeNode *buildBSTfromPreorder(vector<int> &preorder)
{
    if (preorder.size() == 0)
    {
        return NULL;
    }

    return buildBSTfromPreorderHelper(root, 0, preorder.size() - 1);
}