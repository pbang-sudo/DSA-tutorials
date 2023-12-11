#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int value)
{
    if (root != NULL)
    {
        if (value < root->data)
            root->left = insertBST(root->left, value);
        else
            root->right = insertBST(root->right, value);
    }
    else
        return new Node(value);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

Node *searchNode(Node *root, int key)
{
    if (root->data == key)
        return root;
    else if (root->data > key)
        return searchNode(root->left, key);
    else if (root->data < key)
        return searchNode(root->right, key);

    if (root == NULL)
        return NULL;
}

Node *inOrderSucc(Node *root)
{
    Node *currNode = root;
    while (currNode && currNode->left != NULL)
    {
        currNode = currNode->left;
    }
    return currNode;
}

Node *deleteNode(Node *root, int key)
{
    // Case 1 : Node is a leaf node
    // simply delete the node

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Case 2 : Node has one child
        // do replace node with child and delete the node

        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3 : Node has two children
        // replace the node with child with maximum in the left subtree or with the minimum in the right subtree

        Node *temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 6);

    inOrder(root);
    cout << endl;

    root = deleteNode(root, 2);
    inOrder(root);
    cout << endl;
    return 0;
}