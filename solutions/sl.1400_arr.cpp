#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


const int maxN = 4e5 + 226;

int seed = 2003;

inline int Rand(){
    return seed = (seed * 3 + 101) % (int)(1e9 + 7);
}

string com;
int val[maxN], pri[maxN], l[maxN], r[maxN], sz[maxN], cnt, k = 1, root, x, num;

inline int newNode(int v){
    int o = cnt++;
    val[o] = v;
    pri[o] = Rand();
    l[o] = r[o] = -1;
    sz[o] = 1;
    return o;
}

void disp(int x){
    if(!(~x)) return;
    disp(l[x]);
    cout << val[x] << " ";
    disp(r[x]);
}

inline int Size(int x){
    return ~x ? sz[x] : 0;
}

inline void pull(int x){
    sz[x] = 1 + Size(l[x]) + Size(r[x]);
}

void Split(int o, int &a, int &b, int k){
    if(!(~o)){
        a = b = -1;
        return;
    }
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

int Merge(int a, int b){
    if(!(~a) || !(~b)) return ~a ? a : b;
    if(pri[a] < pri[b]){
        r[a] = Merge(r[a], b);
        pull(a);
        return a;
    } else {
        l[b] = Merge(a, l[b]);
        pull(b);
        return b;
    }
}

void Ins(int x){
    int a, b;
    Split(root, a, b, x);
    root = Merge(Merge(a, newNode(x)), b);
}

void Reset(){
    root = -1;
    cnt = 0;
    k = 1;
    num = 0;
}

int getKth(int k){
    int cN = root;
    while(true){
        if(k == Size(l[cN]) + 1) return val[cN];
        else if(k <= Size(l[cN])){
            cN = l[cN];
        } else {
            k -= Size(l[cN]) + 1;
            cN = r[cN];
        }
    }
}


int main(){
    ericxiao;
    Reset();
    while(cin >> com){
        if(com[0] == 'P'){
            cin >> x;
            Ins(x);
            num++;
            //disp(root);
            //cout << endl;
        } else if(com[0] == 'G'){
            if(k <= num){
                cout << getKth(k) << endl;
                k++;
            }
        } else {
            if(com[1] == 'N') return 0;
            Reset();
        }
    }
}
