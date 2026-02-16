//morris traversal
#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x) , left(NULL)
        , right(NULL){}
};
vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    TreeNode* curr = root;
    while (curr) {
        if (!curr->right) {
            // if there is no right child ,add the current node's value to the vector
            res.push_back(curr->val);
            curr = curr->right;
            // move to the right child
        }
        else { // if there is a right child
            TreeNode* next
                = curr->right; 
                // set the next node to the right child
            while (next->left
                   && next->left
                          != curr) { 
                // traverse the left subtree of the right child untill a leaf node or the current node is reached
                next = next->left;
            }
            if (!next->left) {
                 // if the left child of the next node is NULL
                res.push_back(curr->val);
                next->left = curr;
                curr = curr->right;
            }
            else {
                next->left = NULL;
                curr = curr->left;
            }
        }
    }
    return res;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    vector<int> res = rightSideView(root);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
