// check two n-ary trees are mirror.
#include <bits/stdc++.h>
using namespace std;
// Function to check given two trees are mirror of each other or not
int checkMirrorTree(int n, int e, int A[], int B[])
{
    //Lists to store nodes of the tree
    vector<stack<int>> s;
    vector<queue<int>> q;
    // initializing both list with empty stack and queue
    for (int i = 0; i <= n; i++)
    {
        s.push_back(stack<int>());
        queue<int> queue;
        q.push_back(queue);
    }
    // add all nodes of tree 1 to list of stack and tree 2 to list of queue
    for (int i = 0; i < 2 * e; i += 2)
    {
        s[A[i]].push(A[i + 1]);
        q[B[i]].push(B[i + 1]);
    }
    // now take out the stack and queues for each of the nodes and compare them one by one
    for (int i = 1; i <= n; i++)
    {
        while (!s[i].empty() && !q[i].empty())
        {
            int a = s[i].top();
            s[i].pop();
            int b = q[i].front();
            q[i].pop();
            if (a != b)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n = 3;
    int e = 2;
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};
    if (checkMirrorTree(n, e, A, B) == 1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
