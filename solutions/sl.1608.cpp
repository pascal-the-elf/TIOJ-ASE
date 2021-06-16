#include <iostream>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

//S  UDLR
//-1 0123
const int maxN = 1e3 + 10;
int mp[maxN][maxN], dirs[maxN][maxN], N, M, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, maxV, cDir, globMax = -(1 << 30) - 5;
bool canGo[maxN][maxN], visited[maxN][maxN];
bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < N && j < M;
}



queue<int> que;

int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
        cin >> mp[i][j];
        globMax = max(globMax, mp[i][j]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            maxV = mp[i][j];
            if(mp[i][j] == globMax){
                canGo[i][j] = true;
                visited[i][j] = true;
                que.push(i * maxN + j);
            }
            cDir = -1;
            for(int d = 0; d < 4; d++){
                if(isValid(i + dy[d], j + dx[d]) && mp[i + dy[d]][j + dx[d]] > maxV){
                    maxV = mp[i + dy[d]][j + dx[d]];
                    cDir = d;
                }
            }
            dirs[i][j] = cDir;
        }
    }

    int pos, i, j;
    while(que.size()){
        pos = que.front();
        que.pop();
        i = pos / maxN;
        j = pos % maxN;
        for(int d = 0; d < 4; d++){
            if(isValid(i + dy[d], j + dx[d]) && !canGo[i + dy[d]][j + dx[d]] && (dirs[i + dy[d]][j + dx[d]] ^ 1) == d){
                canGo[i + dy[d]][j + dx[d]] = true;
                que.push((i + dy[d]) * maxN + (j + dx[d]));
            }
        }
    }
    int ans = N * M;
    /*
    for(int i = 0; i < N ;i++){
        for(int j = 0; j < M; j++){
            cout << dirs[i][j] << " \n"[j == M -  1];
        }
    }
    */
    //cout << endl;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
        //cout << canGo[i][j] << " \n"[j == M - 1];
        ans -= (canGo[i][j]);
    }
    cout << ans << endl;
}
