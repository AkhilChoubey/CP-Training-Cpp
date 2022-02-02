struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int start, int end)
{
    // leaf node condition
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    TreeNode *newNode = new TreeNode(nums[mid]);

    newNode->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    newNode->right = sortedArrayToBSTHelper(nums, mid + 1, end);

    return newNode;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return NULL;
    }

    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}