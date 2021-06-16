#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 500005;

vector<pii> all;
int N, x, y, md = 1e17, sm;
pii ans;

inline int Abs(int x){
    return x >= 0 ? x : -x;
}

inline int dist(pii a, pii b){
    return Abs(a.F - b.F) + Abs(a.S - b.S);
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        all.emplace_back(x, y);
    }
    sort(all.begin(), all.end());
    for(pii p : all){
        sm = 0;
        for(pii q : all){
            sm += dist(p, q);
        }
        if(sm < md){
            md = sm;
            ans = p;
        }
    }
    cout << ans.F << " " << ans.S << endl;
    cout << md << endl;
}
