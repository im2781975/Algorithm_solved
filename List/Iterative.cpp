// iterative postorder traversal using stack
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
 
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
 
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
 
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
 
        // Get the current node's value from the string
        string currVal = ip[i];
 
        // If the left child is not null
        if (currVal != "N") {
 
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
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
// An iterative function to do postorder traversal of a given binary tree
vector<int> postOrder(Node* node)
{
    stack<Node*> s;
    // vector to store the postorder traversal
    vector<int> post;
    // Using unordered map as hash table for hashing to mark the visited nodes
    unordered_map<Node*, int> vis;
    // push the root node in the stack to traverse the tree
    s.push(node);
    // stack will be empty when traversal is completed
    while (!s.empty()) {
        // mark the node on the top of stack as visited
        vis[s.top()] = 1;
 
        // if left child of the top node is not NULL and not visited push it into the stack
        if (s.top()->left != 0) {
            if (!vis[s.top()->left]) {
                s.push(s.top()->left);
                continue;
            }
        }
        // Otherwise if the right child of the top node is not NULL and not visited push it into the stack
        if (s.top()->right != 0) {
            if (!vis[s.top()->right]) {
                s.push(s.top()->right);
                continue;
            }
        }
        // Add the value of the top node in our postorder traversal answer if none of the above two conditions are met
        post.push_back(s.top()->data);
        // Remove the top node from the stack
        s.pop();
    }
    // post will now contain the postorder traversal of the tree
    return post;
}
int main()
{
    string s = "1 2 3 4 5 6 7";
    Node* root = buildTree(s);
 
    vector<int> ans;
    ans = postOrder(root);
    cout << "Post order traversal of binary tree is :\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
// iterative postorder traversal using one stack
#include <bits/stdc++.h>
using namespace std;
// A tree node
struct Node {
    int data;
    struct Node *left, *right;
};
// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// An iterative function to do postorder traversal of a given binary tree
vector<int> postOrderIterative(struct Node* root)
{
    vector<int> postOrderList;
    // Check for empty tree
    if (root == NULL)
        return postOrderList;
    stack<Node*> S;
    S.push(root);
    Node* prev = NULL;
    while (!S.empty()) {
        auto current = S.top();
        // go down the tree in search of a leaf an if so process it and pop stack otherwise move down
        if (prev == NULL || prev->left == current
            || prev->right == current) {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
            // go up the tree from left node, if the child is right push it onto stack otherwise process  parent and pop stack 
        }
 
        else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
            //go up the tree from right node and after
           // coming back from right node process parent and pop stack 
        }
        else if (current->right == prev) {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}
// An iterative function to do postorder traversal of a
// given binary tree
vector<int> postOrderIterative(struct Node* root)
{
    vector<int> postOrderList;
    stack<Node*> st;
    while (true) {
        while (root) {
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            return postOrderList;
        root = st.top();
        st.pop();
        if (!st.empty() && st.top() == root)
            root = root->right;
        else {
            postOrderList.push_back(root->data);
            root = NULL;
        }
    }
    return postOrderList;
}
int main()
{
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Post order traversal of binary tree is :\n");
    printf("[");
    vector<int> postOrderList = postOrderIterative(root);
    for (auto it : postOrderList)
        cout << it << " ";
    printf("]");
    return 0;
}
