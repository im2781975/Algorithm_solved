#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularDoublyLinkedList() : head(nullptr) {}
    
    // Destructor
    ~CircularDoublyLinkedList() {
        clear();
    }
    
    // Create list from array
    void createList(int arr[], int n) {
        clear();
        if (n <= 0) return;
        
        head = new Node(arr[0]);
        head->next = head;
        head->prev = head;
        
        Node* tail = head;
        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(arr[i]);
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }
    
    // Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    
    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    
    // Insert after specific value
    bool insertAfter(int key, int val) {
        if (!head) return false;
        
        Node* curr = head;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next->prev = newNode;
                curr->next = newNode;
                return true;
            }
            curr = curr->next;
        } while (curr != head);
        return false;
    }
    
    // Insert before specific value
    bool insertBefore(int key, int val) {
        if (!head) return false;
        
        Node* curr = head;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr;
                newNode->prev = curr->prev;
                curr->prev->next = newNode;
                curr->prev = newNode;
                
                if (curr == head) head = newNode;
                return true;
            }
            curr = curr->next;
        } while (curr != head);
        return false;
    }
    
    // Delete node with specific value
    bool deleteNode(int val) {
        if (!head) return false;
        
        Node* curr = head;
        do {
            if (curr->data == val) {
                if (curr->next == curr) {
                    delete head;
                    head = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    if (curr == head) head = head->next;
                }
                delete curr;
                return true;
            }
            curr = curr->next;
        } while (curr != head);
        return false;
    }
    
    // Delete front node
    void deleteFront() {
        if (!head || head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
    }
    
    // Delete end node
    void deleteEnd() {
        if (!head || head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }
    
    // Search for value
    bool search(int val) {
        if (!head) return false;
        
        Node* curr = head;
        do {
            if (curr->data == val) return true;
            curr = curr->next;
        } while (curr != head);
        return false;
    }
    
    // Reverse the list
    void reverse() {
        if (!head || head->next == head) return;
        
        Node* curr = head;
        do {
            swap(curr->next, curr->prev);
            curr = curr->prev;
        } while (curr != head);
        
        head = head->prev;
    }
    
    // Display list
    void display() {
        if (!head) {
            cout << "List is empty
";
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    
    // Display in reverse order
    void displayReverse() {
        if (!head) {
            cout << "List is empty
";
            return;
        }
        
        Node* temp = head->prev;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
    
    // Get size of list
    int size() {
        if (!head) return 0;
        
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
    
    // Clear entire list
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = temp->prev;
                temp->prev->next = head;
            }
            delete temp;
        }
    }
    
    // Check if empty
    bool isEmpty() {
        return head == nullptr;
    }
bool insertAtPosition(int pos, int val) {
    int n = size();
    if (pos < 1 || pos > n + 1) return false;
    
    if (pos == 1) {
        insertFront(val);
        return true;
    }
    
    Node* curr = head;
    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }
    Node* newNode = new Node(val);
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
    return true;
}
Node* getNodeAt(int pos) {
    if (pos < 1 || pos > size()) return nullptr;
    Node* curr = head;
    for (int i = 1; i < pos; i++) {
        curr = curr->next;
    }
    return curr;
}
};

// Test the implementation
int main() {
    CircularDoublyLinkedList list;
    
    // Create list: 10 20 30 40
    int arr[] = {10, 20, 30, 40};
    list.createList(arr, 4);
    cout << "Original list: ";
    list.display();
    
    // Insert operations
    list.insertFront(5);
    cout << "After insertFront(5): ";
    list.display();
    
    list.insertEnd(50);
    cout << "After insertEnd(50): ";
    list.display();
    
    list.insertAfter(20, 25);
    cout << "After insertAfter(20,25): ";
    list.display();
    
    // Delete operations
    list.deleteNode(30);
    cout << "After deleteNode(30): ";
    list.display();
    
    // Size and search
    cout << "Size: " << list.size() << endl;
    cout << "Search 25: " << (list.search(25) ? "Found" : "Not found") << endl;
    
    // Reverse
    list.reverse();
    cout << "After reverse: ";
    list.display();
    
    list.displayReverse();
    
    return 0;
}
