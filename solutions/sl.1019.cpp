#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int T, N, DP[1005], vals[1005];

inline int diff(int a, int b){
    return (a >= b ? a - b : b - a);
}

signed main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> vals[i];
            if(!i) DP[i] = 0;
            else if(i == 1) DP[i] = diff(vals[1], vals[0]);
            else DP[i] = min(DP[i - 1] + diff(vals[i], vals[i - 1]), DP[i - 2] + diff(vals[i], vals[i - 2]));
            //cout << "DP[" << i << "] = " << DP[i] << endl;
        }
        cout << DP[N - 1] << endl;
    }
}
