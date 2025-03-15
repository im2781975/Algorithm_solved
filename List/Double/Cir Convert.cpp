#include<bits/stdc++.h>
//convert the array in circular tree
using namespace std;
struct node{
    int data;
    struct node *nxt;
    struct node *prv;
};
struct node *createNode(){
    return ((struct node*) malloc(sizeof(struct node)));
}
void createList(int arr[], int n, struct node **start){
    struct node *newnode, *tmp;
    for(int i = 0; i < n; i++){
        newnode = createNode();
        newnode -> data = arr[i];
        if(i == 0){
            *start = newnode;
            newnode -> prv = *start;
            newnode -> nxt = *start;
        }
        else{
            tmp = (*start) -> prv;
            tmp -> nxt = newnode
            newnode -> nxt = *start;
            newnode -> prv = tmp;
            tmp = *start;
            tmp -> prv = newnode;
        }
    }
}
int display(struct node *tmp){
    struct node *tp = tmp;
    if(tmp == NULL)
        return 0;
    else{
        while(tmp -> nxt != t){
            cout << tmp -> data << " ";
            tmp = tmp -> nxt;
        }
        cout << tmp -> data;
        return 1;
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node *start = NULL;
    createList(arr, n, &start);
    display(start);
}
//convert a Binary Tree to a Circular Doubly Linked List 
using namespace std;
struct node{
    struct node *left, *right;
    int data;
};
node *create(int data){
    node *tmp = new node();
    tmp -> data = data;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}
node *concat(node *leftList, node *rightList){
    if(leftList == NULL) return rightList;
    if(rightList == NULL) return leftList;
    node *leftLast = leftList -> left;
    node *rightLast = rightList -> right;
   //Connect the last node of Left List with the first Node of the right List 
    leftLast -> right = rightList; 
    rightList -> left = leftLast; 
    // Left of first node points to the last node in the list 
    leftList -> left = rightLast; 
    // Right of last node refers to the first node of the List 
    rightLast -> right = leftList; 
    return leftList; 
}
// Function converts a tree to a circular Linked List  and then returns the head of the Linked List 
node *toCirList(node *root){
    if(root == NULL)
        return NULL;
    node *left = toCirList(root -> left);
    node *right = toCirList(root -> right);
    // Make a circular linked list of single node (or root). To do so, make the right and 
    // left pointers of this node point to itself 
    root->left = root->right = root; 
    // Step 1 (concatenate the left list with the list with single node, i.e., current node) 
    // Step 2 (concatenate the returned list with the right List) 
    return concat(concat(left, root), right); 
}
void disp(node *head){
    node *iter = head;
    do{
        cout << iter -> data << " ";
        iter = iter -> right;
    }while(head != iter);
    cout << "\n";
}
int main(){
    node *root = create(10);
    root -> left = create(12); 
    root -> right = create(15); 
    root -> left -> left = create(25); 
    root -> left -> right = create(30); 
    root -> right -> left = create(36); 
    node *head = toCirList(root);
    disp(head);
}
