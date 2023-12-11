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

void mapNodes(Node *root, vector<Node*> &nodes) {
	if(root == NULL) return;

	mapNodes(root->left, nodes);
	nodes.push_back(root);
	mapNodes(root->right, nodes);
}

Node *buildTreeUtil(vector<Node*> &nodes, int start, int end) {
	if(start > end) return NULL;

	int mid = (start + end) / 2;
	Node *root = nodes[mid];

	root->left = buildTreeUtil(nodes, start, mid - 1);
	root->right = buildTreeUtil(nodes, mid + 1, end);
	return root;
}

Node *buildBalancedTree(Node *root) {
	vector<Nodes*> nodes;
	mapNodes(root, nodes);
	return buildTreeUtil(nodes, 0, nodes.size() - 1);
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