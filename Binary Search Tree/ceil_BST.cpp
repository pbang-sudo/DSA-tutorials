#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int x) {
		data = x;
		right = NULL;
		left = NULL;
	}
};

Node *insert(Node*, int);
Node *buildTree(string);

Node *insert(Node *tree, int val) {
	if(tree == NULL) return new Node(val);

	if(val < tree->data) {
		tree->left = insert(tree->left, val);
	} else if (val > tree->data) {
		tree->right = insert(tree->right, val);
	}
	return tree;
}

Node *buildTree(string str) {
	istringstream ss(str);
	string word;
	vector<int> nodeData;
	while(ss >> word) {
		nodeData.push_back(stoi(word));
	}
	int n = nodeData.size();
	Node *root = NULL;
	for(int i = 0; i < n; i++) {
		root = insert(root, nodeData[i]);
	}
	return root;
}

int findCeil(Node* root, int key) {
    if (root == NULL) return -1;
    int c = -1;
    while(root) {
        if(root->data == key) {
            c = root->data;
            return c;
        }
        
        if(key > root->data) {
            root = root->right;
        }
        
        if(key < root->data) {
            c = root->data;
            root = root->left;
        }
    }
    return c;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    int x;
    cin >> x;
    cout << findCeil(root, x);

    return 0;
}