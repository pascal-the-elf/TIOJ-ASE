#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 20;

int vals[20] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000, 1000000000, 5000000000};
int has[maxN], N, sum;
int f(int i, int j){ //1~j using first i
    if(!j) return 0;
    if(!i) return min(has[0], j);
    int take = min(has[i], j / vals[i]), r = 0;
    //cout << "take = " << take << endl;
    return (take * (f(i - 1, vals[i] - 1) + 1) % MOD + f(i - 1, j - take * vals[i]) ) % MOD;
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> has[i];
        sum += has[i] * vals[i];
    }
    cout << f(18, sum) << '\n';
}
