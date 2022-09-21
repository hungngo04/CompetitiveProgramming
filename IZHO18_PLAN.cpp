#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
 
using namespace std;
 
typedef pair<int, int> ii;
 
const int maxN = 1e5 + 10;
const int maxM = 5e5 + 10;
const int inf = 1e9;
 
int         n,m;
int         p[maxN][20];
int         d[maxN], par[maxN], par1[maxN], h[maxN];
bool        mark[maxN];
vector<ii>  adj[maxN];
vector<int> a[maxN];
 
priority_queue<ii> pq;
 
void dijkstra(){
    while(!pq.empty()){
        int u = pq.top().se;
        int dist = -pq.top().fi;
        pq.pop();
 
        if(dist > d[u]) continue;
 
        for(auto i : adj[u]){
            int v = i.fi;
            int dst = i.se;
            if(d[u] + dst < d[v]){
                d[v] = d[u] + dst;
                pq.push({-d[v], v});
            }
        }
    }
}
 
int findSet(int u){
    if(par[u] != u) par[u] = findSet(par[u]);
    return par[u];
}
 
void dfs(int u, int pr){
    h[u] = h[pr] + 1;
    p[u][0] = pr;
 
    for(int i = 1; i <= 19; ++i)
        p[u][i] = p[p[u][i - 1]][i - 1];
 
    for(auto v : a[u])
        if(v != pr)
            dfs(v, u);
}
 
int getlca(int x, int y)
{
    for(int i = 19; i >= 0; --i){
        if(h[p[x][i]] >= h[y])
            x = p[x][i];
    }
 
    for(int i = 19; i >= 0; --i){
        if(h[p[y][i]] >= h[x])
            y = p[y][i];
    }
 
    for(int i = 19; i >= 0; --i){
        if(p[x][i] != p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }
 
    while(x != y){
        x = p[x][0];
        y = p[y][0];
    }
 
    return x;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    //freopen("EvacuationPlan.inp", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
 
    for(int i = 1; i <= n; ++i){
        d[i] = inf;
        par[i] = i;
    }
 
    int k;
    cin >> k;
    for(int i = 1; i <= k; ++i){
        int x;
        cin >> x;
        pq.push({0, x});
        d[x] = 0;
    }
 
    dijkstra();
 
    vector<int> e;
    for(int i = 1; i <= n; ++i)
        e.pb(i);
 
    sort(e.begin(), e.end(), [&](int a, int b){
        return ii(d[a], a) > ii(d[b], b);
    });
 
    for(auto u : e){
        for(auto v : adj[u]){
            if(ii(d[v.fi], v.fi) > ii(d[u], u)){
                int parV = findSet(v.fi);
                if(parV == u) continue;
                a[u].pb(parV);
                a[parV].pb(u);
                par[parV] = u;
            }
        }
    }
 
    dfs(e.back(), 0);
 
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i){
        int x,y;
        cin >> x >> y;
        cout << d[getlca(x,y)] << endl;
    }
}