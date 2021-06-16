#pragma GCC optimize ("Ofast")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10, maxCnt = 1e6 + 2 * maxN;

int T, N, M, s1, t1, s2, t2, cnt, a[maxN], sz, indeg[maxCnt];
long long int longest[maxCnt];
map<pii, int> id;
vector<int> pos[maxCnt];
vector<pii> adj[maxCnt];
queue<int> que;

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

inline void solve(){
    Read(N);
    Read(M);

    cnt = 0;
    id = map<pii, int>();
    for(int i = 1; i <= N; i++){
        Read(a[i]);
    }
    cnt = 0;
    for(int i = 1; i <= N; i++){
        pos[i].push_back(   1);
        pos[i].push_back(a[i]);
        longest[cnt] = 1;
        id[{i,    1}] = cnt++;
        id[{i, a[i]}] = cnt++;
    }
    for(int i = 0; i < M; i++){
        Read(s1);
        Read(t1);
        Read(s2);
        Read(t2);
        if(!id.count({s1, t1})){
            pos[s1].push_back(t1);
            id[{s1, t1}] = cnt++;
        }
        if(!id.count({s2, t2})){
            pos[s2].push_back(t2);
            id[{s2, t2}] = cnt++;
        }
        adj[id[{s1, t1}]].emplace_back(id[{s2, t2}], 1);
        indeg[id[{s2, t2}]]++;
    }




    //for(auto x : id){
    //    cout << x.F.F << ", " << x.F.S << " -> " << x.S << endl;
    //}
    for(int i = 1; i <= N; i++){
        sort(pos[i].begin(), pos[i].end());
        sz = unique(pos[i].begin(), pos[i].end()) - pos[i].begin();
        for(int j = 0; j < sz - 1; j++){
            adj[id[{i, pos[i][j]}]].emplace_back(id[{i, pos[i][j + 1]}], pos[i][j + 1] - pos[i][j]);
            indeg[id[{i, pos[i][j + 1]}]]++;
        }
    }
    que = queue<int>();
    for(int i = 0; i < cnt; i++) if(!indeg[i]) que.push(i);
    long long int c = 0, ans = 0, t;
    while(que.size()){
        c++;
        t = que.front();
        que.pop();
        ans = ans > longest[t] ? ans : longest[t];
        //cout << "t =  " << t << endl;
        for(pii v : adj[t]){
            indeg[v.F]--;
            longest[v.F] = longest[v.F] > longest[t] + v.S ? longest[v.F] : longest[t] + v.S;
            if(!indeg[v.F]) que.push(v.F);
        }
    }
    if(c < cnt) printf("LoveLive!\n");
    else printf("%lld\n", ans);

    fill(longest, longest + cnt, 0);
    for(int i = 0; i < cnt; i++){
        vector<pii>().swap(adj[i]);
        vector<int>().swap(pos[i]);
    }
    fill(indeg, indeg + cnt, 0);
}

signed main(){
    Read(T);
    while(T--){
        solve();
    }
}
