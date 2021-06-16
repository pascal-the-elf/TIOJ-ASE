#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 10;

int seg[maxN * 2], pri[maxN], sz[maxN], val[maxN], sum[maxN], l[maxN], r[maxN], fat[maxN], cnt = 1, root, seed = 2003;
int N, Q, com, l1, r1, l2, r2, I, J, W, x;

int Rand(){
    return seed = (seed * 3 + 101) % (int)(1e9 + 7);
}
void modify(int p, int x);
int getSum(int l, int r);
int newNode(int v);
void pull(int x);
int Size(int x);
int Sum(int x);
int Merge(int a, int b);
void Split(int o, int &a, int &b, int k);
int getRk(int x);
int getKth(int x);
void updAnc(int x);

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

void disp(int x){
    if(!x) return;
    disp(l[x]);
    cout << val[x] << " ";
    disp(r[x]);
}

void dispid(int x){
    if(!x) return;
    dispid(l[x]);
    cout << x << " ";
    dispid(r[x]);
}

void Swap(int l1, int r1, int l2, int r2){
    int a, b, c, d, e, f, g, h;
    Split(root, a, b, r1);
    Split(a, c, d, l1 - 1);
    Split(b, e, f, r2 - r1);
    Split(e, g, h, l2 - r1 - 1);
    root = Merge(Merge(Merge(c, h), Merge(g, d)), f);
}

int rkSum(int l, int r){
    int a, b, c, d, res;
    Split(root, a, b, r);
    Split(a, c, d, l - 1);
    pull(d);
    res = sum[d];
    root = Merge(Merge(c, d), b);
    return res;
}

signed main(){
    ericxiao;
    Read(N);
    Read(Q);
    for(int i = 1; i <= N; i++){
        Read(x);
        root = Merge(root, newNode(x));
        modify(i, x);
    }
    while(Q--){
        Read(com);
        if(com == 1){ //swap ids I & J
            Read(I);
            Read(J);
            if(I == J) continue;
            int rkI = getRk(I), rkJ = getRk(J);
            if(rkI > rkJ) swap(rkI, rkJ);
            Swap(rkI, rkI, rkJ, rkJ);
        } else if(com == 2){
            Read(I);
            Read(J);
            if(I == J) continue;
            if(I > J) swap(I, J);
            Swap(I, I, J, J);
        } else if(com == 3){
            Read(I);
            Read(W);
            val[I] = W;
            updAnc(I);
            modify(I, W);
        } else if(com == 4){
            Read(I);
            Read(W);
            I = getKth(I);
            val[I] = W;
            updAnc(I);
            modify(I, W);
        } else if(com == 5){
            Read(l1);
            Read(r1);
            Read(l2);
            Read(r2);
            Swap(l1, r1, l2, r2);
        } else if(com == 6){
            Read(I);
            cout << getKth(I) << endl;
        } else if(com == 7){
            Read(I);
            cout << getRk(I) << endl;
        } else if(com == 8){
            Read(l1);
            Read(r1);
            cout << getSum(l1, r1) << endl;
        } else if(com == 9){
            Read(l1);
            Read(r1);
            cout << rkSum(l1, r1) << endl;
        }
        //disp(root);
        //cout << endl;
        //dispid(root);
        //cout << endl;
    }
}

void modify(int p, int x){ //1-based
    for(seg[p += N + 1] = x; p > 1; p >>= 1) seg[p >> 1] = seg[p] + seg[p ^ 1];
}

int getSum(int l, int r){ //[l, r]
    r++;
    int res = 0;
    for(l += N + 1, r += N + 1; l < r; l >>= 1, r >>= 1){
        if(l & 1) res += seg[l++];
        if(r & 1) res += seg[--r];
    }
    return res;
}

int newNode(int v){
    int id = cnt++;
    sz[id] = 1;
    pri[id] = Rand();
    val[id] = sum[id] = v;
    fat[id] = l[id] = r[id] = 0;
    return id;
}

int Size(int x){
    return x ? sz[x] : 0;
}

int Sum(int x){
    return x ? sum[x] : 0;
}

void pull(int x){
    sz[x] = 1 + Size(l[x]) + Size(r[x]);
    sum[x] = val[x] + Sum(l[x]) + Sum(r[x]);
    if(l[x]) fat[l[x]] = x;
    if(r[x]) fat[r[x]] = x;
}

int Merge(int a, int b){
    if(!a || !b) return a ? a : b;
    if(pri[a] < pri[b]){
        r[a] = Merge(r[a], b);
        pull(a);
        pull(b);
        return a;
    } else {
        l[b] = Merge(a, l[b]);
        pull(a);
        pull(b);
        return b;
    }
}

void Split(int o, int &a, int &b, int k){
    if(!o){
        a = b = o;
        return;
    }
    pull(o);
    if(Size(l[o]) >= k){
        b = o;
        Split(l[o], a, l[b], k);
        pull(a);
        pull(b);
    } else {
        a = o;
        Split(r[o], r[a], b, k - Size(l[o]) - 1);
        pull(b);
        pull(a);
    }
}

int getRk(int x){
    int res = 1 + Size(l[x]);
    while(fat[x]){
        if(r[fat[x]] == x){
            res += 1 + Size(l[fat[x]]);
        }
        x = fat[x];
    }
    return res;
}

void updAnc(int x){
    for(; x; x = fat[x]) pull(x);
}

int getKth(int k){
    int cur = root;
    while(true){
        if(k == Size(l[cur]) + 1) return cur;
        if(k <= Size(l[cur])) cur = l[cur];
        else {
            k -= Size(l[cur]) + 1;
            cur = r[cur];
        }
    }
}
