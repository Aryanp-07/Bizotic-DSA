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

class BST
{
public:
    void insert(Node *&root, int val)
    {
        if (root == NULL)
        {
            root = new Node(val);
            return;
        }
        if (val < root->data)
        {
            if (root->left != NULL)
                insert(root->left, val);
            else
                root->left = new Node(val);
        }
        else
        {
            if (root->right != NULL)
                insert(root->right, val);
            else
                root->right = new Node(val);
        }
    }

    void inorderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void levelOrderTraversal(Node *root)
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

    bool search(Node *root, int key)
    {
        if (root == NULL)
            return false;
        if (key < root->data)
            return search(root->left, key);
        if (key > root->data)
            return search(root->right, key);
        return true;
    }
};

int main()
{
    Node *root = NULL;
    BST bst;
    bst.insert(root, 10);
    bst.insert(root, 15);
    bst.insert(root, 5);
    bst.insert(root, 2);
    bst.insert(root, 20);
    bst.inorderTraversal(root);
    cout << endl;
    cout << bst.search(root, 10) << endl;
    bst.levelOrderTraversal(root);
    cout << endl;
    cout << bst.count << endl;
    return 0;
}