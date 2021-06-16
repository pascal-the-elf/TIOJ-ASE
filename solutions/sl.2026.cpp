#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int seed = 1;

int rand(){
    return seed = seed * 1013 + 2147;
}

struct Node{
    int v, sz, pri;
    Node *l, *r;
    Node(){}
    Node(int v): v(v), pri(rand()), sz(1){}
} *root = NULL;

void show(Node *n){
    if(!n) return;
    show(n->l);
    cout << n->v << " ";
    show(n->r);
}

int Size(Node*n){
    return !n ? 0 : n->sz;
}

void pull(Node *&n){
    n->sz = 1 + Size(n->l) + Size(n->r);
}

Node* Merge(Node *a, Node *b){
    if(!a || !b) return a ? a : b;
    pull(a);
    pull(b);
    if(a->pri < b->pri){
        a->r = Merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = Merge(a, b->l);
        pull(b);
        return b;
    }
}

void Split(Node *o, Node *&a, Node *&b, int k){ //split by value
    if(!o){
        a = b = NULL;
        return;
    }
    pull(o);
    if(o->v < k){
        a = o;
        Split(o->r, a->r, b, k);
        pull(a);
    } else {
        b = o;
        Split(o->l, a, b->l, k);
        pull(b);
    }
}

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

int getKth(Node *o, int k){
    //cout << "GetKth of " << o->v << ", k = " << k << endl;
    if(Size(o->l) == k - 1){
        return o->v;
    }
    if(Size(o->l) + 1 > k) return getKth(o->l, k);
    else return getKth(o->r, k - Size(o->l) - 1);
}

void Insert(Node *&r, int v){
    Node *a, *b = new Node(v), *c;
    Split(r, a, c, v);
    r = Merge(Merge(a, b), c);
}

int Q, c, x, sz = 0;

int main(){
    ericxiao;
    input(Q);
    while(Q--){
        input(c);
        if(c == 1){
            input(x);
            if(!root) root = new Node(x);
            else Insert(root, x);
            sz++;
        } else if(c == 2){
            cout << getKth(root, (sz + 1) / 2) << '\n';
        } else show(root);
    }
}
