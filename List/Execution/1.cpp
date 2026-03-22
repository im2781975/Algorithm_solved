#include<bits/stdc++.h>
using namespace std;
struct node {
    int data; node *next;
};
void push(Node** head, int data) {
    Node* node = new Node();
    node -> data = data;
    node -> next = *head;
    *head = node;
}
void reverse(node **head) {
    node *curr = *head, *prv = nullptr;
    while(curr) {
        node *tmp = curr -> next;
        curr -> next = prv;
        prv = curr; curr = next;
    }
    *head = prv;
}
// Reverses the linked list in groups of size k
node *reverseK(node *head, int k) {
    if(!head) return nullptr;
    node *curr = head, *prv = nullptr, *tmp = nullptr;
    int cnt = 0;
    while(curr && cnt < k) {
        tmp = curr -> next;
        curr -> next = prv;
        prv = curr; curr = tmp; cnt++;
    }
    if(curr) head -> next = reverseK(curr, k);
    return prv;
}
node *reverse(node *head) {
    if(!head ||!head -> next) return head;
    node *res = reverse(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return res;
}
void reverse(Node** head) {
    if (!*head) return;
    util(*head, nullptr, head);
}
void util(node *curr, node *prv, node **head) {
    node *tmp = curr -> next;
    curr -> next = prv;
    if(!tmp) {
        *head = curr; return;
    }
    util(tmp, curr, head);
}
void reverseKgrp(node *head, int k) {
    node *tmp = head; int cnt = 0;
    while(tmp && cnt < k) {
        tmp = tmp -> next; ++cnt;
    }
    if(cnt < k) return head;
    node *prv = NULL, *curr = head, *last = NULL;
    for(int i = 0; i < k; i++) {
        last = curr -> next;
        curr -> next = prv;
        prv = curr; curr = last;
    }
    head -> next = reverseKgrp(curr, k);
    return prv;
}
node* reverseKGroups(node* head, int k) {
    return process(head, k, true);
}
node *process(node *head, int k, bool rev) {
    if(!head) return NULL;
    node *prv = NULL, *curr = head, *last = NULL;
    int cnt = 1;
    while(curr && cnt <= k) {
        last = curr -> next;
        if(rev) curr -> next = prv;
        prv = curr; curr = last; cnt++;
        if(rev) {
            head -> next = process(curr, k, false); 
            return prv;
        }
        else {
            prv -> next = process(curr, k, true);
            return head;
        }
    }
}
// Reverses the linked list in groups of size k and returns the pointer to the new head node.
node* reverse(node* head, int k) { 
    if (!head || k == 1) 
        return head; 
    Node* dummy = new node(); 
    dummy->data = -1; 
    dummy->next = head; 
    node *prev = dummy, *curr = dummy, *next = dummy; 
    int count = 0; 
    while (curr) { 
        curr = curr->next; 
        count++; 
    } 
    while (next) { 
        curr = prev->next; 
        next = curr->next; 
        int toLoop = count > k ? k : count - 1; 
        for (int i = 1; i < toLoop; i++) { 
            // 4 steps as discussed above 
            curr->next = curr->next->next; 
            curr->next->next = prev->next; 
            prev->next = next; 
            next = curr->next; 
        } 
        // Setting prev to curr 
        prev = curr; 
        // Update count 
        count -= k; 
    } 
    // dummy -> next will be our new head for output linked list
    return dummy->next; 
} 
// Helper: rotate one block of length k by degree d
Node* rotateHelper(Node* head, Node* tail, int d, Node** tailPtr, int len) {
    // Normalize rotation degree
    d = d % len;
    if (d < 0) d += len;
    if (d == 0) {
        *tailPtr = tail;
        return head;
    }

    if (d > 0) {
        // Rotate clockwise by 1 step, then recurse
        Node* newTail = head;
        int pos = 1;
        while (pos < len - 1 && newTail->next->next) {
            newTail = newTail->next;
            pos++;
        }
        tail->next = head;                // connect tail to head
        *tailPtr = newTail;               // new tail of this block
        return rotateHelper(tail, newTail, d - 1, tailPtr, len);
    }

    // Anti‑clockwise: same idea, but we implemented normalized d so this branch is not needed
    return head; // safe fallback
}

// Rotate whole list block‑wise: each block of size k by d positions
Node* rotateByBlocks(Node* head, int k, int d) {
    if (!head || !head->next || d == 0) {
        return head;
    }

    // Step 1: find the last node of the first block (or whole list if <k)
    Node* blockEnd = head;
    int len = 1;
    while (blockEnd->next && len < k) {
        blockEnd = blockEnd->next;
        len++;
    }

    // Step 2: next block starts after this block
    Node* nextHead = blockEnd->next;
    Node* tail = nullptr;                 // will be set by rotateHelper

    // Step 3: rotate this block
    int effectiveD = d % k;
    if (effectiveD < 0) effectiveD += k;

    head = rotateHelper(head, blockEnd, effectiveD, &tail, len);

    // Step 4: recursively rotate the rest and attach
    tail->next = rotateByBlocks(nextHead, k, d);

    return head;
}
// segregates nodes so that even‑valued nodes come first, then odd‑valued nodes
node *divide(node *head) {
    if(!head) return nullptr;
    queue <node*> even, odd, q;
    node *curr = head;
    while(curr) {
        if(curr -> data % 2 == 0) even.push_back(curr);
        else odd.push_back(curr);
        curr = curr -> next;
    }
    node *dummy = new node(-100);
    node *tmp = dummy;
    while(!even.empty()) {
        q.push(even.front()); even.pop();
    }
    while(!odd.empty()) {
        q.push(odd.front()); odd.pop();
    }
    while(!q.empty()) {
        tmp -> next = q.front();
        tmp = tmp -> next; q.pop();
    }
    tmp -> next = nullptr;
    return dummy -> next;
}
void segregateEvenOdd(node **head) {
    node *evenstart = NULL, *evenend = NULL;
    node *oddstart = NULL, *oddend = NULL;
    node *curr = *head;
    while(curr) {
        int val = curr -> data;
        if(val % 2 == 0) {
            if(!evenstart) {
                evenstart = curr; evenend = curr;
            }
            else {
                evenend -> next = curr;
                evenend = evenend -> next;
            }
        }
        else {
            if(!oddstart) {
                oddstart = curr; oddend = oddstart;
            }
            else {
                oddend -> next = curr;
                oddend = oddend -> next;
            }
        }
        curr = curr -> next;
    }
    if(!oddstart || !evenstart) return;
    evenend->next = oddstart; 
    oddend->next = nullptr; 
    *head = evenstart;
}
void segregateEvenOdd(Node** head_ref) {
    if (!*head_ref) return;

    Node* end = *head_ref;
    while (end->next) end = end->next;

    Node* new_end = end;
    Node* curr = *head_ref;
    Node* prev = NULL;

    // Move leading odd nodes to the end
    while (curr != end && (curr->data % 2 != 0)) {
        if (curr == *head_ref) {
            *head_ref = curr->next;
        }
        if (prev) {
            prev->next = curr->next;
        }
        new_end->next = curr;
        new_end = curr;
        curr = curr->next;
        new_end->next = nullptr;
    }

    // Now traverse the rest (from first even) and move odd nodes to end
    while (curr != end && curr != nullptr) {
        if (curr->data % 2 != 0) {
            prev->next = curr->next;
            curr->next = nullptr;
            new_end->next = curr;
            new_end = curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // If last node is odd and not already moved, move it too
    if (curr && curr == end && curr->data % 2 != 0 && prev) {
        prev->next = curr->next;
        curr->next = nullptr;
        new_end->next = curr;
    }
}
// alternatively split a linked list into two halves
void MoveNode(Node** destRef, Node** sourceRef) 
{ 
    // the front source node 
    Node* newNode = *sourceRef; 
    assert(newNode != NULL); 
    // Advance the source pointer
    *sourceRef = newNode->next; 
    // Link the old dest of the new node
    newNode->next = *destRef; 
    //Move dest to point to the new node
    *destRef = newNode; 
} 
void AlternatingSplit(Node* source, Node** aRef, Node** bRef) 
{ 
    ///split the nodes of source to these 'a' and 'b' lists 
    Node* a = NULL; 
    Node* b = NULL; 
    Node* current = source; 
    while (current != NULL) 
    { 
        MoveNode(&a, ¤t);
        // Move a node to list 'a'
        if (current != NULL) 
        { 
            MoveNode(&b, ¤t); 
            // Move a node to list 'b' 
        } 
    } 
    *aRef = a; 
    *bRef = b; 
} 
void AlternatingSplit(Node* source,Node** aRef, Node** bRef) 
{ 
    Node aDummy; 
     
    //points to the last node in 'a'
    Node* aTail = &aDummy; 
    Node bDummy; 
    // points to the last node in 'b' 
    Node* bTail = &bDummy; 
    Node* current = source; 
    aDummy.next = NULL; 
    bDummy.next = NULL; 
    while (current != NULL) 
    { 
        MoveNode(&(aTail->next), ¤t);
        //add at 'a' tail 
        aTail = aTail->next;
        //advance the 'a' tail 
        if (current != NULL) 
        { 
            MoveNode(&(bTail->next), ¤t); 
            bTail = bTail->next; 
        } 
    } 
    *aRef = aDummy.next; 
    *bRef = bDummy.next; 
} 
// subtract smaller valued list from larger valued list and return result as a list
int getLength(Node* Node)
{
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}
 
//padds zeros in front of the Node, with the given diff
Node* paddZeros(Node* sNode, int diff)
{
    if (sNode == NULL)
        return NULL;
 
    Node* zHead = newNode(0);
    diff--;
    Node* temp = zHead;
    while (diff--) {
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zHead;
}
// Subtract LinkedList Helper is a recursive function, move till the last Node,  and subtract the digits and
//create the Node and return the Node. If d1 < d2, we borrow the number from previous digit
Node* subtractLinkedListHelper(Node* l1, Node* l2,bool& borrow)
{
    if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;
 
    Node* previous = subtractLinkedListHelper(
        l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);
 
    int d1 = l1->data;
    int d2 = l2->data;
    int sub = 0;
    // if you have given the value to next digit then reduce the d1 by 1
    if (borrow) {
        d1--;
        borrow = false;
    }
    //If d1 < d2, then borrow the number from previous digit. Add 10 to d1 and set borrow = true; 
    if (d1 < d2) {
        borrow = true;
        d1 = d1 + 10;
    }
    // subtract the digits
    sub = d1 - d2;
    // Create a Node with sub value 
    Node* current = newNode(sub);
    //Set the Next pointer as Previous
    current->next = previous;
    return current;
}
Node* subtractLinkedList(Node* l1, Node* l2)
{
    // Base Case.
    if (l1 == NULL && l2 == NULL)
        return NULL;
    // In either of the case, get the lengths of both Linked list.
    int len1 = getLength(l1);
    int len2 = getLength(l2);
 
    Node *lNode = NULL, *sNode = NULL;
    Node* temp1 = l1;
    Node* temp2 = l2;
    // If lengths differ, calculate the smaller Node and padd zeros for smaller Node and ensure both
    // larger Node and smaller Node has equal length.
    if (len1 != len2) {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;
        sNode = paddZeros(sNode, abs(len1 - len2));
    }
    else {
        // If both list lengths are equal, then calculate the larger and smaller list. If 5-6-7 & 5-6-8
        // are linked list, then walk through linked list at last Node as 7 < 8, larger Node is 5-6-8 and smaller Node is 5-6-7.
        while (l1 && l2) {
            if (l1->data != l2->data) {
                lNode = l1->data > l2->data ? temp1 : temp2;
                sNode = l1->data > l2->data ? temp2 : temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    // If both lNode and sNode still have NULL value, then this means that the  value of both of the given
    // linked lists is the same and hence we can directly return a node with value 0.
    if (lNode == NULL && sNode == NULL) {
        return newNode(0);
    }
    // After calculating larger and smaller Node, call subtractLinkedListHelper which returns the subtracted linked list.
    bool borrow = false;
    return subtractLinkedListHelper(lNode, sNode, borrow);
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
