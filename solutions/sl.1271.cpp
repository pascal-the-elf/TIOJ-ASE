#include "lib1271.h"
#include <iostream>
#include <vector>
using namespace std;

int R = 1020183129;

vector<int> roots;
int Rand(){
    return R = (R * 5 + 7) % 0xdefaced;
}
struct Node{
    int l, r, sz, pri;
    char c;
    Node(): pri(Rand()), sz(1){}
    Node(char ch): l(0), r(0), c(ch), sz(1), pri(Rand()){}
    Node(int lV, int rV, char ch): l(lV), r(rV), c(ch), sz(1), pri(Rand()){}

};

vector<Node*> nodes;

void pull(Node *&n){
    n->sz = 1;
    if(n->l < nodes.size() && nodes[n->l]) n->sz += nodes[n->l]->sz;
    if(n->r < nodes.size() && nodes[n->r]) n->sz += nodes[n->r]->sz;
}

int Size(Node *n){
    if(!n) return 0;
    return n->sz;
}

inline Node *newNode(Node *o){
    if(!o) return NULL;
    Node *n = new Node();
    n->l = o->l;
    n->r = o->r;
    n->c = o->c;
    n->sz = o->sz;
    n->pri = o->pri;
    return n;
}

void disp(Node *n){
    if(nodes[n->l]) disp(nodes[n->l]);
    cout << n->c;
    if(nodes[n->r]) disp(nodes[n->r]);
}

void showString(){
    disp(nodes[*roots.rbegin()]);
    cout << endl;
}

int Merge(Node *a, Node *b){
    if(!a || !b) {
        nodes.push_back((a ? newNode(a) : newNode(b)));
        return nodes.size() - 1;
    }
    if(a->pri < b->pri){
        Node *na = newNode(a);
        na->l = a->l;
        na->r = Merge(nodes[a->r], b);
        pull(na);
        nodes.push_back(na);
    } else {
        Node *nb = newNode(b);
        nb->r = b->r;
        nb->l = Merge(a, nodes[b->l]);
        pull(nb);
        nodes.push_back(nb);
    }
    return nodes.size() - 1;
}

char getKth(int cur, int k){
    if(Size(nodes[nodes[cur]->l]) >= k){
        return getKth(nodes[cur]->l, k);
    } else if(Size(nodes[nodes[cur]->l]) + 1 == k){
        return nodes[cur]->c;
    } else {
        return getKth(nodes[cur]->r, k - Size(nodes[nodes[cur]->l]) - 1);
    }
}

void Init(){
    vector<Node*>().swap(nodes);
    vector<int>().swap(roots);
    nodes.push_back(NULL);
    roots.push_back(0);
}

void TypeLetter(char c){
    int ind = Merge(nodes[*roots.rbegin()], new Node(c));
    roots.push_back(ind);
    //showString();
}

void UndoCommands(int k){
    roots.push_back(roots[roots.size() - 1 - k]);
    //showString();
}

char GetLetter(int k){
    //disp(nodes[*roots.rbegin()]);
    //cout << endl;
    return  getKth(*roots.rbegin(), k + 1);
    //cout << "Ans = " << ans << endl;
}



