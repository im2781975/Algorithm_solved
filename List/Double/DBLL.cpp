#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val = 0) : data(val), next(nullptr), prev(nullptr) {}
};
Node* push(Node*& head, int data) {
    Node* new_node = new Node(data);
    new_node->next = head;
    if (head) head->prev = new_node;
    head = new_node;
    return head;
}
Node* reverseGroups(Node* head, int k) {
    if (!head) return head;
    
    Node* result = nullptr;
    Node* prevGroupTail = nullptr;
    Node* curr = head;
    
    while (curr) {
        // Reverse k nodes
        Node* groupHead = nullptr;
        Node* tail = curr;
        int count = 0;
        
        // Reverse current group
        while (curr && count < k) {
            Node* next = curr->next;
            curr->next = groupHead;
            curr->prev = next;
            groupHead = curr;
            curr = next;
            count++;
        }
        
        // Connect to previous group
        if (!result) {
            result = groupHead;
            result->prev = nullptr;
        } else {
            prevGroupTail->next = groupHead;
            groupHead->prev = prevGroupTail;
        }
        
        prevGroupTail = tail;
    }
    
    return result;
}
Node* reverseGroup(Node* head, int k) {
    Node* curr = head;
    Node* newHead = nullptr;
    int count = 0;
    
    // Reverse first k nodes by pushing to new list
    while (curr && count < k) {
        Node* next = curr->next;
        push(newHead, curr->data);  // Simplified push
        curr = next;
        count++;
    }
    
    // Link to next group
    if (curr) {
        head->next = reverseGroup(curr, k);
        if (head->next) head->next->prev = head;
    }
    
    newHead->prev = nullptr;
    return newHead;
}
Node* reverseGroups(Node* head, int k) {
    if (!head) return nullptr;
    
    // Reverse first k nodes
    Node* newHead = nullptr;
    Node* curr = head;
    int count = 0;
    
    while (curr && count < k) {
        Node* next = curr->next;
        curr->next = newHead;
        curr->prev = next;
        newHead = curr;
        curr = next;
        count++;
    }
    
    // Connect to rest
    if (curr) {
        Node* restHead = reverseGroups(curr, k);
        newHead->next = restHead;
        if (restHead) restHead->prev = newHead;
    }
    
    return newHead;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* insertAtEnd(Node* head, int data) {
    Node* node = new Node(data);
    
    if (!head) return node;
    
    Node* tail = head;
    while (tail->next) tail = tail->next;
    
    tail->next = node;
    node->prev = tail;
    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void push(Node*& head, int data) {
    Node* node = new Node(data);
    node->next = head;
    if (head) head->prev = node;
    head = node;
}

void reverse(Node*& head) {
    Node* curr = head;
    while (curr) {
        // Swap next and prev pointers
        swap(curr->next, curr->prev);
        // Move to next node (which is now prev)
        curr = curr->prev;
    }
    // Update head to last node
    if (head) head = head->prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
class DoublyLinkedList {
private:
    Node* head;
    
public:
    DoublyLinkedList() : head(nullptr) {}
    
    // 1. Insert at END (append)
    void append(int new_data) {
        Node* new_node = new Node(new_data);
        
        // Empty list
        if (!head) {
            head = new_node;
            return;
        }
        
        // Traverse to last node
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        
        // Link new node
        last->next = new_node;
        new_node->prev = last;
    }
    
    // 2. Insert at FRONT (push)
    void push(int new_data) {
        Node* new_node = new Node(new_data);
        
        // Link new node to current head
        new_node->next = head;
        
        // Update previous pointer if head exists
        if (head) {
            head->prev = new_node;
        }
        
        // Update head
        head = new_node;
    }
void reverse() {
        Node *curr = head, *prev = nullptr, *next = nullptr;
        
        while (curr) {
            // Swap next and prev pointers
            next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            
            // Move prev to current, current to next
            prev = curr;
            curr = next;
        }
        // Update head to last node
        head = prev;
    }
void reverse()
    {
        stack<int> st;
        Node* temp = head;
        while (temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }
        // added all the elements sequence wise in the st
        temp = head;
        while (temp != NULL) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        // popped all the elements and the added in the linked list, which are in the reversed order
    }
    // 3. Insert AFTER given node
    void insertAfter(Node* prev_node, int new_data) {
        if (!prev_node) {
            cout << "Previous node cannot be NULL
";
            return;
        }
        
        Node* new_node = new Node(new_data);
        
        // Link new node between prev_node and prev_node->next
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        new_node->prev = prev_node;
        
        // Update next node's prev pointer
        if (new_node->next) {
            new_node->next->prev = new_node;
        }
    }
    
    // 4. Insert BEFORE given node  
    void insertBefore(Node* next_node, int new_data) {
        if (!next_node) {
            cout << "Next node cannot be NULL
";
            return;
        }
        
        Node* new_node = new Node(new_data);
        
        // Link new node between next_node->prev and next_node
        new_node->prev = next_node->prev;
        next_node->prev = new_node;
        new_node->next = next_node;
        
        // Update previous node's next pointer
        if (new_node->prev) {
            new_node->prev->next = new_node;
        } else {
            // If inserting before head
            head = new_node;
        }
    }
    
    // Display list (forward)
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Get head for insertAfter/insertBefore
    Node* getHead() { return head; }
    
    // Destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Test the implementation
int main() {
    DoublyLinkedList dll;
    
    // Basic operations
    dll.push(10);           // 10
    dll.append(20);         // 10 <-> 20
    dll.append(30);         // 10 <-> 20 <-> 30
    
    Node* node20 = dll.getHead()->next;  // Node with 20
    dll.insertAfter(node20, 25);         // 10 <-> 20 <-> 25 <-> 30
    
    dll.insertBefore(node20, 15);        // 10 <-> 15 <-> 20 <-> 25 <-> 30
    
    cout << "Final list: ";
    dll.display();
    
    return 0;
}
struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class DLL {
    Node* head = nullptr;
    
public:
    void push(int x) {           // Insert front
        Node* n = new Node{x};
        n->next = head; if (head) head->prev = n; head = n;
    }
    
    void append(int x) {         // Insert end
        Node* n = new Node{x};
        if (!head) return push(x);
        for (Node* t = head; t->next; t = t->next);
        t->next = n; n->prev = t;
    }
    
    void insertAfter(Node* p, int x) {
        if (!p) return;
        Node* n = new Node{x};
        n->next = p->next; p->next = n; n->prev = p;
        if (n->next) n->next->prev = n;
    }
    
    void insertBefore(Node* n, int x) {
        if (!n) return;
        Node* p = new Node{x};
        p->prev = n->prev; n->prev = p; p->next = n;
        if (p->prev) p->prev->next = p; else head = p;
    }
void sortedInsert(int val) {
    Node* n = new Node{val};
    
    // Find insertion point with two pointers
    Node *prev = nullptr, *curr = head;
    while (curr && curr->data < val) {
        prev = curr;
        curr = curr->next;
    }
    
    // Insert between prev and curr
    n->prev = prev;
    n->next = curr;
    
    if (prev) prev->next = n;
    else head = n;        // Insert at front
    
    if (curr) curr->prev = n;
}
    
    
    void print() {
        for (Node* h = head; h; h = h->next) cout << h->data << " ";
        cout << endl;
    }
};

void reverse(Node** head_ref) {
    Node* current = *head_ref;
    
    // Swap prev/next pointers for all nodes
    while (current) {
        // Swap pointers
        std::swap(current->prev, current->next);
        // Move to next node (which is now in prev)
        current = current->prev;
    }
    
    // Update head to last node (now first after reversal)
    if (*head_ref) {
        *head_ref = (*head_ref)->prev;
    }
}

void printList(Node* node) {
    while (node) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
