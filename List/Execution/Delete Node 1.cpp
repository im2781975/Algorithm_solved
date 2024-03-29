#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
     
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class LLUtil {
public:
    // function creates a linked list from a given array and returns head
    Node* createLL(int arr[], int n) {
        Node* head = new Node(arr[0]);
        Node* temp = head;
        Node* newNode = nullptr;
        for(int i = 1; i < n; i++) {
            newNode = new Node(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
    // This function prints the given linked list
    void printLL(Node* head) {
        while(head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};
// This function deletes nodes on the right side of the linked list
Node* deleteNodesOnRightSide(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* nextNode = deleteNodesOnRightSide(head->next);
    if(nextNode->data > head->data) {
        return nextNode;
    }
    head->next = nextNode;
    return head;
}
int main() {
    int arr[] = {12, 15, 10, 11, 5, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
     
    LLUtil llu;
    Node* head = llu.createLL(arr, n);
    cout << "Given Linked List" << endl;
    llu.printLL(head);
    head = deleteNodesOnRightSide(head);
     
    cout << "Modified Linked List" << endl;
    llu.printLL(head);
    return 0;
}
