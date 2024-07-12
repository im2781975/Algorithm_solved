// customized data structure
#include<bits/stdc++.h>
using namespace std;
#define Max 100
class Stack{
    int min, size;
    public:
    Stack():min(INT_MAX), size(0){}
    vector<pair<int, int> > arr;
    int AddValue(int val);
    int GetLast();
    int RemoveLast();
    int GetMin();
    void Display();
    int Size();
};
int Stack::AddValue(int val){
    if(size >= Max){
        cout << "Overflow";
        return 0;
    }
    if(min > val)
        min = val;
    arr.push_back(make_pair(val, min));
    size++; return 1;
}
int Stack::GetLast(){
    if(size == 0){
        cout << "Underflow";
        abort();
    }
    return arr[size - 1].first;
}
int Stack::RemoveLast(){
    if(size == 0){
        cout << "Underflow";
        abort();
    }
    arr.pop_back(); size--;
    if(size == 0)
        min = INT_MAX;
    else
        min = arr[size - 1].second;
    return 1;
}
int Stack::GetMin(){
    if(size == 0){
        cout << "Stack is empty";
        return 0;
    }
    return arr[size - 1].second;
}
void Stack::Display(){
    if(size == 0){
        cout << "Underflow";
        return;
    }
    cout << "\nElements are: ";
    for(int i = size - 1; i >= 0; i--)
        cout << arr[i].first << " ";
}
int Stack::Size(){
    return size;
}
int main(){
    Stack st;
    int Done = st.AddValue(5);
    (Done == 1)? cout << "Successfull\n" : cout << "No\n";
    st.AddValue(7);
    st.AddValue(3);
    st.Display();
    cout << "\nMin elements are: " << st.GetMin();
    cout << "\n" << st.Size();
}
