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

/*Node *buildTree(int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd, 
                map<int, int> inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    Node *root = new Node(pre[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(pre, preStart + 1, preStart + numsLeft, 
                            in, inStart, inRoot - 1, inMap);
    root->right = buildTree(pre, preStart + numsLeft + 1, preEnd, 
                            in, inRoot + 1, inEnd, inMap);
    return root;
} 

Node *buildTree(int in[],int pre[], int n) {
    // Code here
    map<int, int> inMap;

    for(int i = 0; i < n; i++) {
        inMap[in[i]] = i;
    }

    Node *root = buildTree(pre, 0, n - 1, in, 0, n - 1, inMap);
    return root;
}*/

Node* constructTree(int in[], int inStart, int inEnd, int pre[], int &preIndex, int n) {
    // base case
    if(preIndex >= n || inStart > inEnd) {
        return NULL;
    }

    int rootElement = pre[preIndex++];
    Node* root = new Node(rootElement);

    // Searching the index of rootElement between a specific range not in the whole in[] array
    // to avoid any error due to duplicate elements in the array
    int inRootIdx = inStart;
    for( ; inRootIdx<inEnd; inRootIdx++) {
        if(in[inRootIdx] == rootElement) break;
    }
    root->left = constructTree(in, inStart, inRootIdx - 1, pre, preIndex, n);
    root->right = constructTree(in, inRootIdx + 1, inEnd, pre, preIndex, n);
    return root;
}

Node* buildTree(int in[], int pre[], int n) {
    int preIndex = 0;
    Node* res = constructTree(in, 0, n - 1, pre, preIndex, n);
    return res;
}

void postOrder(Node *root) {
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int in[n], pre[n];

    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> pre[i];

    Node *root = buildTree(in, pre, n);
    postOrder(root);
    return 0;
}