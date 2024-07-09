#include<iostream>
#include<stdlib.h>
using namespace std;
class TwoStack{
    int *arr, size, top1, top2;
    public:
    TwoStack(int sz){
        arr = new int[sz];
        size = sz;
        top1 = -1; top2 = size;
    }
    void push1(int x){
        if(top1 < top2 -1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout << "Overflow";
            exit(1);
        }
    }
    void push2(int x){
        if(top1 < top2 - 1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout << "Overflow";
            exit(1);
        }
    }
    int pop1(){
        if(top1 >= 0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            cout << "Overflow";
            exit(1);
        }
    }
    int pop2(){
        if(top2 < size){
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            cout << "Overflow";
            exit(1);
        }
    }
};
int main(){
    int n;
    cin >> n;
    TwoStack st(n);
    for(int i = 1; i < n/2; i++){
        st.push1(i);
        cout << st.pop1() << " ";
    }
    cout << "\n";
    for(int i = n/2; i < n-1; i++){
        st.push2(i);
        cout << st.pop2() << " ";
    }
}
