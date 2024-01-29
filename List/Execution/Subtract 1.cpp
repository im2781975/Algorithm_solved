// subtract smaller valued list from larger valued list and return result as a list using 10's complement.
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
// A utility which creates Node.
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int getLength(Node* Node)
{
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}
// A utility function to reverse the list
Node* reverse(Node* head)
{
    Node *prev = NULL, *next;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
 
//Subtract LinkedList Helper is an iterative function,Reverse the linked list,
//and perform addition of linked list after converting L2 to 10's complement 
Node* subtractLinkedListHelper(Node* l1, Node* l2)
{
    // reverse both linked list
    l1 = reverse(l1);
    l2 = reverse(l2);
 
    // Initialize carry = 1 for making 10s complement using 9's complement
    // 10's complement = 9's complement + 1
    int carry = 1, sum;
    Node *res = NULL, *temp;
    // Repeat while any of list is not empty
    while (l1 != NULL || l2 != NULL) {
        sum = carry;
        // If L1 is not empty
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        // If L2 is not empty
        if (l2) {
            sum += (9 - l2->data);
            l2 = l2->next;
        }
        // Otherwise consider l2->data as 0 (zero)
        else {
            sum += 9;
        }
        carry = sum / 10;
        sum = sum % 10;
        // If result has no digit yet
        if (res == NULL) {
            res = newNode(sum);
            temp = res;
        }
        // otherwise append the data to result linked list
        else {
            temp->next = newNode(sum);
            temp = temp->next;
        }
    }
    // Reverse the resulting linked list
    res = reverse(res);
    // remove initial zeroes
    while (res && res->data == 0)
        res = res->next;
 
    return res;
}
// This function subtracts two linked lists and returns the linked list which shall have the subtracted result.
Node* subtractLinkedList(Node* l1, Node* l2)
{
    // Base Case.
    if (l1 == NULL && l2 == NULL)
        return NULL;
 
    // Remove initial zeroes
    while (l1 != NULL && l1->data == 0)
        l1 = l1->next;
    while (l2 != NULL && l2->data == 0)
        l2 = l2->next;
 
    // determine which one is bigger and which is smaller and store larger in l1 and smaller in l2
    // Get length of both the linked list
    int len1 = getLength(l1);
    int len2 = getLength(l2);
 
    // If length of both linked list is same then determine which one is bigger using the data
    if (len1 == len2) {
        Node *a = l1, *b = l2;
        while (a != NULL && b != NULL
               && a->data == b->data) {
            a = a->next;
            b = b->next;
        }
        // if b's value is greater than a's value then l2 is larger number than l1
        if (a != NULL && b != NULL && a->data < b->data) {
            swap(l1, l2);
        }
    }
    // If length(l2) is greater than length(l1) then l2 is larger and l1 is smaller
    else if (len2 > len1) {
        swap(l1, l2);
    }
    // Get subtraction result using 10's complement
    Node* res = subtractLinkedListHelper(l1, l2);
    // If res is NULL, then it means both numbers are same and answer is zero
    if (res == NULL) {
        return newNode(0);
    }
    return res;
}
void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
int main()
{
    Node* head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(0);
 
    Node* head2 = newNode(1);
 
    Node* result = subtractLinkedList(head1, head2);
    printList(result);
 
    return 0;
}
