#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ep emplace_back
using namespace std;
 
typedef pair<int, int> ii;
 
const int maxN = 1e5 + 5;
const int inf = 100;
 
int         n,m,s,t,u,v;
int         distU[maxN], distV[maxN], distS[maxN], distT[maxN], dU[maxN], dV[maxN];
int         deg[maxN];
vector<ii>  adj[maxN];
 
void dijkstra(int s, long long *dist){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[s] = 0;
	pq.push({0,s});
 
	while(!pq.empty()){
		int d = pq.top().first;
		int v = pq.top().se;
		pq.pop();
		if(d > dist[v]) continue;
		for(ii &p : adj[v])
            if(d + p.se < dist[p.fi]){
                dist[p.fi] = d + p.se;
                pq.push({dist[p.fi],p.fi});
            }
	}
}
 
int32_t main ()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> n >> m >> s >> t >> u >> v;
	for(int i = 1; i <= m; ++i){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].ep(b,c);
		adj[b].ep(a,c);
	}
 
	memset(distU, inf, sizeof distU);
	memset(distV, inf, sizeof distV);
	memset(distS, inf, sizeof distS);
	memset(distT, inf, sizeof distT);
 
	dijkstra(u, distU);
	dijkstra(v, distV);
	dijkstra(s, distS);
	dijkstra(t, distT);
 
	for (int i = 1; i <= n; ++i) {
		dU[i] = distU[i];
		dV[i] = distV[i];
		if (distS[i] + distT[i] == distS[t]){
			for (ii p : adj[i])
                if (distS[i] + p.se == distS[p.fi] && distS[p.fi] + distT[p.fi] == distS[t])
                    ++deg[p.fi];
		}
	}
 
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(ii p : adj[cur])
            if(distS[cur] + p.se == distS[p.fi] && distS[p.fi] + distT[p.fi] == distS[t]){
                dU[p.fi] = min(dU[p.fi],dU[cur]);
                dV[p.fi] = min(dV[p.fi],dV[cur]);
        if(!(--deg[p.fi]))
            q.push(p.fi);
		}
	}
 
	int res = 1e18;
	for (int i = 1; i <= n; ++i)
		res = min({res, dU[i] + distV[i], dV[i] + distU[i]});
 
	//cout << res << endl;
	printf("%lld", res);
 
	return 0;
}