#include<iostream>
#include<climits>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
};
node *create(int x){
    node *newnode = new node();
    newnode->data = x;
    newnode->nxt = NULL;
    return newnode;
}
bool IsEmpty(node *root){
    return(root == NULL);
}
void push(node**root, int data){
    node *newnode = create(data);
    newnode->nxt = *root;
    *root = newnode;
    cout << data << " ";
}
int pop(node **root){
    if(IsEmpty(*root))
        return INT_MIN;
    node *tmp = *root;
    (*root) = (*root)->nxt;
    int x = tmp->data;
    free(tmp);
    return x;
}
int peek(node *root){
    if(IsEmpty(root))
        return INT_MIN;
    return root->data;
};
int main(){
    node *root = NULL;
    for(int i = 10; i <= 100; i+= 10)
        push(&root, i);
    cout << "\nElements are: ";
    while(!IsEmpty(root)){
        cout << peek(root) << " ";
        pop(&root);
    }
}
