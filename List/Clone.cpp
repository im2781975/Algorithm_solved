#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* arbit;
    Node(int x) : val(x), next(nullptr), arbit(nullptr) {}
};

// Clone linked list with random pointers
Node* clone(Node* head) {
    if (!head) return nullptr;
    
    unordered_map<Node*, Node*> mp;
    
    // Create copy nodes and map them
    Node* orig = head, *copy = new Node(head->val);
    mp[head] = copy;
    
    while (orig->next) {
        copy->next = new Node(orig->next->val);
        orig = orig->next;
        copy = copy->next;
        mp[orig] = copy;
    }
    
    // Fix arbitrary pointers
    orig = head, copy = mp[head];
    while (orig) {
        copy->arbit = mp[orig->arbit];
        orig = orig->next;
        copy = copy->next;
    }
    
    return mp[head];
}

void print(Node* head) {
    while (head) {
        cout << head->val << "(" << head->arbit->val << ") ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Set arbitrary pointers
    head->arbit = head->next->next;           // 1→3
    head->next->arbit = head;                 // 2→1
    head->next->next->arbit = head->next->next->next->next;  // 3→5
    head->next->next->next->arbit = head->next->next;        // 4→3
    head->next->next->next->next->arbit = head->next;        // 5→2
    
    cout << "Original: "; print(head);
    cout << "Cloned:   "; print(clone(head));
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next, *random;
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
};

Node* clone(Node* head) {
    if (!head) return nullptr;
    
    // 1. Interleave: orig->copy->orig->copy...
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    
    // 2. Fix copy random pointers
    curr = head;
    while (curr) {
        if (curr->random) curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    
    // 3. Extract copies
    Node* cloneHead = head->next;
    curr = head;
    Node* copyCurr = cloneHead;
    
    while (curr->next) {
        curr->next = curr->next->next;
        copyCurr->next = copyCurr->next ? copyCurr->next->next : nullptr;
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    
    return cloneHead;
}

void print(Node* head) {
    while (head) {
        cout << head->data << "(" << head->random->data << ") ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2); head->next->next = new Node(3);
    head->next->next->next = new Node(4); head->next->next->next->next = new Node(5);
    
    head->random = head->next->next;           // 1→3
    head->next->random = head;                 // 2→1  
    head->next->next->random = head->next->next->next->next;  // 3→5
    head->next->next->next->random = head->next->next;        // 4→3
    head->next->next->next->next->random = head->next;        // 5→2
    
    cout << "Original: "; print(head);
    cout << "Clone:    "; print(clone(head));
}
