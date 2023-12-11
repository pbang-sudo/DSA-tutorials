#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *buildTree(string str)
{
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

/*void markParents(Node *root, unordered_map<Node*, Node*> &parent_marks) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *node = q.front();
        q.pop();
        if(node->left) {
            q.push(node->left);
            parent_marks[node->left] = node;
        }

        if(node->right) {
            q.push(node->right);
            parent_marks[node->right] = node;
        }
    }
}

Node *targetAdd(Node *root, int target) {
    if(root == NULL) return NULL;
    if(root->data == target) return root;
    targetAdd(root->left, target);
    targetAdd(root->right, target);
}

vector <int> KDistanceNodes(Node* root, int tar, int k) {
    // return the sorted vector of all nodes at k dist
    unordered_map<Node*, Node*> parent_marks;
    markParents(root, parent_marks);

    unordered_map<Node*, bool> visited; // A visited nodes map;
    queue<Node*> q;
    Node *target = targetAdd(root, tar);
    q.push(target);
    visited[target] = true;
    int currLvl = 0;

    while(!q.empty()) {
        int size = q.size();
        if(currLvl++ == k) break;
        for(int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();

            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }

            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }

            if(parent_marks[target] && !visited[parent_marks[node]]) {
                q.push(parent_marks[node]);
                visited[parent_marks[node]] = true;
            }
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        Node *node = q.front();
        q.pop();
        ans.push_back(node->data);
    }
    return ans;
}*/

void parent(Node *root, Node *&res, int target, unordered_map<Node *, Node *> &m)
{
    if (!root)
        return;
    if (root->data == target)
    {
        res = root;
    }
    m[root->left] = root;
    m[root->right] = root;
    parent(root->left, res, target, m);
    parent(root->right, res, target, m);
}

vector<int> KDistanceNodes(Node *root, int target, int k)
{
    // return the sorted vector of all nodes at k dist
    vector<int> ans;
    unordered_map<Node *, Node *> m;
    unordered_map<Node *, bool> visited;

    Node *res = NULL;
    parent(root, res, target, m);
    queue<Node *> q;
    q.push(res);
    visited[res] = true;
    int c = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (c == k)
            break;
        c++;
        for (int i = 0; i < size; i++)
        {
            Node *t = q.front();
            q.pop();

            if (t->left && !visited[t->left])
            {
                q.push(t->left);
                visited[t->left] = true;
            }

            if (t->right && !visited[t->right])
            {
                q.push(t->right);
                visited[t->right] = true;
            }
            if (m[t] && !visited[m[t]])
            {
                q.push(m[t]);
                visited[m[t]] = true;
            }
        }
    }

    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    int target, k;
    cin >> target >> k;
    vector<int> ans = KDistanceNodes(root, target, k);
    for (unsigned int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}