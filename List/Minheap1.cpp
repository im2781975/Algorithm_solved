/
/
// A program to take numbers from different machines and print them in sorted order 
#include <stdio.h> 
 
// A Linked List node 
struct ListNode 
{ 
 int data; 
 struct ListNode* next; 
}; 
 
// A Min Heap Node 
struct MinHeapNode 
{ 
 ListNode* head; 
}; 
 
// A Min Heao (Collection of Min Heap nodes) 
struct MinHeap 
{ 
 int count; 
 int capacity; 
 MinHeapNode* array; 
}; 
 
// A function to create a Min Heap of given capacity 
MinHeap* createMinHeap( int capacity ) 
{ 
 MinHeap* minHeap = new MinHeap; 
 minHeap->capacity = capacity; 
 minHeap->count = 0; 
 minHeap->array = new MinHeapNode [minHeap->capacity]; 
 return minHeap; 
} 
 
/* A utility function to insert a new node at the beginning 
of linked list */
void push (ListNode** head_ref, int new_data) 
{ 
 /* allocate node */
 ListNode* new_node = new ListNode; 
 
 /* put in the data */
 new_node->data = new_data; 
 
 /* link the old list off the new node */
 new_node->next = (*head_ref); 
 
 /* move the head to point to the new node */
 (*head_ref) = new_node; 
} 
 
// A utility function to swap two min heap nodes. This function 
// is needed in minHeapify 
void swap( MinHeapNode* a, MinHeapNode* b ) 
{ 
 MinHeapNode temp = *a; 
 *a = *b; 
 *b = temp; 
} 
 
// The standard minHeapify function. 
void minHeapify( MinHeap* minHeap, int idx ) 
{ 
 int left, right, smallest; 
 left = 2 * idx + 1; 
 right = 2 * idx + 2; 
 smallest = idx; 
 
 if ( left < minHeap->count && 
  minHeap->array[left].head->data < 
  minHeap->array[smallest].head->data 
 ) 
  smallest = left; 
 
 if ( right < minHeap->count && 
  minHeap->array[right].head->data < 
  minHeap->array[smallest].head->data 
 ) 
  smallest = right; 
 
 if( smallest != idx ) 
 { 
  swap( &minHeap->array[smallest], &minHeap->array[idx] ); 
  minHeapify( minHeap, smallest ); 
 } 
} 
 
// A utility function to check whether a Min Heap is empty or not 
int isEmpty( MinHeap* minHeap ) 
{ 
 return (minHeap->count == 0); 
} 
 
// A standard function to build a heap 
void buildMinHeap( MinHeap* minHeap ) 
{ 
 int i, n; 
 n = minHeap->count - 1; 
 for( i = (n - 1) / 2; i >= 0; --i ) 
  minHeapify( minHeap, i ); 
} 
 
// This function inserts array elements to heap and then calls 
// buildHeap for heap property among nodes 
void populateMinHeap( MinHeap* minHeap, ListNode* *array, int n ) 
{ 
 for( int i = 0; i < n; ++i ) 
  minHeap->array[ minHeap->count++ ].head = array[i]; 
 
 buildMinHeap( minHeap ); 
} 
 
// Return minimum element from all linked lists 
ListNode* extractMin( MinHeap* minHeap ) 
{ 
 if( isEmpty( minHeap ) ) 
  return NULL; 
 
 // The root of heap will have minimum value 
 MinHeapNode temp = minHeap->array[0]; 
 
 // Replace root either with next node of the same list. 
 if( temp.head->next ) 
  minHeap->array[0].head = temp.head->next; 
 else // If list empty, then reduce heap size 
 { 
  minHeap->array[0] = minHeap->array[ minHeap->count - 1 ]; 
  --minHeap->count; 
 } 
 
 minHeapify( minHeap, 0 ); 
 return temp.head; 
} 
 
