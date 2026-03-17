#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head, int data) {
    Node* newNode = new Node{data, *head};
    *head = newNode;
}
void deleteList(Node** head) {
    Node* curr = *head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    *head = nullptr;
}

void deleteNode(Node** head, int pos) {
    if (!*head) return;
    
    if (pos == 0) {
        Node* temp = *head;
        *head = temp->next;
        delete temp;
        return;
    }
    
    Node* prev = *head;
    for (int i = 0; i < pos - 1 && prev->next; i++)
        prev = prev->next;
    
    if (!prev || !prev->next) return;
    
    Node* toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
}

void print(Node* head) {
    for (; head; head = head->next)
        cout << head->data << " ";
}
void push(Node** head, int data) {
    *head = new Node{data, *head};
}
void deleteAlt(Node *head)  
{  
    if (head == NULL)  
        return;  
    // Initialize prev and node to be deleted
    Node *prev = head;  
    Node *node = head->next;  
  
    while (prev != NULL && node != NULL)  
    {  
        // Change next link of previous node 
        prev->next = node->next;  
        delete(node); 
        // delete the node 
        //Update prev and node 
        prev = prev->next;  
        if (prev != NULL)  
            node = prev->next;  
    }  
}  
// deletes alternate nodes of a list starting with head
void deleteAlt(Node *head)  
{  
    if (head == NULL)  
        return;  
  
    Node *node = head->next;  
    if (node == NULL)  
        return;  
    // Change the next link of head
    head->next = node->next;  
    free(node);  
    //Recursively call for the new next of head
    deleteAlt(head->next);  
}
void deleteAlt(Node* head) {
    if (!head || !head->next) return;
    
    head->next = head->next->next;
    delete head->next;  // Safe - already unlinked
    deleteAlt(head->next);
}
int main() {
    Node* head = nullptr;
    push(&head, 7); push(&head, 1); push(&head, 3);
    push(&head, 2); push(&head, 8);
    
    cout << "Before: "; print(head); cout << '
';
    deleteNode(&head, 4);
    cout << "After:  "; print(head);
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head, int data) {
    *head = new Node{data, *head};
}

void deleteKey(Node** head, int key) {
    if (!*head) return;
    
    // Head case
    if ((*head)->data == key) {
        Node* temp = *head;
        *head = temp->next;
        delete temp;
        return;
    }
    
    // Traverse to find key
    Node* prev = *head;
    while (prev->next && prev->next->data != key)
        prev = prev->next;
    
    if (prev->next) {
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
}

void print(Node* head) {
    for (; head; head = head->next)
        cout << head->data << " ";
    cout << '
';
}

int main() {
    Node* head = nullptr;
    push(&head, 2); push(&head, 5); push(&head, 7);
    push(&head, 8); push(&head, 10);
    
    cout << "Before: "; print(head);
    deleteKey(&head, 7);
    cout << "After:  "; print(head);
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
// Deletes every k-th node and returns head of modified list 
Node *deleteKthNode(struct Node *head, int k) 
{ 
    // If linked list is empty 
    if (head == NULL) 
        return NULL; 
    if (k == 1) 
    { 
       freeList(head); 
       return NULL; 
    } 
    // Initialize ptr and prev before starting  traversal
    struct Node *ptr = head, *prev = NULL; 
    // Traverse list and delete every k-th node 
    int count = 0; 
    while (ptr != NULL) 
    { 
        // increment Node count 
        count++; 
        // check if count is equal to k .  if yes, then delete current Node 
        if (k == count) 
        { 
            // put the next of current Node in  the next of previous Node 
            delete(prev->next); 
            prev->next = ptr->next;
            // set count = 0 to reach further  k-th Node 
            count = 0; 
        } 
        // update prev if count is not 0 
        if (count != 0) 
            prev = ptr; 
        ptr = prev->next; 
    } 
    return head; 
}
Node* deleteKth(Node* head, int k) {
    if (!head || k <= 0) return nullptr;
    if (k == 1) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return nullptr;
    }
    
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr) {
        for (int i = 1; i < k && curr->next; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr->next) break;
        
        prev->next = curr->next->next;
        delete curr->next;
        curr = prev->next;
    }
    return head;
}
void deleteNode(Node* node)
{
    Node* prev;
    if (node == NULL)
        return;
    else {
        Node* temp = node->next;
        node->data = temp->data;
        node->next = temp->next;
        temp = NULL;
    }
}
void print(Node* head) {
    for (; head; head = head->next)
        cout << head->data << " ";
    cout << '
';
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, 
                   new Node{4, new Node{5, new Node{6, 
                   new Node{7, new Node{8, nullptr}}}}}}}}};
    
    cout << "Before (k=3): "; print(head);
    head = deleteKth(head, 3);
    cout << "After:        "; print(head);
}
#include <iostream>
using namespace std;

struct Node {
    int number;
    Node* next;
};

void push(Node** head, int data) {
    *head = new Node{data, *head};
}

void append(Node** head, int data) {
    Node* newNode = new Node{data, nullptr};
    
    if (!*head) {
        *head = newNode;
        return;
    }
    
    Node* last = *head;
    while (last->next) last = last->next;
    last->next = newNode;
}

void deleteN(Node** head, int pos) {
    if (!*head || pos < 0) return;
    
    if (pos == 0) {
        Node* temp = *head;
        *head = temp->next;
        delete temp;
        return;
    }
    
    Node* prev = *head;
    Node* curr = *head;
    
    for (int i = 0; i < pos && curr; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

void printList(Node* head) {
    while (head) {
        cout << "[" << head->number << "] -> ";
        cout << (head->next ? to_string((uintptr_t)head->next) : "nil") << '
';
        head = head->next;
    }
    cout << '
';
}

int main() {
    Node* head = nullptr;
    push(&head, 1); push(&head, 2); push(&head, 3);
    
    cout << "Before:
"; printList(head);
    deleteN(&head, 1);  // Delete position 1 (value 2)
    cout << "After:
";  printList(head);
}
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int number;
    Node* next;
};
//Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end
void append(Node** head_ref, int new_data)
{
    //allocate node
    Node* new_node = new Node();
    // Used in step 5
    Node* last = *head_ref;
    //Put in the data
    new_node->data = new_data;
    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
 
    // If the Linked List is empty,then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
    // Change the next of last node
    last->next = new_node;
    return;
}
void Push(Node** head, int A)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->number = A;
    n->next = *head;
    *head = n;
}
 
void deleteN(Node** head, int position)
{
    Node* temp;
    Node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}
 
void printList(Node* head)
{
    while (head) {
        if (head->next == NULL)
            cout << "[" << head->number << "] "
                 << "[" << head << "]->"
                 << "(nil)" << endl;
        else
            cout << "[" << head->number << "] "
                 << "[" << head << "]->" << head->next
                 << endl;
        head = head->next;
    }
    cout << endl << endl;
}
int main()
{
    Node* list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    Push(&list, 1);
    Push(&list, 2);
    Push(&list, 3);
 
    printList(list);
    // Delete any position from list
    deleteN(&list, 1);
    printList(list);
    return 0;
}
