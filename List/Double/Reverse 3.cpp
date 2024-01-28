#include <iostream> 
#include <cstring> 
using namespace std; 
class Node { 
  public: 
      int data; 
      Node *next; 
      Node(int val) 
      { 
          data = val; 
          next = nullptr; 
      } 
}; 
void printReverse(Node *head, int n) 
{ 
        int j = 0; 
        Node *current = head; 
        while (current != nullptr){ 
             
           for (int i = 0; i < 2 * (n - j); i++) 
                cout << " "; 
  
           // use of carriage return to move back   and print. 
           cout << "\r" << current->data; 
           current = current->next;
           j++;  
        } 
} 
Node *push(Node *head, int data)  
{ 
        Node *new_node = new Node(data); 
        new_node->next = head; 
        head = new_node; 
  
        return head; 
} 
  
int printList(Node *head) 
{ 
        // i for finding length of list  
        int i = 0; 
        Node *temp = head; 
        while (temp != nullptr) 
        { 
               cout << temp->data << " "; 
               temp = temp->next; 
               i++; 
        } 
        return i; 
} 
int main() 
{
      Node *head = nullptr; 
      head = push(head, 1); 
      head = push(head, 2); 
      head = push(head, 3); 
      head = push(head, 4); 
      head = push(head, 5); 
      head = push(head, 6); 
  
      cout << "Given linked list: " << endl; 
      // printlist print the list and return the size of list  
      int n = printList(head);  
  
      // print reverse list with help of carriage return function 
      cout << "Reversed Linked list: " << endl; 
      printReverse(head, n);  
      cout << endl; 
      return 0; 
} 

