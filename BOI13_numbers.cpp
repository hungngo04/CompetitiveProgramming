#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int     dp[10][10][25][2];
string  s;
 
int calc(int fi, int se, int len, int f){
    if(len >= s.length())
        return 1;
 
    if(dp[fi][se][len][f] != -1)
        return dp[fi][se][len][f];
 
    int res = 0;
 
    if(f){
        for(int i = 0; i <= 9; ++i){
            if(i != fi && i != se)
                res += calc(se, i, len + 1, true);
        }
    }
    else{
        int lim = s[len] - '0';
 
        for(int i = 0; i < lim; ++i){
            if(i != fi && i != se)
                res += calc(se, i, len + 1, true);
        }
 
        if(lim != fi && lim != se)
            res += calc(se, lim, len + 1, false);
    }
 
    return dp[fi][se][len][f] = res;
}
 
int solve(int a){
    stringstream ss;
    ss << a;
    s = ss.str();
 
    memset(dp, -1, sizeof(dp));
 
    int res = 0;
 
    bool tmp;
    for(int i = 1; i <= s[0] - '0'; ++i){
        if(i != s[0] - '0') tmp = true;
        else tmp = false;
        res += calc(i, i, 1, tmp);
    }
 
    for(int i = 2; i <= s.length(); ++i){
        for(int j = 1; j <= 9; ++j){
            res += calc(j, j, i, true);
        }
    }
 
    return res;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
 
    int a,b;
    cin >> a >> b;
 
    int res = solve(b) - solve(a - 1);
    cout << res;
 
    return 0;
}