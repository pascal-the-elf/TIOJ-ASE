#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int maxN = 15;

int fact[maxN], N, M, ans[maxN], kth, c;
bool used[maxN];

inline void solve(int N, int M){
    M = (M - 1) % fact[N];
    fill(used, used + N, false);
    for(int i = 0; i < N; i++){
        kth = M / fact[N - i - 1];
        //cout << i << "th char is " << kth << " unused " << endl;
        c = 0;
        for(int j = 0; j < N; j++){
            if(!used[j]){
                if(c == kth){
                    used[j] = true;
                    ans[i] = j;
                    break;
                }
                c++;
            }
        }
        M %= fact[N - i - 1];
    }
    for(int i = 0; i < N; i++) cout << (char)(ans[i] + 'A') << " ";
    cout << endl;
}

signed main(){
    fact[0] = 1;
    for(int i = 1; i < maxN; i++) fact[i] = fact[i - 1] * i;
    while(cin >> N >> M){
        if(!N) return 0;
        solve(N, M);
    }

}
