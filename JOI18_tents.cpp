#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
 
using namespace std;
 
const int maxN = 3005;
const int mod = 1e9 + 7;
 
int n,m;
int f[maxN][maxN];
 
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
 
    cin >> m >> n;
 
    for(int i = 0; i <= m; ++i)
        f[i][0] = 1;
    for(int i = 0; i <= n; ++i)
        f[0][i] = 1;
 
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
            f[i][j] = (f[i][j] + f[i - 1][j - 1] * 4 % mod * j % mod) % mod;
            if(j >= 2)
            f[i][j] = (f[i][j] + f[i - 1][j - 2] * (j*(j - 1)/2 % mod)) % mod;
            if(i >= 2)
            f[i][j] = (f[i][j] + f[i - 2][j - 1] * j % mod * (i - 1) % mod) % mod;
        }
    }
 
    cout << (f[m][n] - 1 + mod) % mod;
}