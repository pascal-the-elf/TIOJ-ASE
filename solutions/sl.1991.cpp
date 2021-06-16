#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, Q, r1, c1, r2, c2;

int main(){
    ericxiao;
    cin >> N >> M;
    int mp[N + 1][M + 1], vert[N + 1][M + 1], hor[N + 1][M + 1];
    for(int i = 0; i <= N; i++) mp[i][0] = 0;
    for(int i = 0; i <= M; i++) mp[0][i] = 0;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++){
        cin >> mp[i][j];
        vert[i][j] = vert[i - 1][j] + vert[i][j - 1] - vert[i - 1][j - 1] + (mp[i][j] & mp[i - 1][j]);
        hor[i][j] = hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1] + (mp[i][j] & mp[i][j - 1]);
    }
    cin >> Q;
    while(Q--){
        cin >> r1 >> c1 >> r2 >> c2;
        cout << vert[r2][c2] - vert[r2][c1 - 1] - vert[r1][c2] + vert[r1][c1 - 1] + hor[r2][c2] - hor[r2][c1] - hor[r1 - 1][c2] + hor[r1 - 1][c1] << '\n';
    }
}
