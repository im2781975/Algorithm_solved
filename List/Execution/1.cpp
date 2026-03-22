#include<bits/stdc++.h>
using namespace std;
struct node {
    int data; node *next;
}
void push(node **head, int val) {
    node *newnode = new node();
    newnode -> data = val; 
    newnode -> next = *head;
    *head =  newnode;
}
void printrandom(node *head) {
    if(!head) return;
    srand(time(NULL));
    int res = head -> data, n = 1;
    node *curr = head;
    while(curr) {
        n++; 
        if(rand() % n == 0) res = curr -> data;
        curr = curr -> next;
    }
    cout << res;
}
void printrandom(node *head) {
    node *curr = head;
    vector <int> vec;
    while(curr) {
        vec.push_back(curr -> data);
        curr = curr -> next;
    }
    int idx = rand() % (vec.size());
    cout << vec[idx] << endl;
}
node *insertfront(node *head, int data) {
    node *newnode = new node(data);
    newnode -> next = head; return newnode;
}
void rearrange(node **head) {
    node *odd = nullptr, *even = nullptr;
    node *curr = *head;
    while(curr) {
        if(curr -> data % 2 == 0) even = insertfront(even, curr -> data);
        else odd = insertfront(odd, curr -> data);
        curr = curr -> next;
    }
    node *res = nullptr;
    node *currOdd = odd, *currEven = even;
    bool takeOdd = true;
    while(currOdd || currEven) {
        if(takeOdd && currOdd) {
            res = insertfront(res, currOdd -> data);
            currOdd = currOdd -> next;
        }
        else if(currEven){
            res = insertfront(res, currEven -> data);
            currEven = currEven -> next;
        }
        else takeOdd = !takeOdd;
    }
    *head = res;
}
void reverse(node **head) {
    node *prv = nullptr, *curr = *head;
    while(curr) {
        node *tmp = curr -> next;
        curr -> next = prv; 
        prv = curr; curr = tmp;
    }
}
void rearrange(node **head) {
    node *slow = *head, *fast = *head;
    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    node *head2 = slow -> next;
    slow -> next = nullptr;
    reverse(&head2);
    node *p1 = *head, *p2 = *head2;
    while (p1 && p2) {
        node* next1 = p1->next;
        node* next2 = p2->next;
        
        p1->next = p2; p2->next = next1;
        p1 = next1; p2 = next2;
    }
}
void rearrange(node **head, node *last) {
    if(!last) return;
    rearrange(head, last -> next);
    if(!(*head) || !(*head) -> next) return;
    if ((*head) != last && (*head) -> next != last) {
        node *tmp = (*head) -> next;
        (*head) -> next = last;
        last -> next = tmp;
        *head = tmp;
    }
    else (*head) -> next = nullptr;
}
void rearrange(node **head) {
    node *prv = nullptr, *curr = *head;
    while(curr && curr -> next) {
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        tmp -> next = curr;
        if(prv) prv -> next = curr;
        else *head = tmp;
        prv = tmp; curr = tmp -> next;
    }
}
void rearrangeOddEven(node *head) {
    stack <node*> odd, even;
    node *curr = head; int pos = 1;
    while(curr) {
        if ((curr -> data % 2 != 0) != (pos % 2 != 0)) {
            if (curr -> data % 2 == 0)  even.push(curr);
            else odd.push(curr);
        }
        curr = curr->next; pos++;
    }
    while (!odd.empty() && !even.empty()) {
        swap(odd.top() -> data, even.top() -> data);
        odd.pop(); even.pop();
    }
}
