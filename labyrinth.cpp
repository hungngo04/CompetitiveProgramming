#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1005;
const int tx[4] = {-1,0,0,1};
const int ty[4] = {0,-1,1,0};

queue<pair<int, int>> q;
vector<int> path;
pair<int, int> dst, start;
char a[N][N];
bool mark[N][N];
int prevStep[N][N];
int n, m = 0;

bool avail(int u, int v){
    if(u <= n && u >= 1 && v <= m && v >= 1 && mark[u][v] && a[u][v] != '#')
        return true;
    return false;
}

void bfs(int u, int v){
    q.push(make_pair(u,v));
    mark[u][v] = false;
    
    
    while(!q.empty()){
        pair<int, int> x = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i){
            int u1 = x.first + tx[i];
            int v1 = x.second + ty[i];
            if(avail(u1,v1)){
                mark[u1][v1] = false;
                prevStep[u1][v1] = i;
                q.push(make_pair(u1,v1));
            }
        }
    }
}

void tracePath(){
    if(mark[dst.first][dst.second])
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        while(dst != start){
            int prev = prevStep[dst.first][dst.second];
            path.push_back(prev);
            dst = make_pair(dst.first - tx[prev], dst.second - ty[prev]);
        }
    }
    
    reverse(path.begin(), path.end());
    
    cout << path.size() << endl;
    
    for(auto v : path){
        switch (v) {
            case 0:
                cout << "U";
                break;
            case 1:
                cout << "L";
                break;
            case 2:
                cout << "R";
                break;
            case 3:
                cout << "D";
                break;
        }
    }
    
    cout << endl;
}

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            mark[i][j] = true;
        }
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == 'A'){
                start = make_pair(i,j);
                bfs(i,j);
            }
            if(a[i][j] == 'B')
                dst = make_pair(i,j);
        }
}

int main(int argc, const char * argv[]) {
    input();
    tracePath();
}
