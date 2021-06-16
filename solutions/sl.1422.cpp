#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <string.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int n, m, t = 1, ans = 1e5;
char mp[100][100];
int k[(int)1e8];
time_t start, ed;
unordered_set<string> states;

vector<pii> currentState;

bool need(){
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mp[i][j] == '.') return true;
    return false;
}

int canErase(int y, int x){
    int r = 0;
    for(int k = 0; k < n; k++){
        if(mp[k][x] == '.') r++;
    }
    for(int k = 0; k < m; k++){
        if(mp[y][k] == '.') r++;
    }
    for(int k = -n; k < n; k++){
        if(y + k < n && y + k >= 0 && x + k < m && x + k >= 0 && mp[y + k][x + k] == '.') r++;
        if(y - k < n && y - k >= 0 && x + k < m && x + k >= 0 && mp[y - k][x + k] == '.') r++;
    }
    return r;
}

vector<pii> place(int y, int x){
    mp[y][x] = 'O';
    vector<pii> res;
    res.emplace_back(y, x);
    for(int k = 0; k < n; k++){
        if(mp[k][x] == '.'){
            mp[k][x] = 'X';
            res.emplace_back(k, x);
        }
    }
    for(int k = 0; k < m; k++){
        if(mp[y][k] == '.'){
            mp[y][k] = 'X';
            res.emplace_back(y, k);
        }
    }
    for(int k = -n; k < n; k++){
        if(y + k < n && y + k >= 0 && x + k < m && x + k >= 0 && mp[y + k][x + k] == '.'){
            mp[y + k][x + k] = 'X';
            res.emplace_back(y + k, x + k);
        }
        if(y - k < n && y - k >= 0 && x + k < m && x + k >= 0 && mp[y - k][x + k] == '.'){
            mp[y - k][x + k] = 'X';
            res.emplace_back(y - k, x + k);
        }
    }
    return res;
}

void undo(vector<pii> v){
    for(pii p : v) mp[p.F][p.S] = '.';
}

void show(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << mp[i][j];
        cout << endl;
    }
}

void dfs(int y, int d){
    if(clock() - start >= CLOCKS_PER_SEC * 6) return;
    if(d > ans) return;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        if(mp[i][y] == '.'){
            v = place(i, y);
            if(!need()){
                ans = min(ans, d);
                undo(v);
                return;
            }
            for(int j = y + 1; j < m; j++) dfs(j, d + 1);
            undo(v);
        }
    }
}

int main(){
    cin >> n >> m;
    start = clock();
    k[(int)(1e6)] = 1;
    if(n < m) swap(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) mp[i][j] = '.';
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(clock() - start >= CLOCKS_PER_SEC * 6){
            cout << ans << endl;
            return 0;
        }
        dfs(i, 1);
    }
    int c = 0;
    //while(clock() - start < CLOCKS_PER_SEC * 6);
    cout << ans << endl;
}
