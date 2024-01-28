//appends a new node at the end
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    Node* last = *head_ref;
    new_node->data = new_data;
 
    //This new node is going to be the last node, so
    // make next of it as NULL
    new_node->next = NULL;
 
    //If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    // Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
    //Change the next of last node
    last->next = new_node
    // Make last node as previous of new node
    new_node->prev = last;
    return;
}
//inserts a new node on the front of the list.
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    // put in the data
    new_node->data = new_data;
 
    // Make next of new node as head and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;
   // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    // move the head to point to the new node
    (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
    // Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }
    Node* new_node = new Node();
    // put in the data
    new_node->data = new_data;
    // Make next of new node as next of prev_node
    new_node->next = prev_node->next;
    // Make the next of prev_node as new_node
    prev_node->next = new_node;
    //Make prev_node as previous of new_node
    new_node->prev = prev_node;
    //Change previous of new_node's next node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
// Given a node as prev_node, insert a new node 
// after the given node
void insertBefore(Node* next_node, int new_data)
{
    // Check if the given next_node is NULL
    if (next_node == NULL) {
        printf("the given next node cannot be NULL");
        return;
    }
    Node* new_node = new Node();
    // Put in the data
    new_node->data = new_data;
 
    //Make previous of new node as previous of next_node
    new_node->prev = next_node->prev;
    // Make the previous of next_node as new_node
    next_node->prev = new_node;
    //Make next_node as next of new_node
    new_node->next = next_node;
    // Change next of new_node's previous node
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        head = new_node;
}
