#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* constructTree(int in[], int inStart, int inEnd, int post[], int &postIndex, int n) {
    // base case
    if(postIndex < 0 || inStart > inEnd) {
        return NULL;
    }

    int rootElement = post[postIndex--];
    Node* root = new Node(rootElement);

    // Searching the index of rootElement between a specific range not in the whole in[] array
    // to avoid any error due to duplicate elements in the array
    int inRootIdx = inStart;
    for( ; inRootIdx < inEnd; inRootIdx++) {
        if(in[inRootIdx] == rootElement) break;
    }
    root->right = constructTree(in, inRootIdx + 1, inEnd, post, postIndex, n);
    root->left = constructTree(in, inStart, inRootIdx - 1, post, postIndex, n);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n - 1;
    Node *root = constructTree(in, 0, n - 1, post, postIndex, n);
    return root;
}

void preOrder(Node *root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int in[n], post[n];

    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> post[i];

    Node *root = buildTree(in, post, n);
    preOrder(root);
    return 0;
}