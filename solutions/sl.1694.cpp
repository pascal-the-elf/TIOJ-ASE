#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxN = 23000, maxM = 200000;

int N, M, vals[maxN + 10], bit[maxN + 10], blocks[maxN + 10], _l, _r, _id = 0, Ans[maxM];

struct Query{
    int l, r, id;
    Query(){}
    Query(int l, int r): l(l), r(r), id(_id++){}
} queries[maxM + 10];

bool qCmp(const Query a, const Query b){
    return blocks[a.l] < blocks[b.l] || (blocks[a.l] == blocks[b.l] && a.r < b.r);
}

int lowbit(int x){
    return x & -x;
}

void add(int pos, int val){
    for(; pos <= maxN; pos += lowbit(pos)) bit[pos] += val;
}

int query(int pos){
    int res = 0;
    for(; pos > 0; pos -= lowbit(pos)) res += bit[pos];
    return res;
}

int main(){
    cin >> N >> M;
    int bS = sqrt(N);
    for(int i = 0; i < N; i++) blocks[i] = i/bS + 1; //divide into blcoks
    for(int i = 0; i < N; i++) cin >> vals[i];
    for(int i = 0; i <= N; i++) bit[i] = 0;
    for(int i = 0; i < M; i++){
        cin >> _l >> _r;
        queries[i] = Query(_l - 1, _r - 1);
    }
    sort(queries, queries + M, qCmp);
    //process first item
    int L = 0, R = 0, ans = 0;
    add(vals[0], 1);
    Query cQ;
    for(int i = 0; i < M; i++){
        cQ = queries[i];
        while(R < cQ.r){
            R++;
            add(vals[R], 1);
            ans += query(N) - query(vals[R]);
        }
        while(L > cQ.l){
            L--;
            add(vals[L], 1);
            ans += query(vals[L] - 1);
        }
        while(R > cQ.r){
            //cout << "K" << endl;
            add(vals[R], -1);
            //cout << "Added" << endl;
            ans -= query(N) - query(vals[R]);
            R--;
        }
        while(L < cQ.l){
            add(vals[L], -1);
            ans -= query(vals[L] - 1);
            L++;
        }
        Ans[cQ.id] = ans;
    }
    for(int i = 0; i < M; i++){
        //cout << i << endl;
        cout << Ans[i] << endl;
    }
}
