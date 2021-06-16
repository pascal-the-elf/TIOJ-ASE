#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxW = 1e6 + 10, maxN = 1e5;

int n, W, w, m, c, dp[maxW];

void run(int w, int v){
    for(int i = maxW - 1; i >= w; i--){
        dp[i] = max(dp[i], dp[i - w] + v);
    }
}

int main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w >> m >> c;
        for(int j = 0; (1LL << j) <= c; j++){
            run(w * (1LL << j), m * (1LL << j));
            c -= (1LL << j);
        }
        if(c){
            run(w * c, m * c);
        }
    }
    cin >> W;
    cout << dp[W] << endl;
}

