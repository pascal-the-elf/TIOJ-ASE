#include <iostream>
#include <vector>
#define vv vector<vector<int> >
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1024;
int seed = 1428571, MOD = 1e9 + 7;

int Rand(){
    return seed = (seed * 7 + 13) % (MOD);
}

int T, N, A[maxN][maxN], B[maxN][maxN], C[maxN][maxN], X[maxN], CX[maxN], BX[maxN], ABX[maxN];

inline bool solve(){
    cin >> N;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
        cin >> A[i][j];
        A[i][j] = (A[i][j] + MOD) % MOD;
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
        cin >> B[i][j];
        B[i][j] = (B[i][j] + MOD) % MOD;
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
        cin >> C[i][j];
        C[i][j] = (C[i][j] + MOD) % MOD;
    }
    for(int trial = 0; trial < 1; trial++){
        seed = Rand();
        for(int i = 0; i < N; i++){
            X[i] = Rand();
        }
        for(int i = 0; i < N; i++){
            BX[i] = 0;
            for(int j = 0; j < N; j++){
                BX[i] = (BX[i] + B[i][j] * X[j] % MOD) % MOD;
            }
        }
        for(int i = 0; i < N; i++){
            ABX[i] = 0;
            for(int j = 0; j < N; j++){
                ABX[i] = (ABX[i] + A[i][j] * BX[j] % MOD) % MOD;
            }
        }
        for(int i = 0; i < N; i++){
            CX[i] = 0;
            for(int j = 0; j < N; j++){
                CX[i] = (CX[i] + C[i][j] * X[j] % MOD) % MOD;
            }
        }
        for(int i = 0; i < N; i++){
            if(CX[i] != ABX[i]) return false;
        }
    }
    return true;
}

signed main(){
    ericxiao;
    cin >> T;
    while(T--){
        if(solve()){
            cout << "Loli is god.\n";
        } else {
            cout << "QAQ!\n";
        }
    }
}
