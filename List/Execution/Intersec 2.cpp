// get intersection point of two linked list
#include <iostream>
#include <unordered_set>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
 
// find the intersection point of two lists
void MegeNode(Node* n1, Node* n2)
{
    unordered_set<Node*> hs;
    while (n1 != NULL) {
        hs.insert(n1);
        n1 = n1->next;
    }
    while (n2) {
        if (hs.find(n2) != hs.end()) {
            cout << n2->data << endl;
            break;
        }
        n2 = n2->next;
    }
}
void Print(Node* n)
{
    Node* curr = n;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
      cout << endl;
}
int main() 
{
     // list 1
    Node* n1 = new Node(1);
    n1->next = new Node(2);
    n1->next->next = new Node(3);
    n1->next->next->next = new Node(4);
    n1->next->next->next->next = new Node(5);
    n1->next->next->next->next->next = new Node(6);
    n1->next->next->next->next->next->next = new Node(7);
     // list 2
    Node* n2 = new Node(10);
    n2->next = new Node(9);
    n2->next->next = new Node(8);
    n2->next->next->next = n1->next->next->next;
    Print(n1);
    Print(n2);
    MegeNode(n1,n2);
    return 0;
}
