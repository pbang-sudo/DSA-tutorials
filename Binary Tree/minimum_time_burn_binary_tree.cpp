#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val) {
    Node *node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Creating root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Staring from the second element
    unsigned int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // if the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void parentMap(Node *root, Node *&res, unordered_map<Node*, Node*> &m, int target) {
    if(root == NULL) return;
    if(root->data == target) res = root;
    if(root->left) m[root->left] = root;
    if(root->right) m[root->right] = root;

    parentMap(root->left, res, m, target);
    parentMap(root->right, res, m, target);
}



int minTime(Node *root, int tar) {
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, bool> visited;
    Node *target = NULL;
    queue<Node*> q;
    if(root == NULL) return 0;
    // if(!root->left && !root->right) return 1;
    
    parentMap(root, target, parent, tar);
    q.push(root);
    visited[root] = true;
    int count = 0;

    while(!q.empty()) {
        int size = q.size();
        int flag = 0;
        for(int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left && !visited[node->left]) {
                flag = 1;
                q.push(node->left);
                visited[node->left] = true;
            }

            if(node->right && !visited[node->right]) {
                flag = 1;
                q.push(node->right);
                visited[node->right] = true;
            }

            if(parent[node] && !visited[parent[node]]) {
                flag = 1;
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
            if(flag) count++;
        }
    }
    return count / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    int target;
    cin >> target;
    cout << minTime(root, target);

    return 0;
}