#include<bits/stdc++.h> 
using namespace std;
int removeConsecutiveSame(vector <string> v) 
{ 
    stack<string> st; 
    // Start traversing the sequence 
    for (int i=0; i<v.size(); i++) 
    { 
        // Push the current string if the stack is empty 
        if (st.empty()) 
            st.push(v[i]); 
        else
        { 
            string str = st.top(); 
            // compare the current string with stack top if equal, pop the top 
            if (str.compare(v[i]) == 0) 
                st.pop(); 
            // Otherwise push the current string 
            else
                st.push(v[i]); 
        } 
    }
    return st.size(); 
}
int main() 
{ 
    vector<string> V = { "ab", "aa", "aa", "bcd", "ab"}; 
    cout << removeConsecutiveSame(V); 
    return 0; 
} 
