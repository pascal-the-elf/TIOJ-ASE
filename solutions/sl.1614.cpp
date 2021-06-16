#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 10;

int N, M, que[maxN], roots[maxN], ans;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> que[i];
    for(int i = 0; i < M; i++) cin >> roots[i];
    sort(roots, roots + M);
    for(int i = 0; i < N; i++){
        auto it = lower_bound(roots, roots + M, que[i]);
        //cout << "Ind: " << it - roots << endl;
        if(*it == que[i]) continue;
        ans += ((M - (it - roots)) % 2 == 0);
    }
    cout << ans << '\n';
}
