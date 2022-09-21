#include <bits/stdc++.h>
#define RED 0
#define GRE 1
#define YEL 2
using namespace std;
 
const int inf = 1e9;
 
int N;
int f[205][205][205][3];
int pos[405][3], pre[405][3];
int pr, py, pg;
 
int calc(int r, int g, int y, int last)
{
    if(r == pr && g == pg && y == py)
        return 0;
 
    if(f[r][g][y][last] != -1)
        return f[r][g][y][last];
 
    int res = inf;
 
    if(r < pr && last != 0) {
        int now = pos[r][0];
        res = min(res, calc(r + 1, g, y, 0) + max(pre[now][1] - g, 0) + max(pre[now][2] - y, 0));
    }
 
    if(g < pg && last != 1) {
        int now = pos[g][1];
        res = min(res, calc(r, g + 1, y, 1) + max(pre[now][0] - r, 0) + max(pre[now][2] - y, 0));
    }
 
    if(y < py && last != 2) {
        int now = pos[y][2];
        res = min(res, calc(r, g, y + 1, 2) + max(pre[now][0] - r, 0) + max(pre[now][1] - g, 0));
    }
 
    return f[r][g][y][last] = res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> N;
    char c;
    memset(f, -1, sizeof(f));
 
    for(int i = 1; i <= N; i++) {
        cin >> c;
 
        if(c == 'R') {
          pre[i][0] = 1;
          pos[pr++][0] = i;
        }
        else if(c == 'G') {
          pre[i][1] = 1;
          pos[pg++][1] = i;
        }
        else {
          pre[i][2] = 1;
          pos[py++][2] = i;
        }
 
        pre[i][0] += pre[i - 1][0];
        pre[i][1] += pre[i - 1][1];
        pre[i][2] += pre[i - 1][2];
    }
 
    if(max(pr, max(pg, py)) > pr + py + pg - max(pr, max(pg, py)) + 1) {
        cout << -1 << endl;
        return 0;
    }
 
    int ans = inf;
    if(pr > 0)
    {
        int now = pos[0][0];
        ans = min(ans, calc(1, 0, 0, 0) + pre[now][1] + pre[now][2]);
    }
    if(pg > 0)
    {
        int now = pos[0][1];
        ans = min(ans, calc(0, 1, 0, 1) + pre[now][0] + pre[now][2]);
    }
    if(py > 0)
    {
        int now = pos[0][2];
        ans = min(ans, calc(0, 0, 1, 2) + pre[now][0] + pre[now][1]);
    }
    if(ans != inf) {
        cout << ans << endl;
    }
    else
        cout << endl;
 
    cin >> N;
}