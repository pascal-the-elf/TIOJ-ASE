#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
/*
This will SF on my local computer but gets verdict of AC on TIOJ
*/
const int maxN = 1e7 + 1, blockSize = 500, sieveMax = 1e4; //sqrt(sqrt(N) * log(N)) = 271 where N = 1e7

bool isPrime[sieveMax];
int l, r, divs[maxN + 10];

struct ZCK{
    pii seg[2 * maxN + 20];
    ZCK(){}
    ZCK(int arr[]){
        for(int i = 0; i < maxN; i++){
            seg[i + maxN] = {arr[i], i};
        }
        for(int i = maxN - 1; i; i--){
            seg[i] = max(seg[i << 1], seg[(i << 1) | 1]);
        }
    }
    pii query(int l, int r){
        pii res = {-1, -1};
        for(l += maxN, r += maxN; l != r; l >>= 1, r >>= 1){
            if(l & 1) res = max(res, seg[l++]);
            if(r & 1) res = max(res, seg[--r]);
        }
        return res;
    }
};

inline void initDivs(){
    fill(divs, divs + maxN + 5, 2);
    divs[1] = 1;
    for(int i = 2; i < maxN; i++){
        for(int j = 2 * i; j < maxN; j += i) divs[j]++;
    }
}

signed main(){
    ericxiao;
    initDivs();
    ZCK rmq = ZCK(divs);
    while(cin >> l >> r){
        if(l > r) swap(l, r);
        if(l == 0 || r == 0){
            cout << 0 << '\n';
            continue;
        }
        pii ans = rmq.query(l, r + 1);
        cout << ans.S << '\n';
    }
}
