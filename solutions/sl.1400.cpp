#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int seed = 2003;

int Rand(){
    return seed = (2 * seed + 101) % (int)(1e9 + 7);
}

struct Node{
    int val, pri, sz;
    Node *l, *r;
    Node(int v): l(NULL), r(NULL), pri(Rand()), sz(1), val(v){}
} *root = NULL;


void disp(Node *n){
    if(n->l) disp(n->l);
    cout << n->val << " ";
    if(n->r) disp(n->r);
}

inline int Size(Node *n){
    return n ? n->sz : 0;
}

inline void pull(Node *n){
    n->sz = 1 + Size(n->l) + Size(n->r);
}

void Split(Node *o, Node *&a, Node *&b, int k){
    if(!o){
        a = b = NULL;
        return;
    }
    if(o->val <= k){
        a = o;
        Split(o->r, a->r, b, k);
        pull(a);
    } else {
        b = o;
        Split(o->l, a, b->l, k);
        pull(b);
    }
}

Node* Merge(Node *a, Node *b){
    if(!a || !b) return a ? a : b;
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

void Ins(int x){
    Node *a, *b;
    Split(root, a, b, x);
    root = Merge(Merge(a, new Node(x)), b);
}

int getKth(int k){
    Node *cur = root;
    while(true){
        if(k == Size(cur->l) + 1){
            return cur->val;
        }
        if(k <= Size(cur->l)){
            cur = cur->l;
        } else {
            k -= 1 + Size(cur->l);
            cur = cur->r;
        }
    }
}

string com;
int x, cnt, k = 1;

int main(){
    ericxiao;
    while(cin >> com){
        if(com[0] == 'P'){
            cin >> x;
            Ins(x);
            cnt++;
            //disp(root);
            //cout << endl;
        } else if(com[0] == 'G'){
            if(k <= cnt){
                cout << getKth(k) << endl;
                k++;
            }
        } else {
            if(com[1] == 'N'){
                return 0;
            } else {
                root = NULL;
                cnt = 0;
                k = 1;
            }
        }
    }
}
