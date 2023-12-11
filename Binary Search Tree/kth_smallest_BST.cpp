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

int KthSmallestElement(Node *root, unsigned int k) {
	/*Node *node = root, *prev = NULL;
	while(node) {
		if(node->left) {
			prev = node->left;
			while(prev->right)
				prev = prev->right;
			prev->right = node->right;
			node->right = node->left;
			node->left = NULL;
		}
		node = node->right;
	}

	while(root && k > 0) {
		if(k == 0) return root->data;
		root = root->right;
		k--;
	}
	return -1;*/
	vector<int> inorder;
    Node *curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node *prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }

            else {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    if(k <= inorder.size() - 1) return inorder[k - 1];
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    unsigned int x;
    cin >> x;
    cout << KthSmallestElement(root, x);

    return 0;
}