#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node *nextRight;
};

Node* newNode(int val) {
    Node *node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    node->nextRight = NULL;
    
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

void printSpecial(Node *root) {
    if(root == NULL)
        return;

    Node *next_root = NULL;
    while(root != NULL) {
        cout << root->data << " ";

        if(root->left && !(next_root))
            next_root = root->left;
        else if(root->right && !(next_root))
            next_root = root->right;

        root = root->nextRight;
    }

    printSpecial(next_root);
}

void inOrder(Node *root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void connect(Node *root) {
    queue<Node*> q;
    if(root == NULL) return;
    q.push(root);
    while(!q.empty()) {
        vector<Node*> temp;
        temp.clear();
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            temp.push_back(node);
        }
        for(unsigned int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->nextRight = nodes[i + 1];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    connect(root);
    printSpecial(root);
    cout << endl;
    inOrder(root);

    return 0;
}