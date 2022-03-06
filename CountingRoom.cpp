#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

const int N = 1005;
const int tx[4] = {-1,0,0,1};
const int ty[4] = {0,-1,1,0};

queue<pair<int, int>> q;
char a[N][N];
bool mark[N][N];
int n, m, ans = 0;

bool avail(int u, int v){
    if(u <= n && u >= 1 && v <= m && v >= 1 && mark[u][v] && a[u][v] == '.')
        return true;
    return false;
}

void bfs(int u, int v){
    ++ans;
    q.push(make_pair(u,v));
    mark[u][v] = false;
        
    while(!q.empty()){
        pair<int, int> x = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int u1 = x.first + tx[i];
            int v1 = x.second + ty[i];
            if(avail(u1,v1)){
                q.push(make_pair(u1,v1));
                mark[u1][v1] = false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            mark[i][j] = true;
        }
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(mark[i][j] && a[i][j] == '.')
                bfs(i,j);
    
    cout << ans;
}