// The main function that takes an array of lists from N machines 
// and generates the sorted output 
void externalSort( ListNode *array[], int N ) 
{ 
 // Create a min heap of size equal to number of machines 
 MinHeap* minHeap = createMinHeap( N ); 
 
 // populate first item from all machines 
 populateMinHeap( minHeap, array, N ); 
 
 while ( !isEmpty( minHeap ) ) 
 { 
  ListNode* temp = extractMin( minHeap ); 
  printf( "%d ",temp->data ); 
 } 
} 
 
// Driver program to test above functions 
int main() 
{ 
 int N = 3; // Number of machines 
 
 // an array of pointers storing the head nodes of the linked lists 
 ListNode *array[N]; 
 
 // Create a Linked List 30->40->50 for first machine 
 array[0] = NULL; 
 push (&array[0], 50); 
 push (&array[0], 40); 
 push (&array[0], 30); 
 
 // Create a Linked List 35->45 for second machine 
 array[1] = NULL; 
 push (&array[1], 45); 
 push (&array[1], 35); 
 
 // Create Linked List 10->60->70->80 for third machine 
 array[2] = NULL; 
 push (&array[2], 100); 
 push (&array[2], 80); 
 push (&array[2], 70); 
 push (&array[2], 60); 
 push (&array[2], 10); 
 
 // Sort all elements 
 externalSort( array, N ); 
 
 return 0; 
} 
// An efficient program to print all anagrams together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define NO_OF_CHARS 26
 
// Structure to represent list node for indexes of words in
// the given sequence. The list nodes are used to connect
// anagrams at leaf nodes of Trie
struct IndexNode
{
    int index;
    struct IndexNode* next;
};
 
// Structure to represent a Trie Node
struct TrieNode
{
    bool isEnd;  // indicates end of word
    struct TrieNode* child[NO_OF_CHARS]; // 26 slots each for 'a' to 'z'
    struct IndexNode* head; // head of the index list
};
 
 
// A utility function to create a new Trie node
struct TrieNode* newTrieNode()
{
    struct TrieNode* temp = new TrieNode;
    temp->isEnd = 0;
    temp->head = NULL;
    for (int i = 0; i < NO_OF_CHARS; ++i)
        temp->child[i] = NULL;
    return temp;
}
 
/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare(const void* a, const void* b)
{  return *(char*)a - *(char*)b; }
 
/* A utility function to create a new linked list node */
struct IndexNode* newIndexNode(int index)
{
    struct IndexNode* temp = new IndexNode;
    temp->index = index;
    temp->next = NULL;
    return temp;
}
 
// A utility function to insert a word to Trie
void insert(struct TrieNode** root, char* word, int index)
{
    // Base case
    if (*root == NULL)
        *root = newTrieNode();
 
    if (*word != '\0')
        insert( &( (*root)->child[tolower(*word) - 'a'] ), word+1, index );
    else  // If end of the word reached
    {
        // Insert index of this word to end of index linked list
        if ((*root)->isEnd)
        {
            IndexNode* pCrawl = (*root)->head;
            while( pCrawl->next )
                pCrawl = pCrawl->next;
            pCrawl->next = newIndexNode(index);
        }
        else  // If Index list is empty
        {
            (*root)->isEnd = 1;
            (*root)->head = newIndexNode(index);
        }
    }
}
 
// This function traverses the built trie. When a leaf node is reached,
// all words connected at that leaf node are anagrams. So it traverses
// the list at leaf node and uses stored index to print original words
void printAnagramsUtil(struct TrieNode* root, char *wordArr[])
{
    if (root == NULL)
        return;
 
    // If a lead node is reached, print all anagrams using the indexes
    // stored in index linked list
    if (root->isEnd)
    {
        // traverse the list
        IndexNode* pCrawl = root->head;
        while (pCrawl != NULL)
        {
            printf( "%s ", wordArr[ pCrawl->index ] );
            pCrawl = pCrawl->next;
        }
    }
 
    for (int i = 0; i < NO_OF_CHARS; ++i)
        printAnagramsUtil(root->child[i], wordArr);
}
 
