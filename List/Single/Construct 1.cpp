#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
 
struct Node
{
    int data;
    Node *next;
};
Node nodes[MAXN];
int nodeCounter = 0;
 
Node *constructLinkedList(int matrix[][4], int rows, int columns)
{
    Node *sentinel = &nodes[nodeCounter++];
    sentinel->next = NULL;
    Node *current = sentinel;
 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Node *newNode = &nodes[nodeCounter++];
            newNode->data = matrix[i][j];
            newNode->next = NULL;
            current->next = newNode;
            current = current->next;
        }
    }
    return sentinel->next;
}
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    int matrix[3][4] = {{1, 2, 3, 4},
    {5, 6, 7, 8},{9, 10, 11, 12}};
 
    Node *head = constructLinkedList(matrix, 3, 4);
    printLinkedList(head);
 
    return 0;
}
