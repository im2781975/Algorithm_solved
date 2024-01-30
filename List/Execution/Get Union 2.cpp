#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
 
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "None";
}
Node* getUnion(Node* ll1, Node* ll2) {
    Node* tail = NULL;
    Node* head = NULL;
    while (ll1 != NULL || ll2 != NULL) {
        if (ll1 == NULL) {
            if (tail == NULL) {
                tail = new Node(ll2->data);
                head = tail;
            } else {
                tail->next = new Node(ll2->data);
                tail = tail->next;
            }
            ll2 = ll2->next;
        } else if (ll2 == NULL) {
            if (tail == NULL) {
                tail = new Node(ll1->data);
                head = tail;
            } else {
                tail->next = new Node(ll1->data);
                tail = tail->next;
            }
            ll1 = ll1->next;
        } else {
            if (ll1->data < ll2->data) {
                if (tail == NULL) {
                    tail = new Node(ll1->data);
                    head = tail;
                } else {
                    tail->next = new Node(ll1->data);
                    tail = tail->next;
                }
                ll1 = ll1->next;
            } else if (ll1->data > ll2->data) {
                if (tail == NULL) {
                    tail = new Node(ll2->data);
                    head = tail;
                } else {
                    tail->next = new Node(ll2->data);
                    tail = tail->next;
                }
                ll2 = ll2->next;
            } else {
                if (tail == NULL) {
                    tail = new Node(ll1->data);
                    head = tail;
                } else {
                    tail->next = new Node(ll1->data);
                    tail = tail->next;
                }
                ll1 = ll1->next;
                ll2 = ll2->next;
            }
        }
    }
    return head;
}
int main() {
    // create first linked list
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);
    head1->next->next->next->next = new Node(50);
    head1->next->next->next->next->next = new Node(60);
    head1->next->next->next->next->next->next = new Node(70);
 
    // create second linked list
    Node* head2 = new Node(10);
    head2->next = new Node(30);
    head2->next->next = new Node(50);
    head2->next->next->next = new Node(80);
    head2->next->next->next->next = new Node(90);
 
    Node* head = getUnion(head1, head2);
    printLinkedList(head);
    cout << endl;
 
    return 0;
}
