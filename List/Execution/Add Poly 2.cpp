#include <bits/stdc++.h> 
using namespace std;
struct Node { 
    int coeff; 
    int pow; 
    struct Node* next; 
  
    Node(int c, int p) 
    { 
        coeff = c; 
        pow = p; 
        next = NULL; 
    } 
}; 
void append(struct Node** head_ref, struct Node** tail_ref, 
            int new_data, int new_data1) 
{ 
    struct Node* new_node = new Node(new_data, new_data1); 
  
    if (*head_ref == NULL) 
        *head_ref = new_node; 
    else
        (*tail_ref)->next = new_node; 
    *tail_ref = new_node; 
} 
void printList(struct Node* head) 
{ 
    struct Node* temp = head; 
  
    while (temp != NULL) { 
        printf("%d %d ", temp->coeff, temp->pow); 
        temp = temp->next; 
    } 
} 
Node* addPolynomial(Node* p1, Node* p2); 
void create_node(int x, int y, struct Node** temp) 
{ 
    struct Node *r, *z; 
    z = *temp; 
    if (z == NULL) { 
        r = new Node(x, y); 
        *temp = r; 
        r->next = NULL; 
    } 
    else { 
        r->next = new Node(x, y); 
        r = r->next; 
        r->next = NULL; 
    } 
}
// 1st Number: 5x^2+4x^1+2x^0 
// 2nd Number: -5x^1-5x^0 
class Solution { 
    public: 
    Node* addPolynomial(Node* p1, Node* p2) 
    { 
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
int main() 
{ 
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
    struct Node *tail1 = NULL, *tail2 = NULL; 
    // 1st Number: 5x^2+4x^1+2x^0 
    append(&poly1, &tail1, 5, 2); 
    append(&poly1, &tail1, 4, 1); 
    append(&poly1, &tail1, 2, 0); 
    // 2nd Number: -5x^1-5x^0 
    append(&poly2, &tail2, -5, 1);
    append(&poly2, &tail2, -5, 0); 
    Solution obj; 
    Node* sum = obj.addPolynomial(poly1, poly2); 
    for (Node* ptr = sum; ptr; ptr = ptr->next) { 
        // printing polynomial 
        cout << ptr->coeff << "x^" << ptr->pow; 
        if (ptr->next) 
            cout << " + "; 
    } 
    cout << endl; 
} 
