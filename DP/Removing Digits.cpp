//CSES
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
vector<int>dp(maxn, INT_MAX);
int solve(int i)
{
    if(i==0)
        return 0;
    if(dp[i]!=INT_MAX)
        return dp[i];
    vector<int>d;
    for(auto j:to_string(i))
        d.push_back(j - '0');
    for(auto val: d)
    {
        dp[i]=min(dp[i], solve(i -  val) +1 );
    }
    return dp[i];
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n);
}
