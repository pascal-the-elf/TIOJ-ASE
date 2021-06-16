#include <iostream>
#include <vector>
#define vv vector<vector<int> >
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
const vv I2 = {
    {1, 0},
    {0, 1}
};

int N, M;

inline int add(int a, int b){
    return (a + b >= MOD ? a + b - MOD : a + b);
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

vv operator*(vv a, vv b){
    vv res;
    res.resize(a.size());
    for(int i = 0; i < a.size(); i++){
        res[i].resize(b[0].size());
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < a[0].size(); k++){
                res[i][j] = add(res[i][j], a[i][k] * b[k][j] % MOD);
            }
        }
    }
    return res;
}

vv operator^(vv b, int e){
    if(!e) return I2;
    vv r = b ^ (e / 2);
    r = r * r;
    if(e % 2) r = r * b;
    return r;
}

inline int fib(int x){
    vv M = {
        {0, 1},
        {1, 1},
    }, A = {
        {0},
        {1}
    };
    A = (M^(x)) * A;
    return A[0][0];
}


signed main(){
    cin >> N >> M;
    int t = gcd(N + 1, M + 1);
    cout << fib(t) << endl;
}

