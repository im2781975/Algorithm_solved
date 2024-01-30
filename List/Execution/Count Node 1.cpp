#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
//This function detects and counts loop nodes in the list.
int countNodesinLoop(struct Node* list)
{
    unordered_set<struct Node*> visited;
    struct Node* current = list;
    int count = 0;
    while (current != nullptr) {
        // If the node is already visited, it means there is a loop
        if (visited.find(current) != visited.end()) {
            struct Node* startOfLoop = current;
            do {
                count++;
                current = current->next;
            } while (current != startOfLoop);
            return count;
        }
        // Mark the current node as visited
        visited.insert(current);
        // Move to the next node
        current = current->next;
    }
    // Return 0 to indicate that
       there is no loop
    return 0;
}
struct Node* newNode(int key)
{
    struct Node* temp = new struct Node;
    temp->data = key;
    temp->next = nullptr;
    return temp;
}
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = head->next;
 
    cout << countNodesinLoop(head) << endl;
 
    return 0;
}
