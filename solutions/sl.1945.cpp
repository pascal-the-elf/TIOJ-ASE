#include <iostream>
#include "lib1945.h"
using namespace std;

const int maxN = 131072;

int que[maxN + 10], pre[maxN], res[maxN];

inline bool getPre(int l, int r){
    return pre[r] ^ (l > 0 ? pre[l - 1] : 0);
}

int main(){
    Init();
    for(int i = 0; i < maxN; i++){
        que[0] = i;
        pre[i] = Query(1, que);
        res[i] = pre[i];
        if(i) pre[i] ^= pre[i - 1];
    }
    for(int i = 0; i < maxN; i++) que[i] = i;
    bool r1 = Query(maxN, que), r2 = Query(maxN, que), r3 = getPre(0, maxN - 1);
    if((r1 == r2 && r1 == r3) || (r1 != r2)){ //output
        for(int i = 0; i < maxN; i++){
            cout << res[i] << " \n"[i == maxN - 1];
        }
        return 0;
    }
    int l = 0, r = maxN, m = (l + r) / 2;
    while(l + 1 < r){
        for(int i = l; i < m; i++) que[i - l] = i;
        r1 = Query(m - l, que);
        if(r1 == getPre(l, m - 1)) l = m;
        else r = m;
        m = (l + r) / 2;
    }
    res[l] ^= 1;
    for(int i = 0; i < maxN; i++){
        cout << res[i] << " \n"[i == maxN - 1];
    }
    return 0;
}
