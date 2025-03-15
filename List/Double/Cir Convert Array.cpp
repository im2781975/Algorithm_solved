#include<bits/stdc++.h>
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
