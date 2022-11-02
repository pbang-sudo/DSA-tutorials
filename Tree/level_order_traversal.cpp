#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int val) {
	Node *node = new Node;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

Node* buildTree(string str) {
	// Corner Case
	if(str.length() == 0 || str[0] == 'N') return NULL;

	// Creating vector of strings from input
	// string after splitting by space
	vector<string> ip;

	istringstream iss(str);
	for(string str; iss >> str;) ip.push_back(str);

	// Creating root of the tree
	Node *root = newNode(stoi(ip[0]));
	
	// Push root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Staring from the second element
	unsigned int i = 1;
	while(!queue.empty() && i < ip.size()) {
		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current Node's value from the string
		string currVal = ip[i];

		// if the left child is not null
		if(currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if(i >= ip.size()) break;
		currVal = ip[i];

		// If the right child is not null
		if(currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}
	return root;
}

vector<int> levelOrder(Node* root)
{
  //Your code here
  vector<int> ans;
  if(root == NULL) return ans;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
      int size = q.size();
      for(int i = 0; i < size; i++) {
        Node* node = q.front();
        q.pop();
        if(node->left != NULL) q.push(node->left);
        if(node->right!= NULL) q.push(node->right);
        ans.push_back(node->data);
      }
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	getline(cin, str);
	Node *root = buildTree(str);
	vector<int> levelorder = levelOrder(root);
	for(unsigned int i = 0; i < levelorder.size(); i++) 
		cout << levelorder[i] << " ";
	return 0;
}