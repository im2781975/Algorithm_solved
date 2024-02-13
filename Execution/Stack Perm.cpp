// Given two arrays, check if one array is stack permutation of other.
#include<bits/stdc++.h>
using namespace std;
// function to check if input queue is permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
    // Input queue
    queue<int> input;
    for (int i=0;i<n;i++)
        input.push(ip[i]);
    // output queue
    queue<int> output;
    for (int i=0;i<n;i++)
        output.push(op[i]);
    // stack to be used for permutation
    stack <int> tempStack;
    while (!input.empty())
    {
        int ele = input.front();
        input.pop();
        if (ele == output.front())
        {
            output.pop();
            while (!tempStack.empty())
            {
                if (tempStack.top() == output.front())
                {
                    tempStack.pop();
                    output.pop();
                }
                else
                    break;
            }
        }
        else
            tempStack.push(ele);
    }
    // If after processing, both input queue and stack are empty then the input queue is permutable otherwise not.
    return (input.empty()&&tempStack.empty());
}
// check if input array is permutable to output array
bool checkStackPermutation(int ip[], int op[], int n)
{
    // we will be pushing elements from input array to stack uptill top of our stack   matches with first element of output array
    stack<int>s;
    // will maintain a variable j to iterate on output array 
    int j=0;
    // will iterate one by one in input array
    for(int i=0;i<n;i++)
    {
    // pushed an element from input array to stack
        s.push(ip[i]);
        // if our stack isn't empty and top matches with output array
        // then we will keep popping out from stack uptill top matches with output array
        while(!s.empty() and s.top()==op[j])
        {
            s.pop();
            // increasing j so next time we can compare next element in output array
          j++;
        }
    }
    // if output array was a correct permutation of input array then
    // by now our stack should be empty 
    if(s.empty())
        return true;
    return false;  
}
int main()
{
    int input[] = {1, 2, 3};
    int output[] = {2, 1, 3};
    int n = 3;
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
