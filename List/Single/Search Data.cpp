#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int key;
    Node* next;
};
void push(Node** head_ref, int new_key)
{
    Node* new_node = new Node();
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main() {
    Node* head = NULL;
    int x = 21;
   

    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    vector<int>v;
    
    //we donot use given data 
    Node* temp=head;
    while(temp!=NULL){
     v.push_back(temp->key);
     temp=temp->next;
    }
    // we use iterator to find.
    vector<int>::iterator it;
    find(v.begin(),v.end(),x);
    if(it==v.end()){
      cout<<"NO"<<endl;
    }else{
     cout<<"YES"<<endl;
    }
    return 0;
}
