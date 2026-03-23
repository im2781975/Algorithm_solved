// C++ program to demonstrate insert operation in binary
// search tree.
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int key;
    int c = 0;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->c = 1;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to insert a new node with given key in
// BST
struct node* insert(struct node* node, int key, int& ma)
{
    // If the tree is empty, return a new node
    if (node == NULL) {
        if (ma == 0)
            ma = 1;
 
        return newNode(key);
    }
 
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key, ma);
    else if (key > node->key)
        node->right = insert(node->right, key, ma);
    else
        node->c++;
 
    // find the max count
    ma = max(ma, node->c);
 
    // return the (unchanged) node pointer
    return node;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node* root, int s)
{
    if (root != NULL) {
        inorder(root->left, s);
 
        if (root->c > (s / 2))
            printf("%d \n", root->key);
 
        inorder(root->right, s);
    }
}
// Driver Code
int main()
{
    int a[] = { 1, 3, 3, 3, 2 };
    int size = (sizeof(a)) / sizeof(a[0]);
 
    struct node* root = NULL;
    int ma = 0;
 
    for (int i = 0; i < size; i++) {
        root = insert(root, a[i], ma);
    }
 
    // Function call
    if (ma > (size / 2))
        inorder(root, size);
    else
        cout << "No majority element\n";
    return 0;
}
// implement k-th order statistics
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
// Constructs a segment tree and stores tree[]
void buildTree(int treeIndex, int l, int r, 
    vector<pair<int, int> > &a, vector<int> tree[])
{
    //l => start of range, r => ending of a range
    //treeIndex => index in the Segment Tree/Merge  Sort Tree
    if (l == r) {
        tree[treeIndex].push_back(a[l].second);
        return;
    }
    int mid = (l + r) / 2;
    
    //building right subtree 
    buildTree(2 * treeIndex, l, mid, a, tree);
 
    // building left subtree
    buildTree(2 * treeIndex + 1, mid + 1, r, a, tree);
    
    // merging left and right child in sorted order 
    merge(tree[2 * treeIndex].begin(), 
        tree[2 * treeIndex].end(),
        tree[2 * treeIndex + 1].begin(), 
        tree[2 * treeIndex + 1].end(),
        back_inserter(tree[treeIndex]));
}
// Returns the Kth smallest number in query range
int queryRec(int segmentStart, int segmentEnd, int queryStart, int queryEnd, int treeIndex,
    int K, vector<int> tree[])
{
        //segmentStart => start of a Segment,segmentEnd => ending of a Segment
       // queryStart => start of a query range,queryEnd => ending of a query range
        //treeIndex => index in the Segment Tree/Merge Sort Tree, K => kth smallest number to find 
    if (segmentStart == segmentEnd) 
        return tree[treeIndex][0];
    int mid = (segmentStart + segmentEnd) / 2;
    
    // finds the last index in the segment which is <= queryEnd
    int last_in_query_range = 
            (upper_bound(tree[2 * treeIndex].begin(),tree[2 * treeIndex].end(), queryEnd)- tree[2 * treeIndex].begin());
 
    // finds the first index in the segment which is >= queryStart
    int first_in_query_range = (lower_bound(tree[2 * treeIndex].begin(), tree[2 * treeIndex].end(),queryStart) - tree[2 * treeIndex].begin());
 
    int M = last_in_query_range - first_in_query_range;
    if (M >= K) {
        // Kth smallest is in left subtree,so recursively call left subtree for Kth smallest number
        return queryRec(segmentStart, mid, queryStart,queryEnd, 2 * treeIndex, K, tree);
    }
    else {
        // Kth smallest is in right subtree, so recursively call right subtree for the (K-M)th smallest number
        return queryRec(mid + 1, segmentEnd, queryStart,
            queryEnd, 2 * treeIndex + 1, K - M, tree);
    }
}
// A wrapper over query()
int query(int queryStart, int queryEnd, int K, int n,
        vector<pair<int, int> > &a, vector<int> tree[])
{
    return queryRec(0, n - 1, queryStart - 1, queryEnd - 1, 1, K, tree);
}
int main()
{
    int arr[] = { 3, 2, 5, 1, 8, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);
    // vector of pairs of form {element, index}
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end());
    // Construct segment tree in tree[]
    vector<int> tree[MAX];
    buildTree(1, 0, n - 1, v, tree);
 
    // Answer queries kSmallestIndex hold the index of the kth smallest number
    int kSmallestIndex = query(2, 5, 2, n, v, tree);
    cout << arr[kSmallestIndex] << endl;
 
    kSmallestIndex = query(1, 6, 4, n, v, tree);
    cout << arr[kSmallestIndex] << endl;
    return 0;
}
