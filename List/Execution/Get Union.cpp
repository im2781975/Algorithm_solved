// find union and intersection of two unsorted linked lists
#include "bits/stdc++.h"
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void push(struct Node** head_ref, int new_data);
// check if given data is present in a list
bool isPresent(struct Node* head, int data);
//Function to get union of two linked lists head1 and head2 
struct Node* getUnion(struct Node* head1,struct Node* head2)
{
    struct Node* ans = new Node(-1);
    struct Node* head = ans;
    set<int> st;
    while (head1 != NULL) {
        st.insert(head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        st.insert(head2->data);
        head2 = head2->next;
    }
    for (auto it : st) {
        struct Node* t = new Node(it);
        ans->next = t;
        ans = ans->next;
    }
    head = head->next;
    return head;
}
// Function to get intersection of two linked lists head1 and head2 
struct Node* getIntersection(struct Node* head1,struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* t1 = head1;
    // Traverse list1 and search each element of it in list2. If the element is present in list 2, then insert the element to result
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
void push(struct Node** head_ref, int new_data)
{
 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;

    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);
 
    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);
    intersecn = getIntersection(head1, head2);
    unin = getUnion(head1, head2);
    cout << "\n First list is " << endl;
    printList(head1);
    cout << "\n Second list is " << endl;
    printList(head2);
    cout << "\n Intersection list is " << endl;
    printList(intersecn);
    cout << "\n Union list is " << endl;
    printList(unin);
    return 0;
}
