struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

// Given the root of a binary tree, flatten the tree into a "linked list" :

// --The "linked list" should use the same TreeNode class where the right child pointer
//    points to the next node in the list and the left child pointer is always null.

// --The "linked list" should be in the same order as a pre - order traversal of the binary tree.

void preorder(TreeNode *root, vector<int> &temp)
{
    if (root == NULL)
    {
        return;
    }

    temp.push_back(root->val);
    preorder(root->left, temp);
    preorder(root->right, temp);
}

void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    vector<int> temp;
    preorder(root, temp);
    for (int i = 1; i < temp.size(); i++)
    {
        root->right = new TreeNode(temp[i]);
        root->left = NULL;
        root = root->right;
    }
}