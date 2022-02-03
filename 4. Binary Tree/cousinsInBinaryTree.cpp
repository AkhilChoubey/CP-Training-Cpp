

// Given tree and two node values , return true if both the nodes are on same level and both have diffrent parents.

bool isCousins(TreeNode *root, int x, int y)
{

    vector<int> currLevel;
    queue<TreeNode *> Q;

    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();

        if (root == NULL)
        {

            bool findX = false;
            bool findY = false;
            int n = currLevel.size() - 1;
            for (int i = 0; i <= n; i++)
            {
                if (currLevel[i] == x)
                {
                    findX = true;
                }
                if (currLevel[i] == y)
                {
                    findY = true;
                }
            }
            if (findX && findY)
            {
                return true;
            }

            currLevel.clear();
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            currLevel.push_back(root->val);
            if ((root->left != NULL && root->right != NULL) && (root->left->val == x && root->right->val == y || root->left->val == y && root->right->val == x))
            {
                return false;
                break;
            }
            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
    }
    return false;
}