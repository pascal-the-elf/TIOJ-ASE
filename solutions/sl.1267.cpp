#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
//#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
#define gc getchar_unlocked
using namespace std;


int T, N, M, coe, fact[30];

/*
poly[i] is a map of all terms with deg i
exponents of term -> coefficients

app: when each term is sorted,

*/

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void solve(){ //solve for one polynomial
    map<vector<int>, int> poly;
    map<vector<int>, pii> app;
    vector<int> pows;
    scanint(N);
    scanint(M);
    pows.resize(N);
    for(int i = 0; i < M; i++){
        scanint(coe);
        for(int j = 0; j < N; j++){
            scanint(pows[j]);
        }
        poly[pows] += coe;
    }
    for(auto P : poly){
        //cout << "POLY: coe = " << P.S << endl;
        //for(int x : P.F) cout << x << " ";
        //cout << endl;
        vector<int> ps = P.F;
        sort(ps.begin(), ps.end());
        if(!app.count(ps)){
            app[ps].F = P.S;
        }
        if(app[ps].F != P.S){
            printf("%d", 0);
            return;
        } else {
            app[ps].S++;
        }
    }
    for(auto sted : app){
        int frqs[10];
        fill(frqs, frqs + 10, 0);
        for(int x : sted.F) frqs[x]++;
        int occ = fact[N];
        for(int i = 0; i < 10; i++) occ /= fact[frqs[i]];
        if(occ != sted.S.S){
            printf("%d", 0);
            return;
        }
    }
    printf("%d", 1);

}

signed main(){
    fact[0] = 1;
    for(int i = 1; i <= 20; i++) fact[i] = fact[i - 1] * i;
    //ericxiao;
    scanint(T);
    while(T--){
        solve();
    }
}
