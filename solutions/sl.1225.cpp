#include <iostream>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10, INF = 2e9;

int N, arr[maxN], nxt[maxN], prv[maxN], perm[maxN], cost;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        nxt[i] = i + 1;
        prv[i] = i - 1;
        perm[i] = i;
    }
    arr[0] = arr[N + 1] = INF;
    sort(perm + 1, perm + N + 1, [=](int i, int j){
        return arr[i] < arr[j];
    });
    for(int i = 1; i <= N - 1; i++){
        cost += min(arr[prv[perm[i]]], arr[nxt[perm[i]]]);
        nxt[prv[perm[i]]] = nxt[perm[i]];
        prv[nxt[perm[i]]] = prv[perm[i]];
    }
    cout << cost << endl;
}
