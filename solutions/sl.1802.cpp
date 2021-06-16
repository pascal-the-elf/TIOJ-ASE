#include <cstdio>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int N, anc, sts[maxN], cost[maxN], lastcand, m, root, pos[maxN], last, stsSum, cnt;
vector<int> adj[maxN];

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

void getSts(int p, int u){
    sts[u] = 1;
    for(int v : adj[u]){
        getSts(u, v);
        sts[u] += sts[v];
    }
}

int main(){
    Read(N);
    for(int i = 1; i <= N; i++){
        Read(anc);
        Read(cost[i]);
        pos[cost[i]] = i;
        if(anc == i){
            root = i;
            continue;
        }
        adj[anc].push_back(i);
    }
    getSts(root, root);
    cost[root] = N;
    pos[N] = root;
    for(int toPut = N; toPut; toPut--){
        if(pos[toPut]){
            //cout << toPut << " has been taken" << endl;
            for(int v : adj[pos[toPut]]){
                if(cost[v]) continue;
                lastcand = v;
                m++;
                //cout << "pushing " << v <<endl;
                stsSum += sts[v];
            }
            continue;
        } else {
            if(m == 1){
                cost[lastcand] = toPut;
                pos[toPut] = lastcand;
                m = 0;
                stsSum = 0;
                for(int v : adj[pos[toPut]]){
                    if(cost[v]) continue;
                    lastcand = v;
                    m++;
                    stsSum += sts[v];
                }
                cnt = 0;
            } else {
                ++cnt;
                if(stsSum == cnt){
                    m = 0;
                    stsSum = 0;
                    last = toPut;
                    cnt = 0;
                }
            }
        }
    }
    for(int i = 1; i <= N; i++) printf("%d\n", cost[i]);

}

