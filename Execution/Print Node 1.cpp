// print all nodes between two given levels
#include <bits/stdc++.h>
using namespace std;
// A binary tree node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// Recursive function to print all nodes between two given levels in a binary tree
void printNodes(Node* root, int start, int end, vector<vector<int>> &ans, int level){
    if(root == NULL) return;
    printNodes(root->left, start, end, ans, level+1);
    if(level >= start && level <= end){
        ans[level-start].push_back(root->data);
    }
    printNodes(root->right, start, end, ans, level+1);
}
int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    int start = 2;
    int end = 3;
    vector<vector<int>> ans(end-start+1);
    printNodes(root, start, end, ans, 1);
    for(auto i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
