#include <iostream>
#include <string.h>
#include <unordered_set>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int B = 101, MOD = 1e9 + 7, maxN = 2e5 + 10, B2 = 131, MOD2 = 998244353;

int N, hsh[maxN], hsh2[maxN], exp[maxN], exp2[maxN];
string s;

struct pairHash{
    const int operator()(const pii &p) const {
        return ((p.F ^ p.S) * MOD % MOD2 + p.F * MOD2 % MOD + p.S * maxN % MOD2) % MOD;
    }
};


unordered_set<pii, pairHash> st;

int get(int l, int r){
    return (hsh[r] - hsh[l] * exp[r - l] % MOD + MOD) % MOD;
}

int get2(int l, int r){
    return (hsh2[r] - hsh2[l] * exp2[r - l] % MOD2 + MOD2) % MOD2;
}

bool chk(int x){
    st = unordered_set<pii, pairHash>();
    for(int i = x; i <= N; i++){
        if(st.count({get(i - x, i), get2(i - x, i)})) return true;
        st.insert({get(i - x, i), get2(i - x, i)});
    }
    return false;
}

signed main(){
    cin >> N >> s;
    exp[0] = exp2[0] = 1;
    for(int i = 1; i <= N; i++){
        hsh[i] = (hsh[i - 1] * B % MOD + s[i - 1]) % MOD;
        hsh2[i] = (hsh2[i - 1] * B2 % MOD2 + s[i - 1]) % MOD2;
        exp[i] = exp[i - 1] * B % MOD;
        exp2[i] = exp2[i - 1] * B2 % MOD2;
    }
    int l = 1, r = N, m;
    while(l + 1 < r){
        m = (l + r) / 2;
        if(chk(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

