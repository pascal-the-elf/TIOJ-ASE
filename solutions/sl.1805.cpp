#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 22625, INF = 2e9;

int vals[maxN], N, l, r, T;

bool can(int k){
    int u = INF, d = -INF;
    for(int i = 0; i < N; i++){
        if(r - vals[i] > k){
            d = max(d, r + vals[i] - k);
        }
        if(vals[i] - l > k){
            u = min(u, l + vals[i] + k);
        }
    }
    return u >= d;
}

int main(){
    ericxiao;
    cin >> T;
    while(T--){
       cin >> N;
        for(int i = 0; i < N; i++) cin >> vals[i];
        sort(vals, vals + N);
        l = vals[0];
        r = vals[N - 1];
        int L = -1, R = r - l + 1, M;
        while(L + 1 < R){
            M = (L + R) / 2;
            if(can(M)) R = M;
            else L = M;
        }
        cout << R << '\n';
    }
}
