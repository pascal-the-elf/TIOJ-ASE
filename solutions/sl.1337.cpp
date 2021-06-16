#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int N, K, l, r, sz;
vector<int> rs[maxN * 2], lis;
vector<pii> segs;

inline bool can(int x){
    multiset<int> st;
    int sc = 0;
    for(int i = 0; i < sz; i++){
        for(int t : rs[i]){
            st.insert(t);
        }
        while(st.size() && *st.begin() == i) st.erase(st.begin());
        while(st.size() > x){
            sc++;
            st.erase(--st.end());
        }
    }
    return sc <= K;
}

int main(){
    ericxiao;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> l >> r;
        segs.emplace_back(l, r);
        lis.push_back(l);
        lis.push_back(r);
    }
    sort(ALL(lis));
    sz = unique(ALL(lis)) - lis.begin();
    for(auto [a, b] : segs){
        a = lower_bound(lis.begin(), lis.begin() + sz, a) - lis.begin();
        b = lower_bound(lis.begin(), lis.begin() + sz, b) - lis.begin();
        rs[a].push_back(b);
    }
    int L = -1, R = N, M;
    while(L + 1 < R){
        M = (L + R) / 2;
        if(can(M)) R = M;
        else L = M;
    }
    cout << R << endl;
}
