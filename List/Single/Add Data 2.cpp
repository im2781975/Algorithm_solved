#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
Node* newNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
///insert a node at the beginning
void push(Node** head_ref, int new_data)
{
    // allocate node
    Node* new_node = newNode(new_data);
    // link the old list of the new node
    new_node->next = (*head_ref);
    // move the head to point to the new node
    (*head_ref) = new_node;
}
void printList(Node* n)
{
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
// function working on addition.
Node* addTwoLists(Node*first){
    int num1=0;
    // get the number.
    while(first->next!=NULL){
        num1 +=first->data;
        num1*=10;
        first=first->next;
    }
    num1+=first->data;
   // add one to it.
    int num2=num1+1;
    Node* temp=NULL;
    //Node* result=temp;
    // made the linked list form it
    while(num2!=0){
        int last=num2%10;
        push(&temp,last);
        num2=num2/10;
    }
    return temp;
}
int main() {
    Node* first = NULL;
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    Node* ans = addTwoLists(first);
    cout << "Sum is of first : ";
    printList(ans);
    Node* second=NULL;
    push(&second, 9);
    push(&second, 9);
    push(&second, 9);
    push(&second, 1);
    cout << "Sum is of second : ";
    Node* res=addTwoLists(second);
    printList(res);
    return 0;
}
