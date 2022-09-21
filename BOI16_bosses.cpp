#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
 
/*
    4
    1 4
    3 1 3 4
    2 1 2
    1 3
*/
 
using namespace std;
 
const int maxN = 5005;
const int inf = 1e18;
 
int         n, cnt = 0, cost = 0;
vector<int> adj[maxN];
int         s[maxN];
 
void bfs(int x){
    memset(s, 0, sizeof(s));
 
    queue<int> q;
    q.push(x);
    s[x] = 1;
    cost = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!s[v]){
                ++cnt;
                s[v] = s[u] + 1;
                cost += s[v];
                q.push(v);
            }
        }
    }
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> n;
	for(int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j){
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }
 
    int ans = inf;
    for(int i = 1; i <= n; ++i){
        cnt = 0;
        cost = 0;
        bfs(i);
        if(cnt == n - 1)
            ans = min(ans, cost);
    }
 
    cout << ans;
    return 0;
}