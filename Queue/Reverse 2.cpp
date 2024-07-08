#include<iostream>
#include<queue>
using namespace std;
// Function to reverse first k elements of a queue
void solve(queue <int> q, int k){
    if(k == 0)
        return;
    int first = q.front();
    q.pop();
    solve(q, k - 1);
    q.push(first);
}
queue <int> ReverseFirst(queue <int> q, int k){
    solve(q, k);
    int size = q.size() - k;
    while(size-- > 0){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}
void print(queue <int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
int main(){
    queue <int> q;
    for(int i = 0; i <= 100; i+=10)
        q.push(i);
    int k = 5;
    // Need to store the value in a queue
    q = ReverseFirst(q, k);
    print(q);
}
