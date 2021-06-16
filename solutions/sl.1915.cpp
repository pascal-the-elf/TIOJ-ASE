#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 10;

int T, N, M, u, v;
vector<int> adj[maxN], deg, fa;

struct Cmp{
    bool operator()(pii a, pii b){
        return (a.S == b.S) ? a.F < b.F : a.S < b.S;
    }
};

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++) vector<int>().swap(adj[i]);
        fa = deg = vector<int>(N);
        int _ans = 0, ans = 0, tp;
        set<pii, Cmp> st;
        for(int i = 0; i < M; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
            if(u > v) fa[v]++;
            else fa[u]++;
            _ans = max(_ans, max(fa[u], fa[v]));
        }
        for(int i = 0; i < N; i++){
            st.insert({i, deg[i]});
        }
        //cout << "SZ = " << st.size() << endl;
        int cn, dg;
        for(int i = 0; i < N; i++){
            auto it = st.begin();
            cn = it->F, dg = it->S;
            st.erase(it);
            //cout << "Taking " << cn << " with deg " << dg << endl;
            ans = max(ans, dg);
            for(int u : adj[cn]){
                //cout << "Trying to find " << u << endl;
                auto _it = st.find({u, deg[u]});
                if(_it == st.end()) continue;
                deg[u]--;
                //cout << "Updating " << u << " now deg = " << deg[u] << endl;
                st.erase(_it);
                st.insert({u, deg[u]});
            }
            //cout << "E" << endl;
        }
        cout << _ans << " " << ans << endl;
    }
}
