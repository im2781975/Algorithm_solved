#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};
node *create(int val) {
    return new node(val);
}
void rightview(node *root) {
    if(!root) return;
    queue <node*> q; q.push(root);
    while(!q.empty()) {
        int sz = q.size(); 
        node *last = nullptr;
        while(sz--) {
            node *cur = q.front(); q.pop();
            last = cur;
            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right)
        }
        cout << last -> data << " ";
    }
}
void rightview(node *root, int level = 1, int maxl = 0) {
    static int ml = 0;
    if(!root || level <= ml) return;
    cout << root -> data << " "; ml = level;
    rightview(root -> right, level + 1, maxl);
    rightview(root -> left, level + 1, maxl);
}
// morris traversal
vector <int> rightview(node *root) {
    vector <int> res;
    node *curr = root;
    while(curr) {
        if(!curr -> right){
            res.push_back(curr -> val);
            curr = curr -> left;
        }
        else {
            node *tmp = curr -> right;
            while(tmp -> left && tmp -> left != curr) tmp = tmp -> left;
            if(!tmp -> left) {
                tmp -> left = curr;
                curr = curr -> right;
            }
            else {
                tmp -> left = nullptr;
                res.push_back(curr -> val);
                curr = curr -> left;
            }
        }
    }
    return res;
}
void leftview(node *root) {
    if(!root) return;
    queue <node*> q; q.push(root);
    while(!q.empty()) {
        int sz = q.size(); 
        node *last = nullptr;
        while(sz--) {
            node *cur = q.front(); q.pop();
            if(!last) last = cur;
            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right)
        }
        cout << last -> data << " ";
    }
}
node *buildTree(vector <int> arr, int idx) { /*
    vector <int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx = 0;
    node* root = buildTree(arr, idx);
    levelOrder(root); */
    if(idx >= arr.size() || arr[idx] == -1) {
        idx++; return nullptr;
    }
    node *root = create(arr[idx++]);
    root -> left = buildTree(arr, idx);
    root -> right = buildTree(arr, idx);
    return root;
}
void levelorder(node *root) {
    if(!root) return;
    queue <node*> q; q.push(root);
    while(!q.empty()) {
        node *curr = q.front(); q.pop();
        cout << curr -> data << " ";
        if(curr -> left) q.push(curr -> left);
        if(curr -> right) q.push(curr -> right);
    }
}
void inorder(node *root) {
    if(root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}
void preorder(node *root) {
    if(root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
void postorder(node *root) {
    if(root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}
int mindepth(node *root) {
    if(!root) return 0;
    if(!root -> left && !root -> right) return 1;
    int l = root -> left ? mindepth(root -> left) : INT_MAX;
    int r = root -> right ? mindepth(root -> right) : INT_MAX;
    return min(l, r) + 1;
}
int mindepth(node *root) {
    if(!root) return 0;
    queue <node*> q; q.push(root);
    int depth = 0;
    while(!q.empty()) {
        depth++;
        int sz = q.size();
        while(sz--) {
            node *curr = q.front(); q.pop();
            if(!curr -> left && !curr -> right) return depth;
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            
        }
    }
    return depth;
}
struct qItem {
    node *nd;
    int depth;
};
int minDepth(node* root) {
    if (!root) return 0;
    queue <qItem> q; q.push({root, 1});
    while (!q.empty()) {
        qItem curr = q.front(); q.pop();
       
        if (!curr.nd -> left && !curr.nd -> right) return curr.depth;
        if(curr.nd -> left) q.push({curr.nd -> left, curr.depth + 1});
        if(curr.nd -> right) q.push({curr.nd -> right, curr.depth + 1});
    }
    return 0;

// Iterative function to print all nodes between two given levels in a binary Node
void printnode(node *root, int start, int end) {
    if(root == NULL) return;
    queue <node*> q; q.push(root);
    int level = 0;
    while(!q.empty()) {
        level++; int sz = q.size();
        while(sz != 0) {
            node *curr = q.front(); q.pop();
            if(level >= start && level <= end) cout << curr -> data << " ";
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            sz--;
        }
        if(level >= start && level <= end) cout << endl;
    }
}
void printnode(node *root, int start, int end, vector <vector <int>> res, int level) {
    if(root == NULL) return;
    printnode(root ->left, start, end, res, level + 1);
    if(level >= start && level <= end) 
        res[level - start].push_back(root -> data)
    printnode(root ->right, start, end, res, level + 1);
}

