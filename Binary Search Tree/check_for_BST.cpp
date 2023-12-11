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
void inorder(Node *);

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

bool util(Node *root, int mini, int maxi) {
	if(root == NULL) return true;

	if(root->data <= mini || root->data >= maxi) return false;
	return util(root->left, mini, root->data) &&
			util(root->right, root->data, maxi);
}

bool isBST(Node *root) {
	return util(root, INT_MIN, INT_MAX);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    cout << isBST(root);

    return 0;
}
