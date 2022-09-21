#include <bits/stdc++.h>
#define ll      long long
#define fs      first
#define sc      second
 
using namespace std;
 
const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;
 
int st[maxN * 4], lazy[maxN * 4], a[maxN];
 
void push(int id)
{
    if(lazy[id])
    {
        int t = lazy[id];
 
        st[id * 2] += t;
        st[id * 2 + 1] += t;
 
        lazy[id * 2] += t;
        lazy[id * 2 + 1] += t;
 
        lazy[id] = 0;
    }
 
}
 
void update(int id, int l, int r, int u, int v, int val)
{
    if(v < l || u > r)
        return ;
 
    if(u <= l && v >= r)
    {
        st[id] += val;
        lazy[id] += val;
        return;
    }
 
    push(id);
 
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
 
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
 
int get(int id, int l, int r)
{
    if(l == r)
        return l;
 
    push(id);
 
    int mid = (l + r) / 2;
 
    int res;
    if(st[id * 2 + 1] <= 0)
        res = get(id * 2, l, mid);
    else
        res = get(id * 2 + 1, mid + 1, r);
 
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    //freopen("759C.inp", "r", stdin);
 
    int m;
    cin >> m;
 
    a[0] = -1;
    for(int i = 1; i <= m; ++i)
    {
        int p,t;
        cin >> p >> t;
 
        if(t == 1)
        {
            int x;
            cin >> x;
            a[p] = x;
            update(1, 0, m, 0, p, 1);
        }
        else
            update(1, 0, m, 0, p, -1);
 
        int k = get(1, 0, m);
        cout << a[k] << endl;
    }
}