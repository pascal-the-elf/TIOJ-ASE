#include "lib1739.h"
#include <iostream>
#include <numeric>
#include <cstdio>
using namespace std;

const int maxN = 622625;

int seg[maxN * 20], lnode[maxN * 20], rnode[maxN * 20], roots[maxN], cnt, N, M, a, b, arr[maxN], Q;
//arr[i]: the number of the marble at arr[i]
//loc[i] the location of the ith marble
int newNode(){
    seg[++cnt] = 0;
    return cnt;
}

void build(int id, int l, int r){
    if(l + 1 == r){
        seg[id] = arr[l];
        return;
    }
    lnode[id] = newNode();
    int m = (l + r) / 2;
    build(lnode[id], l, m);
    rnode[id] = newNode();
    build(rnode[id], m, r);
}

void modify(int lastRoot, int id, int l, int r, int pos, int val){
    if(l + 1 == r){
        seg[id] = val;
        return;
    }
    int m = (l + r) / 2;
    if(pos < m){
        lnode[id] = newNode();
        rnode[id] = rnode[lastRoot];
        modify(lnode[lastRoot], lnode[id], l, m, pos, val);
    } else {
        rnode[id] = newNode();
        lnode[id] = lnode[lastRoot];
        modify(rnode[lastRoot], rnode[id], m, r, pos, val);
    }
}

int query(int id, int l, int r, int pos){
    if(l + 1 == r){
        return seg[id];
    }
    int m = (l + r) / 2;
    if(pos < m){
        return query(lnode[id], l, m, pos);
    } else {
        return query(rnode[id], m, r, pos);
    }
}

int main(){
    roots[0] = 0;
    scanf("%d%d", &N, &M);
    iota(arr, arr + N + 1, 0);
    build(0, 1, N + 1);
    int ra;
    for(int i = 1; i <= M; i++){
        scanf("%d", &a);
        b = a + 1;
        //swap the marbles at
        swap(arr[a], arr[b]);
        /*
        cout << "arr: " << endl;
        for(int i = 1; i <= N; i++){
            cout << arr[i] << " \n"[i == N];
        }
        cout << "loc: " << endl;
        for(int i = 1; i <= N; i++){
            cout << loc[i] << " \n"[i == N];
        }
        */
        ra = newNode();
        modify(roots[2 * i - 2], ra, 1, N + 1, arr[a], a);
        roots[2 * i - 1] = ra;
        ra = newNode();
        modify(roots[2 * i - 1], ra, 1, N + 1, arr[b], b);
        roots[2 * i] = ra;
    }

    Q = getNumQuestions();
    while(Q--){
        getQuestion(a, b);
        answer(query(roots[2 * b], 1, N + 1, a));
    }
}
