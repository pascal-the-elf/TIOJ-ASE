#include <iostream>
#include <string.h>
using namespace std;

int dir[8][2] = {
    {-1 ,-1},
    {-1 , 0},
    {-1 , 1},
    { 0 ,-1},
    { 0 , 1},
    { 1 ,-1},
    { 1 , 0},
    { 1 , 1}
}, lvls[11] = {
    0, 1, 2, 4, 6, 10, 12, 14, 16, 18, (1 << 20)
};

int N, M;
string s;

int mp[512][512], cc;

inline bool isValid(int i, int j){
    return (i >= 0 && j >= 0 && i < N && j < M && mp[i][j] == 1);
}

void dfs(int i, int j){
    mp[i][j] = 2;
    for(int d = 0; d < 8; d++){
        if(isValid(i + dir[d][0], j + dir[d][1])){
            dfs(i + dir[d][0], j + dir[d][1]);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            mp[i][j] = s[j] - '0';
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mp[i][j] == 1){
                cc++;
                dfs(i, j);
            }
        }
    }
    cout << lower_bound(lvls, lvls + 11, cc) - lvls << endl;
}
