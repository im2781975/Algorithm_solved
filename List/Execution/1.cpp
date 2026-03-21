#include<bits/stdc++.h>
using namespace std;
struct node {
    int data; node *next;
};
void push(node **head, int val) {
    node *newnode = new node();
    newnode -> data = val;
    newnode -> next = *head;
    *head = newnode;
}
bool areIdentical(node *a, node *b) {
    if(!a && !b) return false;
    if(a && b) return a -> data == b -> data && areIdentical(a -> next, b -> next);
    return false;
}
bool areIdentical(node *a, node *b) {
    while(a && b) {
        if(a -> data != b -> data) return false;
        a = a -> next; b = b -> next;
    }
    return (!a && !b);
}
bool iscircular(node *head) {
    if(!head) return true;
    node *tmp = head -> next;
    while(tmp != NULL && tmp != head) tmp = tmp -> next;
    return (tmp == head);
}
bool issublist(node *list, node *sub) {
    if(!sub) return true;
    if(!list) return false;
    if(list -> data == sub -> data) {
        if(issublist(list -> next, sub -> next)) return true;
    }
    return issublist(list -> next, sub);
}
bool Ispalindrome(node *head) {
    node *curr = head;
    stack <int> st;
    while(curr) {
        st.push(curr -> data); curr = curr -> next;
    }
    curr = head;
    while(curr) {
        if(curr -> data != st.top()) return false;
        st.pop();
    }
    return true;
}
//make middle node as head of  linked list
void makemiddleheap(node **head) {
    if(!*head) return;
    node *slow = *head, *fast = *head, *prv = nullptr;
    while(fast && fast -> next) {
        prv = slow; slow = slow -> next;
        fast = fast -> next -> next;
    }
    prv -> next = slow -> next;
    slow -> next = *head;
    *head = slow;
}
// merge two sorted linked lists
void mergelist(node *a, node *&b) {
    while(a && b) {
        if(a -> data > b -> data) {
            swap(a -> data, b -> data);
            if(b -> data && b -> data > b -> next -> data) {
                node *tmp = b -> next;
                b -> next = tmp -> next;
                tmp -> next = b; b = tmp;
            }
        }
        a = a -> next
    }
}
// arrange linked list in zigzag fashion
void zigzag(node *head) {
    bool greater = false;
    node *curr = head;
    while(curr -> next) {
        if(greater) {
            if(curr -> data > curr -> next -> data) swap(curr -> data, curr -> next -> data);
        }
        else {
            if(curr -> data < curr -> next -> data) swap(curr -> data, curr -> next -> data);
        }
        greater = !greater;
    }
}
node* zigzag(node* head, bool flag)
{
    if (!head || !head->next)
        return head;
    if (flag == 1) {
        if (head->data > head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
    else {
        if (head->data < head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
}
node *zigzag(node *head, bool flag) {
    if(!head || !head -> next) return head;
    if(flag) {
        if(head -> data > head -> next -> data) swap(head -> data, head -> next -> data);
        return zigzag(head -> next, !flag);
    }
    else {
        if(head -> data < head -> next -> data) swap(head -> data, head -> next -> data);
        return zigzag(head -> next, !flag);
    }
}
struct node {
    char data; node* next;
};
bool Ispalindrome(node **left, node *right) {
    if(!right) return true;
    if(!(Ispalindrome(left, right -> next))) return false;
    bool match = right -> data == (*left) -> data;
    (*left) = (*left) -> next;
    return match;
}
bool palindrome(node *head) {
    return Ispalindrome(&head, head);
}
void push(Node** head, char data) {
    *head = new Node{data, *head};
}
void reverse(node **head) {
    node *prv = nullptr, *curr = *head;
    while(curr) {
        *head = curr -> next;
        curr -> next = prv;
        prv = curr; curr = *head;
    }
    *head = prv;
}
bool compare(node *a, node *b) {
    while(a && b) {
        if(a -> data != b -> data) return false;
        a = a -> next; b = b -> next;
    }
    return !a && !b;
}
bool ispalindrome(node *head) {
    if(!head || !head -> next) return true;
    node *slow = head, *fast = head, *prv = head;
    while(fast -> next && fast -> next -> next) {
        prv = slow; slow = slow -> next;
        fast = fast -> next -> next;
    }
    node *zweithalf = slow -> next;
    prv -> next = nullptr;
    node *mid = fast -> next ? slow : nullptr;
    if(mid) slow = slow -> next;
    reverse(&zweithalf);
    bool res = compare(head, zweithalf);
    reverse(&zweithalf);
    prv -> next = mid? (mid -> next == zweithalf) : zweithalf;
    return res;
}

