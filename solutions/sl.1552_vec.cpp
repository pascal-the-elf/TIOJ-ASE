#include <queue>
#include <bitset>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
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


const int maxN = 1e6 + 10;
const int INF = 1e9;

int N, M, u, v, w, from[maxN], ans[maxN], m, tp;
int len[maxN], W;
bitset<maxN> visited, inQ;

class Cmp{
public:
    bool operator()(int i, int j){
        return len[i] > len[j];
    }
};

priority_queue<int, vector<int>, Cmp > pq;

struct Node{
    int v, w;
    Node *next;
    Node(int V, int W): v(V), w(W), next(NULL){}
} *n;

vector<pii> adj[maxN];

int main(){
    Read(N);
    Read(M);
//    fill(adj + 1, adj + 2 + N, LinkedList());

    for(int i = 0; i < M; i++){
        Read(u);
        Read(v);
        Read(w);
        if(u == v) continue;
        adj[u].emplace_back(v, w);
    }
    //return 0;
    fill(len + 1, len + N + 2, INF);
    fill(from, from + N + 2, -1);
    len[1] = 0;
    from[1] = -1;
    pq.push(1);
    inQ[1] = true;
    while(pq.size()){
        tp = pq.top();
        pq.pop();
        if(visited[tp]) continue;
        visited[tp] = true;
//        n = adj[tp].s;
        //cout << "Looking at " << tp.S << endl;
        for(auto [u, w] : adj[tp]){
            if(visited[u]) continue;
            if(len[u] > len[tp] + w){
                len[u] = len[tp] + w;
                from[u] = tp;
                if(!inQ[u]){
                    pq.push(u);
                    inQ[u] = true;
                }
            } else if(len[u] == len[tp] + w){
                if(tp < from[u]){
                    from[u] = tp;
                }
            }
        }
    }
    printf("%d\n", len[N + 1]);
    for(int cur = N + 1; cur != -1; cur = from[cur]){
        ans[m++] = cur;
    }
    for(int i = m - 1; i; i--) printf("%d-", ans[i]);
    printf("%d\n", N + 1);
}


