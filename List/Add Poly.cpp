#include<iostream>
using namespace std;

class Node {
public:
    int coeff, power;
    Node* next;
    Node(int c, int p) : coeff(c), power(p), next(nullptr) {}
};

void printList(Node* head) {
    cout << "Polynomial: ";
    for (Node* curr = head; curr; curr = curr->next) {
        if (curr->coeff > 0 && curr != head) cout << " + ";
        cout << curr->coeff << "x^" << curr->power;
    }
    cout << endl;
}

void insertEnd(Node*& head, int coeff, int power) {
    Node* newNode = new Node(coeff, power);
    if (!head) {
        head = newNode;
        return;
    }
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = newNode;
}

void addPolynomials(Node* p1, Node* p2) {
    if (!p1 && !p2) return;
    
    int c1 = p1 ? p1->coeff : 0;
    int p1pow = p1 ? p1->power : -1;
    int c2 = p2 ? p2->coeff : 0;
    int p2pow = p2 ? p2->power : -1;
    
    if (p1pow == p2pow && p1pow != -1) {
        int sum = c1 + c2;
        if (sum != 0) {
            cout << " " << sum << "x^" << p1pow;
        }
        addPolynomials(p1 ? p1->next : nullptr, p2 ? p2->next : nullptr);
    } else if (p1pow > p2pow) {
        cout << " " << c1 << "x^" << p1pow;
        addPolynomials(p1 ? p1->next : nullptr, p2);
    } else {
        cout << " " << c2 << "x^" << p2pow;
        addPolynomials(p1, p2 ? p2->next : nullptr);
    }
}
// Create polynomial (terms in descending power order)
Node* createPolynomial(vector<pair<int,int>>& terms) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (auto& term : terms) {
        Node* newNode = new Node(term.first, term.second);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
// Add two polynomials (recursive, returns new list)
Node* addPolynomial(Node* p1, Node* p2) {
    // Base case
    if (!p1 && !p2) return nullptr;
    
    int c1 = p1 ? p1->coeff : 0;
    int pow1 = p1 ? p1->pow : -1;
    int c2 = p2 ? p2->coeff : 0;
    int pow2 = p2 ? p2->pow : -1;
    
    Node* result = nullptr;
    
    // Same power - add coefficients
    if (pow1 == pow2 && pow1 != -1) {
        int sum = c1 + c2;
        if (sum != 0) {  // Skip zero coefficients
            result = new Node(sum, pow1);
            result->next = addPolynomial(p1 ? p1->next : nullptr, p2 ? p2->next : nullptr);
        } else {
            result = addPolynomial(p1 ? p1->next : nullptr, p2 ? p2->next : nullptr);
        }
    }
    // p1 has higher power
    else if (pow1 > pow2) {
        result = new Node(c1, pow1);
        result->next = addPolynomial(p1 ? p1->next : nullptr, p2);
    }
    // p2 has higher power
    else {
        result = new Node(c2, pow2);
        result->next = addPolynomial(p1, p2 ? p2->next : nullptr);
    }
    
    return result;
}
Node* addPolynomial(Node* p1, Node* p2) 
    { 
// 1st Number: 5x^2+4x^1+2x^0 
// 2nd Number: -5x^1-5x^0 
        Node* res = new Node( 
            0, 0); 
        Node* prev = res; 
            // pointer to last node of resultant list 
        // like Merge procedure : 
        while (p1 != NULL and p2 != NULL) { 
            if (p1->pow < p2->pow) { 
                prev->next = p2; 
                prev = p2; 
                p2 = p2->next; 
            } 
            else if (p1->pow > p2->pow) { 
                prev->next = p1; 
                prev = p1; 
                p1 = p1->next; 
            } 
            else { 
                p1->coeff = p1->coeff + p2->coeff; 
                prev->next = p1; 
                prev = p1; 
                p1 = p1->next; 
                p2 = p2->next; 
            } 
        } 
        if (p1 != NULL) { 
            prev->next = p1; 
        }
        if (p2 != NULL) { 
            prev->next = p2; 
        } 
        return res->next; 
    } 
};

int main() {
    Node* head1 = new Node(5, 2);
    insertEnd(head1, 4, 1);
    Node* head2 = new Node(6, 2);
    insertEnd(head2, 4, 1);
    
    printList(head1);
    printList(head2);
    cout << "Sum: ";
    addPolynomials(head1, head2);
    cout << endl;
    
    // TODO: Free memory to avoid leaks
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int coeff, pow;
    Node* next;
};

Node* createNode(int c, int p) {
    Node* node = new Node{c, p, nullptr};
    return node;
}

void append(Node*& head, int c, int p) {
    Node* node = createNode(c, p);
    if (!head) {
        head = node;
        return;
    }
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = node;
}

// Iterative polynomial addition (returns new head)
Node* polyAdd(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node** tail = &result;
    
    while (p1 || p2) {
        int c1 = p1 ? p1->coeff : 0;
        int pow1 = p1 ? p1->pow : -1;
        int c2 = p2 ? p2->coeff : 0;
        int pow2 = p2 ? p2->pow : -1;
        
        int coeff, power;
        Node* next1 = p1 ? p1->next : nullptr;
        Node* next2 = p2 ? p2->next : nullptr;
        
        if (pow1 == pow2 && pow1 != -1) {
            coeff = c1 + c2;
            power = pow1;
            p1 = next1;
            p2 = next2;
        } else if (pow1 > pow2) {
            coeff = c1;
            power = pow1;
            p1 = next1;
        } else {
            coeff = c2;
            power = pow2;
            p2 = next2;
        }
        
        if (coeff != 0) {  // Skip zero coefficients
            *tail = createNode(coeff, power);
            tail = &((*tail)->next);
        }
    }
    return result;
}

void show(Node* head) {
    if (!head) return;
    
    Node* curr = head;
    while (curr) {
        cout << curr->coeff;
        if (curr->pow > 1) cout << "x^" << curr->pow;
        else if (curr->pow == 1) cout << "x";
        
        curr = curr->next;
        if (curr) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    // 5x² + 4x + 2
    Node* poly1 = nullptr;
    append(poly1, 5, 2); append(poly1, 4, 1); append(poly1, 2, 0);
    
    // -5x - 5
    Node* poly2 = nullptr;
    append(poly2, -5, 1); append(poly2, -5, 0);
    
    cout << "1st: "; show(poly1);
    cout << "2nd: "; show(poly2);
    
    Node* sum = polyAdd(poly1, poly2);
    cout << "Sum: "; show(sum);
    
    // TODO: Free memory
    return 0;
}
