#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 525, BASE = 1000;

int hei[maxN][maxN], ans = 0, N, M;
bool visited[maxN][maxN];
pii tp, pos, _pos;

pii getPos(int hsh){
    return {hsh / 1000, hsh % 1000};
}

int hsh(int y, int x){
    return y * 1000 + x;
}

bool isValid(int y, int x){
    return (y >= 0 && x >= 0 && y < N && x < M && !visited[y][x]);
}

priority_queue<pii, vector<pii>, greater<pii> > pq;

signed main(){
    ericxiao;
    while(cin >> N >> M){
        ans = 0;
        pq = priority_queue<pii, vector<pii>, greater<pii> >();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> hei[i][j];
                visited[i][j] = false;
                if(!i || !j || i == (N - 1) || j == (M - 1)){
                    visited[i][j] = true;
                    pq.push({hei[i][j], hsh(i, j)});
                    //cout << "Pushing " << i << ", " << j << endl;
                }
            }
        }
        while(pq.size()){
            tp = pq.top();
            pq.pop();
            pos = getPos(tp.S);
            //cout << "Now at " << pos.F << ", " << pos.S << ", val = " << tp.F << endl;
            if(isValid(pos.F + 1, pos.S)){
                visited[pos.F + 1][pos.S] = true;
                if(hei[pos.F + 1][pos.S] > tp.F){
                    pq.push({hei[pos.F + 1][pos.S], hsh(pos.F + 1, pos.S)});
                } else {
                    //cout << "Adding " << pos.F + 1 << ", " << pos.S << endl;
                    pq.push({tp.F, hsh(pos.F + 1, pos.S)});
                    ans += tp.F - hei[pos.F + 1][pos.S];
                }
            }
            if(isValid(pos.F - 1, pos.S)){
                visited[pos.F - 1][pos.S] = true;
                if(hei[pos.F - 1][pos.S] > tp.F){
                    pq.push({hei[pos.F - 1][pos.S], hsh(pos.F - 1, pos.S)});
                } else {
                    //cout << "Adding " << pos.F - 1 << ", " << pos.S << endl;
                    pq.push({tp.F, hsh(pos.F - 1, pos.S)});
                    ans += tp.F - hei[pos.F - 1][pos.S];
                }
            }
            if(isValid(pos.F, pos.S + 1)){
                visited[pos.F][pos.S + 1] = true;
                if(hei[pos.F][pos.S + 1] > tp.F){
                    pq.push({hei[pos.F][pos.S + 1], hsh(pos.F, pos.S + 1)});
                } else {
                    //cout << "Adding " << pos.F << ", " << pos.S + 1 << endl;
                    pq.push({tp.F, hsh(pos.F, pos.S + 1)});
                    ans += tp.F - hei[pos.F][pos.S + 1];
                }
            }
            if(isValid(pos.F, pos.S - 1)){
                visited[pos.F][pos.S - 1] = true;
                if(hei[pos.F][pos.S - 1] > tp.F){
                    pq.push({hei[pos.F][pos.S - 1], hsh(pos.F, pos.S - 1)});
                } else {
                    //cout << "Adding " << pos.F << ", " << pos.S - 1 << endl;
                    pq.push({tp.F, hsh(pos.F, pos.S - 1)});
                    ans += tp.F - hei[pos.F][pos.S - 1];
                }
            }
        }
        cout << ans << '\n';
    }
}
