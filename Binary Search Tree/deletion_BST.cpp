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

void inorder(Node *root) {
	if(root == NULL) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

Node *deleteNode(Node *root, int x) {
	if(root == NULL) return root;

	if(root->data > x)
		root->left = deleteNode(root->left, x);
	else if(root->data < x)
		root->right = deleteNode(root->right, x);
	else {
		if(root->left == NULL and root->right == NULL)
			return NULL;
		else if(root->left == NULL) {
			Node *node = root->right;
			free(root);
			return node;
		}
		else if(root->right == NULL) {
			Node *node = root->left;
			free(root);
			return node;
		}
		else {
			// If the node has two children then find the minimum and replace it with.
			Node *node = root->right;
			while(node && node->left != NULL)
				node = node->left;
			root->data = node->data;
			root->right = deleteNode(root->right, node->data);
		}
	}
	return root;
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
    inorder(deletion(root, x));

    return 0;
}