#include <iostream>
#include <vector>
#define int long long int
#define vv vector<vector<int>>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MOD = 1e9 + 7;

int N, a, b;

inline int add(int a, int b){
    return (a + b > MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
    return (a - b < 0 ? a - b + MOD : a - b);
}

vv I = {{1, 0}, {0, 1}}, M = {{0, 1}, {1, 1}}, R = {{0}, {1}};

vv operator*(vv a, vv b){
    vv r;
    r.resize(a.size());
    for(int i = 0; i < a.size(); i++){
        r[i].resize(b[0].size());
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < a[0].size(); k++){
                r[i][j] = add(r[i][j], a[i][k] * b[k][j] % MOD);
            }
        }
    }
    return r;
}

vv expmod(vv b, int e){
    if(!e) return I;
    if(e == 1) return b;
    vv r = expmod(b, e/2);
    r = r * r;
    if(e % 2) r = r * b;
    return r;
}

inline int getFib(int i){
    return (expmod(M, i) * R)[0][0];
}

inline int getPre(int i){
    return sub(getFib(i) * getFib(i + 1) % MOD, getFib(i + 2));
}

signed main(){
    ericxiao;
    cin >> N;
    while(N--){
        cin >> a >> b;
        cout << sub(getPre(b), getPre(a - 1)) * 500000004 % MOD << '\n';
    }

}
