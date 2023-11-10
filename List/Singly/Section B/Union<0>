#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;
 
class LinkedList {
public:
    struct Node {
        int data;
        Node* next;
        Node(int d)
            : data(d)
            , next(nullptr)
        {
        }
    };
    Node* head = nullptr;
 
    void printList()
    {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
 
    void push(int new_data)
    {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }
 
    void append(int new_data)
    {
        if (head == nullptr) {
            Node* n = new Node(new_data);
            head = n;
            return;
        }
        Node* n1 = head;
        Node* n2 = new Node(new_data);
        while (n1->next != nullptr) {
            n1 = n1->next;
        }
        n1->next = n2;
        n2->next = nullptr;
    }
 
    bool isPresent(Node* head, int data)
    {
        Node* t = head;
        while (t != nullptr) {
            if (t->data == data)
                return true;
            t = t->next;
        }
        return false;
    }
 
    LinkedList getIntersection(Node* head1, Node* head2)
    {
        unordered_set<int> hset;
        Node* n1 = head1;
        Node* n2 = head2;
        LinkedList result;
 
        while (n1 != nullptr) {
            if (hset.find(n1->data) == hset.end()) {
                hset.insert(n1->data);
            }
            n1 = n1->next;
        }
 
        while (n2 != nullptr) {
            if (hset.find(n2->data) != hset.end()) {
                result.push(n2->data);
            }
            n2 = n2->next;
        }
        return result;
    }
 
    LinkedList getUnion(Node* head1, Node* head2)
    {
        map<int, int> hmap;
        Node* n1 = head1;
        Node* n2 = head2;
        LinkedList result;
 
        while (n1 != nullptr) {
            if (hmap.find(n1->data) != hmap.end()) {
                hmap[n1->data]++;
            }
            else {
                hmap[n1->data] = 1;
            }
            n1 = n1->next;
        }
 
        while (n2 != nullptr) {
            if (hmap.find(n2->data) != hmap.end()) {
                hmap[n2->data]++;
            }
            else {
                hmap[n2->data] = 1;
            }
            n2 = n2->next;
        }
 
        for (auto it = hmap.begin(); it != hmap.end();
             it++) {
            result.append(it->first);
        }
        return result;
    }
};
 
int main()
{
    LinkedList llist1, llist2, intersection, union_list;
 
    llist1.push(20);
    llist1.push(4);
    llist1.push(15);
    llist1.push(10);
 
    llist2.push(10);
    llist2.push(2);
    llist2.push(4);
    llist2.push(8);
 
    intersection = intersection.getIntersection(
        llist1.head, llist2.head);
    union_list
        = union_list.getUnion(llist1.head, llist2.head);
 
    cout << "First List is" << endl;
    llist1.printList();
 
    cout << "Second List is" << endl;
    llist2.printList();
 
    cout << "Intersection List is" << endl;
    intersection.printList();
 
    cout << "Union List is" << endl;
    ;
    union_list.printList();
}
