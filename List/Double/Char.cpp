#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

void insertAtTail(Node*& head, char data) {
    Node* node = new Node(data);
    
    if (!head) {
        head = node;
        return;
    }
    
    Node* tail = head;
    while (tail->next) tail = tail->next;
    
    tail->next = node;
    node->prev = tail;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL
";
}

void rotate(Node*& head, int pos) {
    if (!head || pos == 0) return;
    
    // Find rotation point
    Node* newHead = head;
    for (int i = 0; i < pos && newHead->next; i++) {
        newHead = newHead->next;
    }
    
    // Cut and reconnect
    Node* oldTail = newHead->prev;
    oldTail->next = nullptr;
    newHead->prev = nullptr;
    
    // Find end and connect
    Node* tail = newHead;
    while (tail->next) tail = tail->next;
    tail->next = head;
    head->prev = tail;
    
    head = newHead;
}

int main() {
    Node* head = nullptr;
    string chars = "abcde";
    for (char c : chars) {
        insertAtTail(head, c);
    }
    
    cout << "Before rotation: ";
    display(head);
    
    rotate(head, 2);
    cout << "After rotation (by 2): ";
    display(head);
    
    return 0;
}
