//find next right of a given key 
#include <iostream>
#include <queue>
using namespace std;
// A Binary Tree Node
struct node {
    struct node *left, *right;
    int key;
};
// Method to find next right of given key k, it returns NULL if k is not present in tree or k is the rightmost node of its level
node* nextRight(node* root, int key)
{
    if (root == NULL)
        return NULL;
    // variable to store the result
    node* res = NULL;
    // queue q to store the nodes of the tree
    queue<node*> q:
    q.push(root);
    while (!q.empty()) {
        // Get the count of the elements in the queue, this is also the count of elements present at the current level
        int n = q.size();
        // loop through the elements of the current level
        for (int i = 0; i < n; i++) {
            // take out the front of the queue
            node* temp = q.front();
            q.pop();
            // if the key is found we check if there is any element next to it and return the answer accordingally
            if (temp->key == key) {
                if (i != n - 1)
                    return q.front();
                else
                    return NULL;
            }
            // while the current level elements are
            // processed we push their children into the queue
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return NULL;
}
node* newNode(int key)
{
    node* temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
void test(node* root, int k)
{
    node* nr = nextRight(root, k);
    if (nr != NULL)
        cout << "Next Right of " << k << " is " << nr->key
             << endl;
    else
        cout << "No next right node found for " << k
             << endl;
}
int main()
{
    node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
 
    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
    return 0;
}
