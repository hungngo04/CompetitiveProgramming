#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
 
using namespace std;
 
const int maxN = 1e5 + 5;
const int maxK = 105;
const int inf = 1e9 + 10;
 
int n,k;
int a[maxN], L[maxN], minn[maxN], f[maxK][maxN];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
 
    memset(f, inf, sizeof f);
    f[1][0] = 0;
 
    for (int i = 1; i <= n; ++i)
        f[1][i] = max(f[1][i - 1], a[i]);
 
    int tmp;
    for (int i = 2; i <= k; ++i) {
        stack<pair<int, int> > S;
        for (int j = i; j <= n; ++j) {
            int minn = f[i - 1][j - 1];
            while (!S.empty() && a[S.top().se] <= a[j]) {
                minn = min(minn, S.top().fi);
                S.pop();
            }
            if(S.empty()) tmp = 0;
            else tmp = S.top().se;
            f[i][j] = min(f[i][tmp], minn + a[j]);
            S.push({minn, j});
        }
    }
    cout << f[k][n] << endl;
    return 0;
}