#include <iostream>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 226, INF = 1e17;

inline int Abs(int x){
    return x < 0 ? -x : x;
}

int N, M, a[maxN], b[maxN], lastA, lastB, ans, ap, bp;

signed main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];
    sort(a, a + N);
    sort(b, b + M);
    a[N] = b[M] = ans = lastA = lastB = INF;
    ap = bp = 0;
    while(ap < N || bp < M){
        if(bp == M || a[ap] <= b[bp]){
            //cout << "Putting a: " << a[ap] << endl;
            if(lastB != INF) ans = min(ans, Abs(lastB - a[ap]));
            lastA = a[ap++];
        } else {
            //cout << "Putting b: " << b[bp] << endl;
            if(lastA != INF) ans = min(ans, Abs(lastA - b[bp]));
            lastB = b[bp++];
        }
    }
    cout << ans << endl;
}
