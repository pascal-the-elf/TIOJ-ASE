#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, blockSize = 500;

int frq[maxN], howMany[maxN], ans = 0, res[maxN];

inline void add(int x){
    howMany[frq[x]]--;
    frq[x]++;
    howMany[frq[x]]++;
    ans = max(ans, frq[x]);
}

inline void sub(int x){
    howMany[frq[x]]--;
    frq[x]--;
    howMany[frq[x]]++;
    if(!howMany[ans]) ans--;
}

struct Query{
    int l, r, id;
    Query(){}
    Query(int l, int r, int id): l(l), r(r), id(id){}
    bool operator<(const Query q) const {
        return (l / blockSize == q.l / blockSize) ? r < q.r : l / blockSize < q.l / blockSize;
    }
};

vector<Query> queries;

int N, Q, arr[maxN], l, r;

int main(){
    ericxiao;
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < Q; i++){
        cin >> l >> r;
        queries.emplace_back(l - 1, r, i);
    }
    sort(queries.begin(), queries.end());
    int L = 0, R = 1;
    add(arr[0]);
    for(Query q : queries){
        while(L > q.l) add(arr[--L]);
        while(R < q.r) add(arr[R++]);
        while(L < q.l) sub(arr[L++]);
        while(R > q.r) sub(arr[--R]);
        res[q.id] = ans;
    }
    for(int i = 0; i < Q; i++) cout << res[i] << '\n';
}
