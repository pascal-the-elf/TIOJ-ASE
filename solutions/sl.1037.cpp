#include <iostream>
using namespace std;

bool pprev[105][105], now[105][105];

int N, M, X1, Y1, X2, Y2, K, d;

inline int add(int a, int b, int M){
    return (a + b) % M;
}

inline int sub(int a, int b, int M){
    return (a - b + M * 100) % M;
}

int main(){
    cin >> N >> M >> X1 >> Y1 >> X2 >> Y2 >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            pprev[i][j] = now[i][j] = 0;
        }
    }
    pprev[X1][Y1] = true;
    while(K--){
        cin >> d;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                now[i][j] = false;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(pprev[i][j]) now[add(i, d, N)][j] = now[sub(i, d, N)][j] = now[i][add(j, d, M)] = now[i][sub(j, d, M)] = true;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                pprev[i][j] = now[i][j];
            }
            //cout << endl;
        }
        //cout << endl;
    }
    cout << (now[X2][Y2] ? "YES" : "NO") << endl;
}
