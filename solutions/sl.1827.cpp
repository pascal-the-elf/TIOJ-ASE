#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int seg[maxN * 50], roots[maxN], lft[maxN], rgt[maxN], cnt;
int N, M, arr[maxN], P, K;

inline int newMem(){
    seg[cnt] = 0;
    return cnt++;
}

void build(int l, int r){
    int id = newMem();
    if(l + 1 < r){
        int m = (l + r) / 2;
        lft[id] = build(l, m);
        rgt[id] = build(m, r);
    }
}

void pull(int id){

}

int modify(int ori, int l, int r, int pos){
    int id = newMem();
    if(l + 1 == r){
        seg[id] = seg[ori] + 1;
    } else {
        int m = (l + r) / 2;
        if(pos < m){

        } else {

        }
    }
}

int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    build(0, N);
    roots[0] = 0;
    for(int i = 1; i <= N; i++){

    }
}
