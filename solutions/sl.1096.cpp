#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 226, INF = 1e7;

int N, wei[maxN][maxN], minDist[maxN][maxN];

int main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> wei[i][j];
                if(!wei[i][j]) wei[i][j] = INF;
                minDist[i][j] = wei[i][j];
            }
            minDist[i][i] = 0;
        }
        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(i == j || minDist[i][k] == INF || minDist[k][j] == INF) continue;
                    minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                ans = min(ans, minDist[i][j] + minDist[j][i]);
            }
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
}

