#include<bits/stdc++.h>
using namespace std;
struct node{
    public:
    int data;
    node *nxt;
    node(int val):data(val), nxt(nullptr){}
};
class DetectCycle{
    public:
    bool HasCycle(node *head){
        if(head == nullptr || head->nxt == nullptr)
            return false;
        node *slow = head;
        node *fast = head;
        while(fast !=nullptr && fast->nxt !=nullptr){
            slow = slow->nxt;
            fast = fast->nxt->nxt;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
int main(){
    node *head = new node(1);
    node *a = new node(2);
    node *b = new node(3);
    node *c = new node(4);
    node *d = new node(5);
    head ->nxt = a;
    a ->nxt = b; b ->nxt = c;
    c ->nxt = d; d ->nxt = a;
    DetectCycle Dc;
    bool cyclic = Dc.HasCycle(head);
    if(cyclic)
        cout << "cycle exits";
    else
        cout << "Didn't exit";
    delete head;
    delete a; delete b;
    delete c; delete d;
}

