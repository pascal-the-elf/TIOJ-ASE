#include <iostream>
#include <vector>
#define li long long
#define int __int128_t
#define vv vector<vector<int>>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int MOD = 4294967296;

inline int add(const int &a, const int &b){
    return (a + b) % MOD;
}

inline void mult(int (&A)[2][2], const int (&B)[2][2]){
    static int C[2][2];
    C[0][0] = add(A[0][0]*B[0][0], A[0][1] * B[1][0]);
    C[0][1] = add(A[0][0]*B[0][1], A[0][1] * B[1][1]);
    C[1][0] = add(A[1][0]*B[0][0], A[1][1] * B[1][0]);
    C[1][1] = add(A[1][0]*B[0][1], A[1][1] * B[1][1]);
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}


li n, a, b, x, y;

signed main(){
    ericxiao;
    while(cin >> n){
        if(n < 0) return 0;
        cin >> a >> b >> x >> y;
        int M[2][2] = {
            {
                (int)0, (int)1
            },
            {
                (int)x, (int)y
            }
        }, T[2][2] = {
            {
                (int)1,(int) 0
            },
            {
                (int)0, (int)1
            }
        };
        //exp to nth power
        for(int i = 0; (1LL << i) <= (n); ++i){
            if(((1LL << i) & (n)) > 0){
                mult(T, M);
            }
            mult(M, M);
        }
        cout << (li)(add(T[0][0]*a, T[0][1] * b)) << '\n';
    }
}
