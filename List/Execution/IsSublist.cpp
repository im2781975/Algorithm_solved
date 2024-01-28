#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
 
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
 
bool isSublist(Node* list, Node* sublist)
{
    // Base cases
    if (sublist == nullptr) {
        return true;
    }
    if (list == nullptr) {
        return false;
    }
    if (list->data == sublist->data) {
        return isSublist(list->next, sublist->next);
    }
    else {
        return isSublist(list->next, sublist);
    }
}
int main()
{
    Node* list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(1);
    list->next->next->next = new Node(2);
    list->next->next->next->next = new Node(3);
    list->next->next->next->next->next = new Node(4);
 
    Node* sublist = new Node(1);
    sublist->next = new Node(2);
    sublist->next->next = new Node(3);
    sublist->next->next->next = new Node(4);
 
    // Check if sublist is present in list
    if (isSublist(list, sublist)) {
        cout << "LIST FOUND" << endl;
    }
    else {
        cout << "LIST NOT FOUND" << endl;
    }
 
    return 0;
}
