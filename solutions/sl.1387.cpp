#include <iostream>
using namespace std;

const int maxW = 1e4 + 10, maxN = 100;

int n, W,  w[maxN], m[maxN], c[maxN], dp[maxW];

void run(int w, int v){
    for(int i = maxW - 1; i >= w; i--){
        dp[i] = max(dp[i], dp[i - w] + v);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> m[i] >> c[i];
        for(int j = 0; (1LL << j) <= c[i]; j++){
            run(w[i] * (1LL << j), m[i] * (1LL << j));
            c[i] -= (1LL << j);
        }
        if(c[i]){
            run(w[i] * c[i], m[i] * c[i]);
        }
    }
    cin >> W;
    cout << dp[W] << endl;
}
