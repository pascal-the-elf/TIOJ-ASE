#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2262500, INF = 1e17;

int N, arr[maxN], pre[maxN], suf[maxN];

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        pre[i] = suf[i] = -INF;
    }
    pre[0] = suf[N + 1] = -INF;
    int csum = 0, maxSum = -INF;
    for(int i = 1; i <= N; i++){
        pre[i] = max({pre[i - 1] + arr[i], arr[i], pre[i - 1]});
        suf[N - i + 1] = max({suf[N - i + 2] + arr[N - i + 1], arr[N - i + 1], suf[N - i + 2]});
    }
    /*
    cout << "pre: " << endl;
    for(int i = 1; i <= N; i++) cout << pre[i] << " "; cout << endl;
    cout << "suf: " << endl;
    for(int i = 1; i <= N; i++) cout << suf[i] << " "; cout << endl;
    */
    int ans = -INF;
    for(int i = 2; i < N; i++){
        ans = max(ans, pre[i - 1] + suf[i + 1]);
    }
    cout << ans << '\n';

}



