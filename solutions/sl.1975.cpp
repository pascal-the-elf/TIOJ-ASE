#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 1e6 + 226;

int val[maxN], l[maxN], r[maxN], amnt[maxN], sz[maxN], tag[maxN], pri[maxN], seed = 101, cnt = 2, root = 1;

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


inline int Rand(){
    return seed = (seed * seed + 1) % (0xdefaced);
}

inline int newNode(int v, int _amnt){
    int o = cnt++;
    val[o] = v;
    amnt[o] = sz[o] = _amnt;
    tag[o] = 0;
    pri[o] = Rand();
    l[o] = r[o] = 0;
    return o;
}

inline int Amnt(int x){
    return x ? amnt[x] : 0;
}

inline int Sz(int x){
    return x ? sz[x] : 0;
}

inline void pull(int x){
    sz[x] = Sz(l[x]) + Sz(r[x]) + Amnt(x);
}

inline void push(int x){
    val[x] += tag[x];
    if(l[x]) tag[l[x]] += tag[x];
    if(r[x]) tag[r[x]] += tag[x];
    tag[x] = 0;
}

int Merge(int a, int b){
    if(a) push(a);
    if(b) push(b);
    if(!a || !b) return a ? a : b;
    if(pri[a] < pri[b]){
        r[a] = Merge(r[a], b);
        pull(a);
        return a;
    }
    l[b] = Merge(a, l[b]);
    pull(b);
    return b;
}

void Split(int o, int &a, int &b, int k){ //key <= k
    if(!o){
        a = b = 0;
        return;
    }
    push(o);
    if(val[o] <= k){
        a = o;
        Split(r[o], r[a], b, k);
        pull(a);
    } else {
        b = o;
        Split(l[o], a, l[b], k);
        pull(b);
    }
}

int rkNum(int o, int k){ //returns the kth num
    push(o);
    if(Sz(l[o]) >= k) return rkNum(l[o], k);
    if(k <= Sz(l[o]) + Amnt(o)) return val[o];
    return rkNum(r[o], k - Sz(l[o]) - Amnt(o));
}

bool add(int o, int k, int v){ //add v to node with key k
    if(!o) return false;
    push(o);
    bool rt;
    if(val[o] == k){
        amnt[o] += v;
        rt = true;
    } else if(val[o] < k){
        rt = add(r[o], k, v);
    } else {
        rt = add(l[o], k, v);
    }
    pull(o);
    return rt;
}

void Insert(int &o, int k, int v){
    if(add(o, k, v)) return;
    int a, b, c;
    Split(o, a, b, k);
    o = Merge(a, Merge(newNode(k, v), b));
}

void Use(int k){
    //cout << "Going to use " << k << " numbers" << endl;
    int r = rkNum(root, k), a, b, c, d; //r is kth num
    Split(root, a, b, r);
    Split(a, c, d, r - 1);
    //c d b
    if(c){
        push(c);
        tag[c]++;
        push(c);
    }
    int lftSz = k - Sz(c), rgtSz = Sz(d) - lftSz;
    Insert(b, r + 1, lftSz);
    if(rgtSz) Insert(c, r, rgtSz);
    root = Merge(c, b);
}

void disp(int o){
    if(!o) return;
    push(o);
    disp(l[o]);
    cout << val[o] << ", " << amnt[o] << "/";
    disp(r[o]);
}

int N, M, s, e, w, d, diff[maxN];
vector<int> dyn[maxN];
int main(){
    Read(N);
    for(int i = 0; i < N; i++){
        Read(s);
        Read(e);
        diff[s]++;
        diff[e + 1]--;
    }
    for(int i = 1; i < maxN; i++) diff[i] += diff[i - 1];
    Read(M);
    for(int i = 0; i < M; i++){
        Read(w);
        Read(d);
        dyn[d].push_back(w);
    }
    for(int t = 1; t < maxN; t++){
        Insert(root, diff[t], 1);
        //cout << "Time = " << t << ", root = " << root << endl;
        //disp(root);
        //cout << endl;
        for(int req : dyn[t]){
            Use(req);
            //disp(root);
            //cout << endl;
        }
    }
    while(r[root]){
        push(root);
        root = r[root];
    }
    printf("%d\n", val[root]);
}
