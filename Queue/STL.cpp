#include<iostream>
#include<queue>
using namespace std;
void print(queue <int> q)
{
    queue <int> tmp = q;
    while(!tmp.empty()){
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << "\n";
}
int main(){
    queue <int> a, b;
    for(int i =0; i < 10; i+= 2)
        a.push(i);
    cout << "Befor Swap: \n";
    print(a);
    for(int i = 10; i < 20; i+= 2)
        b.push(i);
    print(b);
    cout << "\nAfter Swap: \n";
    a.swap(b);
    print(a);
    print(b);
    cout << "Is empty: " << a.empty();
}
