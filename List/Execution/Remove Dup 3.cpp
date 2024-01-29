#include <iostream>
#include <set>
struct ListNode {
    int val; 
    ListNode*next;
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};
class Solution {
public:
    // Remove duplicates from sorted linked list using set
    ListNode* deleteDuplicates(ListNode* head)
    {
        // Return head if it's empty
        if (!head)
            return head;
        // Use set to store unique values in linked list
        set<int> set;
        ListNode* curr = head; 
            // Pointer to traverse the linked list
        ListNode* prev = NULL; 
        // Pointer to keep track of the previous node
        // Iterate through the linked list
        while (curr) {
            // If the current value already exists in set, remove the node
            if (set.count(curr->val)) {
                prev->next = curr->next;
            }
            else {
                // Otherwise, add the value to set and move on to the next node
                set.insert(curr->val);
                prev = curr;
            }
            curr = curr->next;
        }
        // Return the head of the linked list
        return head;
    }
};
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next
        = new ListNode(3);
    ListNode* BeforePrinter = head;
    cout<< "Before removing duplicates linked list is:"
        << "\n";
    while (BeforePrinter) {
        cout << BeforePrinter->val << " ";
        BeforePrinter = BeforePrinter->next;
    }
    cout << "\n";
    Solution solution;
    // Remove duplicates from the linked list using the
    // deleteDuplicates function
    head = solution.deleteDuplicates(head);
    // Print the linked list after removing duplicates
    cout << "after removing duplicates linked list is:"
              << "\n";
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";
    return 0;
}
