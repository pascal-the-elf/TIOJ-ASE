#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>
#include <queue>
#define F first
#define S second
#define pii pair<int,int>
#define piii pair<pair<int, int>, int>
#define edge(a,b,c) {{a,b},c}
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
//#define int long long int
using namespace std;

const int maxN = 3e5 + 10;
vector<piii> edges;
vector<pii> queries;
vector<int> ans, dsu, tmp;
int n, edgcnt, a, b, d, t, q, maxD = 0;

struct Que{
    int l, r;
    vector<int> que;
    Que(){}
    Que(int L, int R, vector<int> Q): l(L), r(R), que(Q){}
};

void init();
void Merge(int a, int b);
void Flat(int a);

queue<Que> ques;

signed main(){
    ericxiao;
    cin >> n >> edgcnt;
    dsu.resize(n + 2);
    for(int i = 0; i < edgcnt; i++){
        cin >> a >> b >> d;
        maxD = max(maxD, d);
        edges.push_back(edge(a,b,d));
    }
    sort(edges.begin(), edges.end(), [](piii a, piii b){ return a.S < b.S; });
    cin >> q;
    queries.resize(q);
    ans.resize(q);
    fill(ans.begin(), ans.end(), -1);
    tmp.resize(q);
    iota(tmp.begin(), tmp.end(), 0);
    for(int i = 0; i < q; i++){
        cin >> queries[i].F >> queries[i].S;
    }
    ques.push(Que(0, maxD + 1, tmp));
    int cM = 0, m;
    vector<int> lft, rt;
    Que q;
    init();
    while(ques.size()){
        q = ques.front();
        ques.pop();

        //cout << "The ids: " << endl;
        //for(int u : q.que) cout << u << " ";
        //cout << endl;
        //cout << "Have an ans between " << q.l << " and " << q.r << endl;

        if(q.l == q.r){
            for(int u : q.que) ans[u] = q.l;
            continue;
        }
        m = (q.l + q.r) / 2;
        //cout << "m = " << m << endl;
        if(cM && edges[cM - 1].S > m){
            //cout << "Init" << endl;
            init();
            cM = 0;
        }
        while(edges[cM].S <= m && cM < edgcnt){
            //cout << "Merging " << edges[cM].F.F << " " << edges[cM].F.S << endl;
            Merge(edges[cM].F.F, edges[cM].F.S);
            cM++;
        }
        lft.clear();
        rt.clear();
        for(int qi : q.que){
            Flat(queries[qi].F);
            Flat(queries[qi].S);
            if(dsu[queries[qi].F] == dsu[queries[qi].S]) lft.emplace_back(qi);
            else rt.emplace_back(qi);
        }
        if(lft.size()) ques.push(Que(q.l, m, lft));
        if(rt.size()) ques.push(Que(m + 1, q.r, rt));
    }
    for(int a : ans){
        if(a > maxD) cout << -1 << '\n';
        else cout << a << '\n';
    }
}

void init(){
    iota(dsu.begin(), dsu.end(), 0);
}

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    dsu[dsu[a]] = dsu[b];
}
