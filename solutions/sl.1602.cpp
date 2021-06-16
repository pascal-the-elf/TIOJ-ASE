#include <iostream>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked
using namespace std;

const int maxN = 1510;

int n, m, vals[maxN][maxN], x, y;
bool can[maxN][maxN], visited[maxN][maxN];

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

bool isValid(int y, int x){
    return (y >= 0 && x >= 0 && y < n && x < m);
}

void dfs(int y, int x){
    //cout << "Running dfs(" << y << ", " << x << endl;
    if(isValid(y + 1, x) && !visited[y + 1][x] && vals[y + 1][x] >= vals[y][x]){
        can[y + 1][x] = true;
        visited[y + 1][x] = true;
        dfs(y + 1, x);
    }
    if(isValid(y - 1, x) && !visited[y - 1][x] && vals[y - 1][x] >= vals[y][x]){
        can[y - 1][x] = true;
        visited[y - 1][x] = true;
        dfs(y - 1, x);
    }
    if(isValid(y, x + 1) && !visited[y][x + 1] && vals[y][x + 1] >= vals[y][x]){
        can[y][x + 1] = true;
        visited[y][x + 1] = true;
        dfs(y, x + 1);
    }
    if(isValid(y, x - 1) && !visited[y][x - 1] && vals[y][x - 1] >= vals[y][x]){
        can[y][x - 1] = true;
        visited[y][x - 1] = true;
        dfs(y, x - 1);
    }
}

int main(){
    scanint(n);
    scanint(m);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        scanint(vals[i][j]);
        visited[i][j] = false;
        can[i][j] = false;
    }
    scanint(x);
    scanint(y);
    visited[y][x] = true;
    can[y][x] = true;
    dfs(y, x);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(can[j][i]) printf("(%d,%d)\n", i, j);
        }
    }
}