// The main function that prints all anagrams together. wordArr[] is input
// sequence of words.
void printAnagramsTogether(char* wordArr[], int size)
{
    // Create an empty Trie
    struct TrieNode* root = NULL;
 
    // Iterate through all input words
    for (int i = 0; i < size; ++i)
    {
        // Create a buffer for this word and copy the word to buffer
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
 
        // Sort the buffer
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare );
 
        // Insert the sorted buffer and its original index to Trie
        insert(&root,  buffer, i);
    }
 
    // Traverse the built Trie and print all anagrams together
    printAnagramsUtil(root, wordArr);
}
 
 
// Driver program to test above functions
int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
// An efficient program to print all anagrams together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define NO_OF_CHARS 26
 
// Structure to represent list node for indexes of words in
// the given sequence. The list nodes are used to connect
// anagrams at leaf nodes of Trie
struct IndexNode
{
    int index;
    struct IndexNode* next;
};
 
// Structure to represent a Trie Node
struct TrieNode
{
    bool isEnd;  // indicates end of word
    struct TrieNode* child[NO_OF_CHARS]; // 26 slots each for 'a' to 'z'
    struct IndexNode* head; // head of the index list
};
 
 
// A utility function to create a new Trie node
struct TrieNode* newTrieNode()
{
    struct TrieNode* temp = new TrieNode;
    temp->isEnd = 0;
    temp->head = NULL;
    for (int i = 0; i < NO_OF_CHARS; ++i)
        temp->child[i] = NULL;
    return temp;
}
 
/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare(const void* a, const void* b)
{  return *(char*)a - *(char*)b; }
 
/* A utility function to create a new linked list node */
struct IndexNode* newIndexNode(int index)
{
    struct IndexNode* temp = new IndexNode;
    temp->index = index;
    temp->next = NULL;
    return temp;
}
 
// A utility function to insert a word to Trie
void insert(struct TrieNode** root, char* word, int index)
{
    // Base case
    if (*root == NULL)
        *root = newTrieNode();
 
    if (*word != '\0')
        insert( &( (*root)->child[tolower(*word) - 'a'] ), word+1, index );
    else  // If end of the word reached
    {
        // Insert index of this word to end of index linked list
        if ((*root)->isEnd)
        {
            IndexNode* pCrawl = (*root)->head;
            while( pCrawl->next )
                pCrawl = pCrawl->next;
            pCrawl->next = newIndexNode(index);
        }
        else  // If Index list is empty
        {
            (*root)->isEnd = 1;
            (*root)->head = newIndexNode(index);
        }
    }
}
 
// This function traverses the built trie. When a leaf node is reached,
// all words connected at that leaf node are anagrams. So it traverses
// the list at leaf node and uses stored index to print original words
void printAnagramsUtil(struct TrieNode* root, char *wordArr[])
{
    if (root == NULL)
        return;
 
    // If a lead node is reached, print all anagrams using the indexes
    // stored in index linked list
    if (root->isEnd)
    {
        // traverse the list
        IndexNode* pCrawl = root->head;
        while (pCrawl != NULL)
        {
            printf( "%s ", wordArr[ pCrawl->index ] );
            pCrawl = pCrawl->next;
        }
    }
 
    for (int i = 0; i < NO_OF_CHARS; ++i)
        printAnagramsUtil(root->child[i], wordArr);
}
 
// The main function that prints all anagrams together. wordArr[] is input
// sequence of words.
void printAnagramsTogether(char* wordArr[], int size)
{
    // Create an empty Trie
    struct TrieNode* root = NULL;
 
    // Iterate through all input words
    for (int i = 0; i < size; ++i)
    {
        // Create a buffer for this word and copy the word to buffer
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
 
        // Sort the buffer
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare );
 
        // Insert the sorted buffer and its original index to Trie
        insert(&root,  buffer, i);
    }
 
    // Traverse the built Trie and print all anagrams together
    printAnagramsUtil(root, wordArr);
}
 
 
// Driver program to test above functions
int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
