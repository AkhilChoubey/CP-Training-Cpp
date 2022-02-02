
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *populateNextPointer(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *dummy = root;
    queue<Node *> Q;
    queue<Node *> Q2;

    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();
        Q2.push(root);

        if (root == NULL)
        {
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
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

    Node *temp;
    while (!Q2.empty())
    {
        if (Q2.front() != NULL)
        {
            temp = Q.front();
            Q.pop();
            temp->next = Q.front();
        }
        else
        {
            Q.pop();
        }
    }
    return dummy;
}