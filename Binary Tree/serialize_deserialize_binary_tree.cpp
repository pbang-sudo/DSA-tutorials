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

void solve(Node *root, vector<int> &ans) {
    if(root == NULL) return;
    
    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}

vector<int> serialize(Node *root) 
{
    //Your code here
    vector<int> ans;
    solve(root, ans);
    return ans;
}

void solver(Node *&root, vector<int> &arr, int &index) {
    if(index < 0) return;
    if(arr[index] == MARKER) return;
    int data = arr[index];
    root = new Node(arr[index--]);
    solver(root->left, arr, index);
    root->data = data;
    solver(root->right, arr, index);
}

//Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &A) {
   //Your code here
   Node *root = NULL;
   int index = A.size() - 1;
   solver(root, A, index);
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
    vector<int> ans = serialize(root);
    for(unsigned int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}