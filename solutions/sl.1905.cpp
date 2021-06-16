#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10, INF = 1e9 + 10;

int N, Q, l, r, arr[maxN], ans[maxN], toAns = 0, sz, currentId, nxtVal;
vector<int> lisan;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

struct ZCK{
    int seg[maxN * 2];
    ZCK(){
        fill(seg, seg + 2 * maxN, INF);
    }
    void modify(int p, int x){
        p += N;
        seg[p] = min(seg[p], x);
        for(; p; p >>= 1) seg[p >> 1] = min(seg[p], seg[p ^ 1]);
    }
    int query(int l, int r){ //[l, r)
        if(l >= r) return INF;
        int res = INF;
        for(l += N, r += N; l < r; l >>= 1, r >>= 1){
            if(l & 1) res = min(res, seg[l++]);
            if(r & 1) res = min(res, seg[--r]);
        }
        return res;
    }
} vals, ansvals;

struct Query{
    int l, r, id;
    Query(){}
    Query(int L, int R, int I): l(L), r(R), id(I){}
    const bool operator<(const Query &q) const {
        return l > q.l;
    }
} queries[maxN];

int main(){
    //ericxiao;
    Read(N);
    for(int i = 1; i <= N; i++){
        Read(arr[i]);
        lisan.push_back(arr[i]);
    }
    sort(lisan.begin(), lisan.end());
    sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
    for(int i = 1; i <= N; i++){
        arr[i] = lower_bound(lisan.begin(), lisan.begin() + sz, arr[i]) - lisan.begin();
        //cout << arr[i] << " ";
    }
    //cout << endl;
    Read(Q);
    for(int i = 0; i < Q; i++){
        Read(l);
        Read(r);
        queries[i] = Query(l, r, i);
    }
    sort(queries, queries + Q);
    for(int i = N; i; i--){
        //update

        currentId = vals.query(arr[i], N);
        while(currentId != INF){
            ansvals.modify(currentId, lisan[arr[currentId]] - lisan[arr[i]]);
            nxtVal = upper_bound(lisan.begin(), lisan.begin() + sz, (lisan[arr[currentId]] + lisan[arr[i]]) / 2) - lisan.begin() - 1;
            currentId = vals.query(arr[i] + 1, nxtVal + 1);
        }

        currentId = vals.query(0, arr[i] + 1);
        while(currentId != INF){
            ansvals.modify(currentId, lisan[arr[i]] - lisan[arr[currentId]]);
            nxtVal = upper_bound(lisan.begin(), lisan.begin() + sz, (lisan[arr[currentId]] + lisan[arr[i]]) / 2) - lisan.begin();
            currentId = vals.query(nxtVal, arr[i] + 1);
        }

        vals.modify(arr[i], i);
        //for each query get answer
        while(toAns < Q && queries[toAns].l == i){
            ans[queries[toAns].id] = ansvals.query(queries[toAns].l, queries[toAns].r + 1);
            toAns++;
        }
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
}
