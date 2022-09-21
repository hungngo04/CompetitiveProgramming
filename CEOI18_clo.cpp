#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
 
using namespace std;
 
//20 1 -9999
//4 1 -700
//4 1 -750
//2 1 -10
//-1 1 300
//-3 1 4550
//-6 1 1500
//4890
 
const int maxN = 1e5 + 10;
const int maxC = 2000 * 50 + 69;
const int inf = 1e9 + 10;
 
struct TCom{int c,f,v;};
 
int     n,m;
int     mark[maxN];
int     f[maxC];
TCom    a[maxN * 2];
 
bool cmp(TCom a, TCom b){
    return a.f > b.f;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    //freopen("inputtt.inp", "r", stdin);
    //freopen("cc.out", "w", stdout);
    cin >> n;
 
    bool f1 = true, f2 = true;
 
    for(int i = 1; i <= n; ++i){
        cin >> a[i].c >> a[i].f >> a[i].v;
        if(a[i].f != 1)
            f1 = false;
    }
    cin >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a[i + n].c >> a[i + n].f >> a[i + n].v;
        if(a[i + n].f != 1)
            f2 = false;
    }
 
    for(int i = 1; i <= n; ++i)
        a[i].v = -a[i].v;
    for(int i = n + 1; i <= n + m; ++i)
        a[i].c = -a[i].c;
 
    if(!(f1 && f2))
        sort(a + 1, a + n + m + 1, cmp);
 
    memset(f, 0, sizeof(f));
 
    for(int i = n + m; i >= 1; --i){
        if(a[i].v < 0){
            for(int j = 0; j <= maxC; ++j)
                if(j + a[i].c >= 0 && j + a[i].c <= maxC)
                    f[j] = max(f[j], f[j + a[i].c] + a[i].v);
        }
        else{
            for(int j = maxC; j >= 0; --j)
                if(j + a[i].c >= 0 && j + a[i].c <= maxC)
                    f[j] = max(f[j], f[j + a[i].c] + a[i].v);
        }
    }
 
    cout << f[0];
}