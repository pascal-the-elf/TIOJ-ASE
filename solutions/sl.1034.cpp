#include <iostream>
using namespace std;

const int maxN = 26, INF = 1e9;

int N, Q, arr[maxN][maxN], dist[maxN][maxN][maxN][maxN];
int x, y, a, b;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    for(int a = 0; a < N; a++)
        for(int b = 0; b < N; b++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    dist[a][b][i][j] = INF;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
             if(i)
                dist[i][j][i - 1][j] = arr[i - 1][j];
            if(j)
                dist[i][j][i][j - 1] = arr[i][j - 1];
            if(i < N - 1)
                dist[i][j][i + 1][j] = arr[i + 1][j];
            if(j < N - 1)
                dist[i][j][i][j + 1] = arr[i][j + 1];
            dist[i][j][i][j] = 0;
        }
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    for(int x = 0; x < N; x++){
                        for(int y = 0; y < N; y++){
                            dist[i][j][x][y] = min(dist[i][j][x][y], dist[i][j][a][b] + dist[a][b][x][y]);
                        }
                    }
                }
            }
        }
    }
    cin >> Q;
    while(Q--){
        cin >> x >> y >> a >> b;
        x--;
        y--;
        a--;
        b--;
        int ans = INF;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans = min(ans, dist[x][y][i][j] + dist[i][j][a][b] - arr[i][j] + arr[x][y]);
            }
        }
        cout << ans << endl;
    }
}
