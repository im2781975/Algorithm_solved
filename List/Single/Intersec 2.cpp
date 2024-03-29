#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
void append(struct Node** head_ref, int new_data)
{
 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
vector<int> intersection(struct Node* tmp1, struct Node* tmp2,
                  int k)
{
    vector<int> res(k);
    unordered_set<int> set;
    while (tmp1 != NULL) {
 
        set.insert(tmp1->data);
        tmp1 = tmp1->next;
    }
 
    int cnt = 0;
    while (tmp2 != NULL) {
        if (set.find(tmp2->data) != set.end()) {
            res[cnt] = tmp2->data;
            cnt++;
        }
        tmp2 = tmp2->next;
    }
    return res;
}
int main()
{
 
    struct Node* ll = NULL;
    struct Node* ll1 = NULL;
 
    append(&ll,7);
    append(&ll,6);
    append(&ll,5);
    append(&ll,4);
    append(&ll,3);
    append(&ll,2);
    append(&ll,1);
    append(&ll,0);
 
    append(&ll1,7);
    append(&ll1,6);
    append(&ll1,5);
    append(&ll1,4);
    append(&ll1,3);
    append(&ll1,12);
    append(&ll1,0);
    append(&ll1,9);
 
    vector<int> arr= intersection(ll, ll1, 6);
    for (int i :arr)
        cout << i << "\n";
 
    return 0;
}
