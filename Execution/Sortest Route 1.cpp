//CSES
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const ll INF=(ll)1e9;
ll dist[maxn];
vector<pair<ll, ll> > adj[maxn];
vector<bool>visited(maxn);
void dijkstra(int src, int n)
{
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    dist[src]=0;
    //Min heap
    priority_queue<pair<ll, ll>, vector<pair <ll, ll> >, greater<pair < ll, ll> > > pq;
    pq.push({ 0, src});
    while(!pq.empty())
    {
        int u=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        
        if(visited[u])
            continue;
        visited[u]=true;
        for(auto child:adj[u])
        {
            int v=child.first;
            ll c=child.second;
            if((cost + c) < dist[v])
            {
                dist[v] = cost + c;
                pq.push({dist[v], v });
            }
        }
    }
}
int main()
{
    int e, n;
    cin >> n >> e;
    for(int i=1; i<=e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1, n);
    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}
