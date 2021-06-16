#include <iostream>
#include <vector>
#define int long long int
#define vv vector<vector<int>>
using namespace std;

const int MOD = 1e9 + 7;

const vv I = {
    {1, 0},
    {0, 1}
};

inline int add(int a, int b){
    return (a + b >= MOD ?  a + b - MOD : a + b);
}

vv operator *(vv a, vv b){
    vv res;
    res.resize(a.size());
    for(int i = 0; i < a.size(); i++){
        res[i].resize(b[0].size());
        for(int j = 0; j < b[0].size(); j++){
            res[i][j] = 0;
            for(int k = 0; k < a[0].size(); k++){
                res[i][j] = add(res[i][j], a[i][k] * b[k][j] % MOD);
            }
        }
    }
    return res;
}

vv operator ^ (vv b, int e){
    if(!e) return I;
    if(e == 1) return b;
    vv res = b ^ (e / 2);
    res = res * res;
    if(e % 2) res = res * b;
    return res;
}

int x1, x2, a, b, n; //xi = a * x(n - 1) + b * x(n - 2), find x_n

signed main(){
    cin >> x1 >> x2 >> a >> b >> n;
    vv M = {
        {0, 1},
        {a, b},
    }, A = {
        {x1},
        {x2}
    };
    M = M ^ (n - 1);
    A = M * A;
    cout << A[0][0] << endl;
}
