#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 55, INF = 2e9;

int arr[maxN][maxN], N, M, sm, ans, me;

int main(){
    ericxiao;
    while(cin >> N >> M){
        ans = me = -INF;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                cin >> arr[i][j];
                me = max(me, arr[i][j]);
                arr[i][j] += arr[i][j - 1];
            }
        }
        for(int l = 0; l < M; l++){
            for(int r = l + 1; r <= M; r++){
                sm = 0;
                for(int i = 1; i <= N; i++){
                    sm = max(0, sm + (arr[i][r] - arr[i][l]));
                    ans = max(ans, sm);
                }
            }
        }
        if(me < 0) cout << me << endl;
        else cout << ans << endl;
    }
}
