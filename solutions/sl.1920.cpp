#include <iostream>
#include <queue>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 10, maxQ = 1e6 + 10;

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

struct Node{
    Node *child[2];
    int mxIndex;

    Node(){
        child[0] = child[1] = NULL;
        mxIndex = 0;
    }
} *root;

struct Query{
    int l, v, id;
    Query(){}
    Query(int l, int v, int id): l(l), v(v), id(id){}
};

vector<Query> queries[maxN];

int pre[maxN], l, r, v, N, Q, ans[maxQ];

bool getBit(int i, int j){
    return ((i >> j) & 1);
}

void Insert(int x, int id){
    Node *cur = root;
    for(int lv = 30; lv >= 0; lv--){
        cur->mxIndex = max(cur->mxIndex, id);
        if(!cur->child[getBit(x, lv)]) cur->child[getBit(x, lv)] = new Node();
        cur = cur->child[getBit(x, lv)];
    }
    cur->mxIndex = max(cur->mxIndex, id);
}

int getMax(int x, int l){
    Node *cur = root;
    int res = 0;
    for(int lv = 30; lv >= 0; lv--){
        if(cur->child[getBit(x, lv) ^ 1] && cur->child[getBit(x, lv) ^ 1]->mxIndex >= l){
            res += (1 << lv);
            cur = cur->child[getBit(x, lv) ^ 1];
        } else {
            cur = cur->child[getBit(x, lv)];
        }
    }
    return res;
}

int main(){
    root = new Node();
    Read(N);
    Read(Q);
    for(int i = 1; i <= N; i++){
        Read(pre[i]);
        pre[i] ^= pre[i - 1];
    }
    for(int i = 0; i < Q; i++){
        Read(l);
        Read(r);
        Read(v);
        queries[r].emplace_back(l, v, i);
    }

    for(int i = 0; i <= N; i++){
        for(Query q : queries[i]){
            ans[q.id] = getMax(q.v ^ pre[i], q.l);
        }
        Insert(pre[i], i);
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << endl;
}


