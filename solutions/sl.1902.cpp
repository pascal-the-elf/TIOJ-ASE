#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;




const int maxN = 1e5 + 226, maxLog = 30, blockSize = 300, INF = 2e9;
struct YEE{
    int __[2];
    int& operator[](int i){
        return __[i];
    }
}*trie;
//int trie[maxN * maxLog + 226][2];
int arr[maxN], ans[maxN], lRoot, rRoot, ansR, ansL;
int N, Q, l, r;

struct Query{
    int l, r, id;
    Query(int L, int R, int ID): l(L), r(R), id(ID){}
    Query(){}
    bool operator <(Query q) const {
        return r < q.r;
    }
};

vector<Query> queries[maxN];
int cnt;
inline int newMem(){
    trie[++cnt] = {};
    return cnt;
}
inline void Insert(int N, int id){
    bool b;
    for(int layer = maxLog; layer >= 0; layer--){
        b = ((1 << (layer)) & N) > 0;
        if(!trie[id][b]){
            trie[id][b] = newMem();
        }
        id = trie[id][b];
    }
}

inline int getMax(int N, int id){
    bool b;
    int r = 0;
    for(int layer = maxLog; layer >= 0; layer--){
        b = ((1 << (layer)) & N) > 0;
        if(trie[id][b ^ 1]){
            r += (1 << (layer));
            id = trie[id][b ^ 1];
        } else {
            id = trie[id][b];
        }
    }
    return r;
}

signed main(){
    ericxiao;
    cin >> N >> Q;
    trie = new YEE[(N+blockSize) * 100];

    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) arr[i] ^= arr[i - 1];
    for(int i = 0; i < Q; i++){
        cin >> l >> r;
        queries[l / blockSize].emplace_back(l, r, i);
    }
    for(int i = 0; i <= N; i++){
        sort(queries[i].begin(), queries[i].end());
    }
    int R;
    //cout << endl;
    //for(int i = 0; i < N; i++) cout << arr[i] << " ";
    //cout << endl;
    for(int qs = 0; qs <= N; qs++){
        R = (qs + 1) * blockSize;
        ansR = -INF;
        cnt = 0;
        rRoot = newMem();
        for(Query q : queries[qs]){
            //cout << "Doing query: " << q.l << ", " << q.r << endl;
            for(;R <= q.r; R++){
                //cout << "R: inserting " << arr[R] << endl;
                Insert(arr[R], rRoot);
                ansR = max(ansR, getMax(arr[R], rRoot));
            }
            int oldmem = cnt;
            lRoot = newMem();
            ansL = -INF;
            for(int L = min(q.r, (qs + 1) * blockSize - 1); L >= q.l - 1; L--){
                Insert(arr[L], lRoot);
                //cout << "L: inserting " << arr[L] << endl;
                ansL = max(ansL, getMax(arr[L], lRoot));
                ansL = max(ansL, getMax(arr[L], rRoot));
            }
            cnt = oldmem;
            //cout << "ansR = " << ansR << ", ansL = " << ansL << endl;
            ans[q.id] = max(ansL, ansR);
        }
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
}

