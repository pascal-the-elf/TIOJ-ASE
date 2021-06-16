#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#define ericxiao() ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 5e5, maxM = 1e5;
int N, M, vals[maxN + 10], actual[maxN + 10], bC, _id  = 0, ans, _l, _r, _k, blocks[maxN + 10], howmany[maxN + 10], freqs[maxN + 10];
bool Ans[maxM + 10];
map<int, int> p;
struct Query{
    int l, r, k, id;
    Query(){}
    Query(int l, int r, int k):l(l), r(r), k(k), id(_id++){}
} queries[maxM + 10];

bool qCmp(const Query &a, const Query &b){
    return (blocks[a.l] < blocks[b.l] || (blocks[a.l] == blocks[b.l] && a.r < b.r));
}

inline void add(int val){
    howmany[freqs[val]]--;
    freqs[val]++;
    howmany[freqs[val]]++;
    ans = max(freqs[val], ans);
}

inline void sub(int val){
    howmany[freqs[val]]--;
    freqs[val]--;
    howmany[freqs[val]]++;
    if(ans == freqs[val] + 1 && howmany[freqs[val] + 1] == 0) ans = freqs[val];
}

signed main(){
    ericxiao();
    cin >> N >> M;
    bC = 200; //this might be good
    for(int i = 0; i < N; i++) {
        cin >> vals[i];
        actual[i] = vals[i];
        blocks[i] = i/bC + 1;
    }
    sort(actual, actual + N);
    int k = 1;
    p.insert({actual[0], 1});
    for(int i = 1; i < N; i++){
        if(actual[i] != actual[i-1]) p.insert({actual[i], ++k});
    }
    for(int i = 0; i < N; i++) vals[i] = p[vals[i]];
    for(int i = 0; i < M; i++){
        cin >> _l >> _r >> _k;
        queries[i] = Query(_l - 1, _r - 1, _k);
    }
    sort(queries, queries + M, qCmp);
    int L = 1, R = 0;
    ans = 0;
    Query cQ;
    for(int i = 0; i < M; i++){
        cQ = queries[i];
        while(R < cQ.r){
            add(vals[++R]);
        }
        while(L > cQ.l){
            add(vals[--L]);
        }
        while(R > cQ.r){
            sub(vals[R--]);
        }
        while(L < cQ.l){
            sub(vals[L++]);
        }
        //printf("The answer for (%d, %d) = %d\n", cQ.l, cQ.r, ans);
        Ans[cQ.id] = ((cQ.r - cQ.l + 1.0)/cQ.k <= ans);
    }

    for(int i = 0; i < M; i++)
        cout << (Ans[i] ? "Yes" : "No") << endl;

}
