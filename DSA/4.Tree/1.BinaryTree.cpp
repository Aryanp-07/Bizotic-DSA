#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{

public:
    Node *root;
    BinaryTree() : root(nullptr) {}

    void insert(int val)
    {
        if (root == NULL)
        {
            root = new Node(val);
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            else
            {
                q.front()->left = new Node(val);
                return;
            }

            if (q.front()->right != NULL)
                q.push(q.front()->right);
            else
            {
                q.front()->right = new Node(val);
                return;
            }
            q.pop();
        }
    }

    void inorderTraversal(Node *head)
    {
        if (head == NULL)
            return;

        inorderTraversal(head->left);
        cout << head->data << " ";
        inorderTraversal(head->right);
    }

    void levelOrderTraversal()
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            cout << q.front()->data << " ";
            q.pop();
        }
    }
};

int main()
{
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.inorderTraversal(bt.root);
    cout << endl;
    bt.levelOrderTraversal();
    return 0;
}