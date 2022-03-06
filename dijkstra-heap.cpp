//
//  main.cpp
//  dijkstra implement using heap (priority queue)
//
//  Created by Tien Hung
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int N = 2e5 + 10;
const long long inf = 1e9 + 10;

int                             n,m;
int                             d[N];
vector<pair<int, int>>          adj[N];

void dijkstra(int src){
    for(int i = 1; i <= n; ++i)
        d[i] = inf;
    d[src] = 0;
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,src});
    
    while(!pq.empty()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
                
        if(d[u] != du)
            continue;
        
        for(auto x : adj[u]){
            int v = x.second;
            int uv = x.first;
             
            if(d[v] > du + uv){
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    
    dijkstra(1);
    
    for(int i = 1; i <= n; ++i)
        cout << d[i] << " ";
    cout << endl;
}
