#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int N, x, seed = 101, pri[maxN], sz[maxN], l[maxN], r[maxN], take[maxN], a, b, c, root = 1;

inline int Rand(){
    return seed = (seed * seed + 1) % (0xdefaced);
}

inline int Sz(int x){
    return x ? sz[x] : 0;
}

inline void pull(int x){
    sz[x] = Sz(l[x]) + Sz(r[x]) + 1;
}

void Split(int o, int &a, int &b, int k){
    if(!o){
        a = b = 0;
        return;
    }
    if(Sz(l[o]) + 1 <= k){
        a = o;
        Split(r[o], r[a], b, k - (Sz(l[o]) + 1));
        pull(a);
    } else {
        b = o;
        Split(l[o], a, l[b], k);
        pull(b);
    }
}

int Merge(int a, int b){
    if(!a || !b) return a ? a : b;
    if(pri[a] < pri[b]){
        r[a] = Merge(r[a], b);
        pull(a);
        return a;
    } else {
        l[b] = Merge(a, l[b]);
        pull(b);
        return b;
    }
}

int main(){
    ericxiao;
    while(cin >> N){
        for(int i = N; i; i--) cin >> take[i];
        for(int i = 1; i <= N; i++){
            pri[i] = Rand();
            sz[i] = 1;
        }
        root = 1;
        for(int i = 2; i <= N; i++) root = Merge(root, i); //root = 1
        for(int p = N; p; p--){
            Split(root, a, b, (take[p] - 1) % p);
            Split(b, b, c, 1);
            root = Merge(c, a);
            cout << b << " ";
        }
        cout << endl;
    }
}
