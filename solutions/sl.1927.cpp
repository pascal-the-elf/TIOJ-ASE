#include <iostream>
#include <utility>
#include <numeric>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 226250, P = 1e9 + 7, K = 5e8 + 3, INF = 1e10;

int arr[maxN], N, Q, l, r, rk[maxN], SA[maxN], LCP[maxN], gap;

struct LCPRMQ{
    int seg[maxN * 2];

    void pull(int id){
        seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
    }

    void build(int id = 0, int l = 0, int r = N){
        if(l + 1 == r){
            seg[id] = LCP[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
        pull(id);
    }

    int query(int id, int l, int r, int ql, int qr){
        if(ql >= r || l >= qr) return INF;
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return min(query(2 * id + 1, l, m, ql, qr), query(2 * id + 2, m, r, ql, qr));
    }

    int getMin(int l, int r){
        if(l > r) swap(l, r);
        return query(0, 0, N, l, r);
    }
} rmq;

int modexp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int r = modexp(b, e/2);
    r = r * r % P;
    if(e % 2) r = r * b % P;
    return r;
}

bool cmp(int i, int j){
    if(rk[i] != rk[j]) return rk[i] < rk[j];
    i += gap;
    j += gap;
    if(i < N && j < N) return rk[i] < rk[j];
    return i > j;
}

inline void init(){
    //SA
    for(int i = 0; i < N; i++) rk[i] = arr[i];
    iota(SA, SA + N, 0);
    int tmp[N + 1];
    for(gap = 1;; gap *= 2){
        sort(SA, SA + N, cmp);
        tmp[SA[0]] = 0;
        for(int i = 1; i < N; i++){
            tmp[SA[i]] = tmp[SA[i - 1]] + cmp(SA[i - 1], SA[i]);
        }
        for(int i = 0; i < N; i++) rk[i] = tmp[i];
        if(rk[SA[N - 1]] == N - 1) break;
    }
    //LCP
    for(int i = 0, k = 0; i < N; i++, k ? k-- : 0){
        if(rk[i] == N - 1){
            k = 0;
            continue;
        }
        int j = SA[rk[i] + 1];
        while(i + k < N && j + k < N && arr[i + k] == arr[j + k]) k++;
        LCP[rk[i]] = k;
    }
    rmq.build();
}

signed main(){
    ericxiao;
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr[i] = modexp(arr[i], K);
        if(arr[i] == P - 1) arr[i] = -1;
    }
    //get SA, LCP, and build seg tree
    init();
    //Checker code:
    /*
    for(int i = 0; i < N; i++){
        cout << "SA[" << i << "] = " << SA[i] << " \n"[i == N - 1];
    }
    for(int i = 0; i < N; i++){
        cout << "LCP[" << i << "] = " << LCP[i] << " \n"[i == N - 1];
    }
    for(int i = 0; i < N; i++){
        cout << "RK[" << i << "] = " << rk[i] << " \n"[i == N - 1];
    }
    */
    //query
    while(Q--){
        cin >> l >> r;
        //RMQ of LCP array from [Rank[l], Rank[r])
        if(l == r) cout << N - l << endl;
        else cout << rmq.getMin(rk[l], rk[r]) << endl;
    }
}
