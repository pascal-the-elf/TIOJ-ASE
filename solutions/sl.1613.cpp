#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

priority_queue<pii, vector<pii>, greater<pii> > pq;

const int maxN = 1e6, MOD = 1e9 + 7;

int N, p, s = 0, ps[maxN];

/*
PS = P1 + P2
ES = (ES1 * P1 + ES2 * P2) / (P1 + P2) + 1
qK = EK * PK
EK = (ES1 * P1 + ES2 * P2) + PS
= qS1 + qS2 + pS

q is what I want
*/

int modpow(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int r = modpow(b, e/2);
    r = r * r % MOD;
    if(e % 2) r = r * b % MOD;
    return r;
}

int inv(int x){
    return modpow(x, MOD - 2);
}

signed main(){
    scanf("%lld", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &ps[i]);
        s += ps[i];
        pq.push({ps[i], 0});
    }
    pii p1, p2, pp;
    while(pq.size() > 1){
        p1 = pq.top();
        pq.pop();
        p2 = pq.top();
        pq.pop();
        pp.F = p1.F + p2.F;
        pp.S = p1.S + p2.S + pp.F;
        pq.push(pp);
    }
    printf("%lld\n", pq.top().S);
}

